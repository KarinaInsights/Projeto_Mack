#include <ESP8266WiFi.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>
#include <DHT.h>

#define SENSOR_TYPE DHT11
const uint8_t SENSOR_PIN = D1;  
DHT sensorDHT(SENSOR_PIN, SENSOR_TYPE);  

#define BUZZER_PIN D2


const char* WIFI_SSID = "Neguinha 2G";
const char* WIFI_PASSWORD = "Luan1234@";


const char* AIO_SERVER = "io.adafruit.com";
const uint16_t AIO_PORT = 1883;
const char* AIO_USERNAME = "karina_mendes";
const char* AIO_KEY = "aio_ESya76qgR7S6oro06fmZtfxe6Q6Y";


WiFiClient wifiClient;
Adafruit_MQTT_Client mqttClient(&wifiClient, AIO_SERVER, AIO_PORT, AIO_USERNAME, AIO_KEY);

char feedTemp[64];
char feedHum[64];
char feedAlarm[64];  

Adafruit_MQTT_Publish* feedTemperature;
Adafruit_MQTT_Publish* feedHumidity;
Adafruit_MQTT_Publish* feedTempAlarm;  

unsigned long lastSendTime = 0;
const unsigned long SEND_INTERVAL = 5000;  
const int TEMPERATURE_THRESHOLD = 27;  

bool highTempSent = false;  
bool normalTempSent = false;  

const int NUM_SAMPLES = 5;  
float temperatureSamples[NUM_SAMPLES];
float humiditySamples[NUM_SAMPLES];
int sampleIndex = 0;

void connectWiFi() {
  Serial.print("Connecting to Wi-Fi...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to Wi-Fi!");
}

void connectMQTT() {
  while (mqttClient.connected() == false) {
    Serial.print("Attempting to connect to Adafruit IO... ");
    if (mqttClient.connect()) {
      Serial.println("Connected successfully!");
    } else {
      Serial.print("Connection failed. Error code: ");
      Serial.println(mqttClient.connectErrorString(mqttClient.connect()));
      Serial.println("Retrying in 5 seconds...");
      delay(5000);
    }
  }
}

void initializeFeeds() {
  snprintf(feedTemp, sizeof(feedTemp), "%s/feeds/Temperature", AIO_USERNAME);
  snprintf(feedHum, sizeof(feedHum), "%s/feeds/Humidity", AIO_USERNAME);
  snprintf(feedAlarm, sizeof(feedAlarm), "%s/feeds/TemperatureAlarm", AIO_USERNAME);  

  feedTemperature = new Adafruit_MQTT_Publish(&mqttClient, feedTemp);
  feedHumidity = new Adafruit_MQTT_Publish(&mqttClient, feedHum);
  feedTempAlarm = new Adafruit_MQTT_Publish(&mqttClient, feedAlarm);  
}

void controlBuzzer(int intensity) {
  
  analogWrite(BUZZER_PIN, intensity);  
}

void readAndStoreSamples() {
  float humidity = sensorDHT.readHumidity();
  float temperature = sensorDHT.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  
  temperatureSamples[sampleIndex] = temperature;
  humiditySamples[sampleIndex] = humidity;

  
  sampleIndex = (sampleIndex + 1) % NUM_SAMPLES;
}

float calculateAverage(float samples[], int numSamples) {
  float sum = 0;
  for (int i = 0; i < numSamples; i++) {
    sum += samples[i];
  }
  return sum / numSamples;
}

void readAndSendData() {
  readAndStoreSamples();  

  
  float averageTemperature = calculateAverage(temperatureSamples, NUM_SAMPLES);
  float averageHumidity = calculateAverage(humiditySamples, NUM_SAMPLES);

  int tempInt = static_cast<int>(round(averageTemperature));
  int humInt = static_cast<int>(round(averageHumidity));

  
  if (!feedTemperature->publish(tempInt)) {
    Serial.println("Failed to send temperature to Adafruit IO.");
  }
  if (!feedHumidity->publish(humInt)) {
    Serial.println("Failed to send humidity to Adafruit IO.");
  }

  Serial.print("Average Temperature: ");
  Serial.print(tempInt);
  Serial.print(" °C    Average Humidity: ");
  Serial.print(humInt);
  Serial.println(" %");

  
  if (tempInt > TEMPERATURE_THRESHOLD && !highTempSent) {
    
    controlBuzzer(128);  
    if (!feedTempAlarm->publish("Alerta! Temperatura Alta!")) {
      Serial.println("Failed to send temperature alarm to Adafruit IO.");
    } else {
      Serial.println("Alerta de temperatura enviado ao Adafruit IO.");
      highTempSent = true;  
      normalTempSent = false;  
    }
  } else if (tempInt <= TEMPERATURE_THRESHOLD && !normalTempSent) {
    
    controlBuzzer(0);  
    if (!feedTempAlarm->publish("Temperatura normal")) {
      Serial.println("Failed to send normal temperature status to Adafruit IO.");
    } else {
      Serial.println("Temperatura normal enviada ao Adafruit IO.");
      normalTempSent = true;  
      highTempSent = false;  
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(BUZZER_PIN, OUTPUT);  
  controlBuzzer(0);  
  connectWiFi();
  sensorDHT.begin();
  connectMQTT();
  initializeFeeds();

 
  for (int i = 0; i < NUM_SAMPLES; i++) {
    temperatureSamples[i] = sensorDHT.readTemperature();
    humiditySamples[i] = sensorDHT.readHumidity();
  }
}

void loop() {
  if (!mqttClient.connected()) {
    connectMQTT();
  }

  mqttClient.ping();

  if (millis() - lastSendTime >= SEND_INTERVAL) {
    lastSendTime = millis();
    readAndSendData();
  }
}
