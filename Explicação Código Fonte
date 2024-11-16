# Documentação do Código

## **Visão Geral**
Este código foi desenvolvido em **C**, utilizando a **Arduino IDE**, para implementar as funcionalidades principais de monitoramento de temperatura e umidade, controle de alertas e comunicação via protocolo MQTT. Abaixo, descrevemos os detalhes do funcionamento e das funções implementadas.

---

## **Estrutura do Código**
O código está dividido em três seções principais:

### **1. Configurações Iniciais (`setup`)**
Esta seção prepara o sistema para operar:
- Configuração do sensor DHT11 para leitura de temperatura e umidade.
- Estabelece conexão à rede Wi-Fi utilizando as credenciais fornecidas no código.
- Configuração do broker MQTT (Adafruit IO) para publicar e monitorar dados.
- Inicializa o buzzer no estado desligado.

### **2. Loop Principal (`loop`)**
Executa continuamente as seguintes tarefas:
- Realiza leituras regulares do sensor DHT11.
- Publica os valores de temperatura e umidade nos feeds MQTT configurados.
- Verifica se a temperatura ultrapassa o limite de 27°C:
  - Caso positivo, aciona o buzzer e publica um alerta no feed de temperatura.
  - Caso contrário, desliga o buzzer e publica que a temperatura está normal.

### **3. Funções Auxiliares**
- **Reconexão Automática:** Reconecta o dispositivo ao Wi-Fi e ao broker MQTT em caso de desconexão.
- **Cálculo de Médias:** Garante maior precisão processando múltiplas leituras do sensor para reduzir ruídos.

---

## **Como Configurar a Temperatura Limite**
O sistema foi projetado para emitir alertas quando a temperatura ultrapassar o limite de **27°C**, mas esse valor pode ser ajustado facilmente no código-fonte. 

### **Passo a Passo para Alterar o Limite de Temperatura**
1. **Localize a variável no código:**
   No início do arquivo [codigofonte.ino](https://github.com/KarinaInsights/Projeto_Mack/blob/main/codigofonte.ino), a temperatura limite está configurada na seguinte linha:

   ```cpp
   const int TEMPERATURE_THRESHOLD = 27;  // Limite de temperatura em graus Celsius
   ```

2. **Substitua o valor pelo novo limite desejado:**
   - Por exemplo, para configurar o limite em **30°C**, modifique para:
     ```cpp
     const int TEMPERATURE_THRESHOLD = 30;
     ```

3. **Salve o arquivo e faça o upload para a NodeMCU ESP8266:**
   - Após alterar o valor, salve o código e envie a nova versão para a placa utilizando a **Arduino IDE**.

### **Considerações**
- Certifique-se de que o valor definido esteja dentro do intervalo suportado pelo sensor DHT11 (-40°C a +80°C).
- Teste o sistema após a alteração para verificar se o limite está funcionando corretamente.

---

## **Detalhes do Código**

### **Conexão Wi-Fi**
O código configura a ESP8266 para se conectar automaticamente à rede Wi-Fi, garantindo acesso à internet para o envio de dados ao broker MQTT.

```cpp
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
}
Serial.println("Conectado ao Wi-Fi!");
```

### **Configuração do MQTT**
O protocolo MQTT é utilizado para enviar os dados ambientais para a plataforma Adafruit IO. Os feeds configurados são:
- **Temperatura:** `/feeds/temperatura`
- **Umidade:** `/feeds/umidade`
- **Alerta de Temperatura:** `/feeds/TemperatureAlarm`

```cpp
mqttClient.connect();
feedTemperature = new Adafruit_MQTT_Publish(&mqttClient, AIO_USERNAME "/feeds/temperatura");
feedHumidity = new Adafruit_MQTT_Publish(&mqttClient, AIO_USERNAME "/feeds/umidade");
feedTempAlarm = new Adafruit_MQTT_Publish(&mqttClient, AIO_USERNAME "/feeds/TemperatureAlarm");
```

### **Leitura e Processamento dos Sensores**
Os dados de temperatura e umidade são coletados do DHT11 e armazenados em um buffer para calcular a média das últimas leituras.

```cpp
float temperature = sensorDHT.readTemperature();
float humidity = sensorDHT.readHumidity();

temperatureSamples[sampleIndex] = temperature;
humiditySamples[sampleIndex] = humidity;

sampleIndex = (sampleIndex + 1) % NUM_SAMPLES;
```

### **Controle do Buzzer**
O buzzer é acionado ou desligado com base no valor da temperatura:

```cpp
if (temperature > TEMPERATURE_THRESHOLD) {
  digitalWrite(BUZZER_PIN, HIGH);
  feedTempAlarm->publish("Temperatura Alta!");
} else {
  digitalWrite(BUZZER_PIN, LOW);
  feedTempAlarm->publish("Temperatura Normal.");
}
```

---

## **Código Completo**
O código completo está disponível no repositório e pode ser acessado no arquivo [codigofonte.ino](https://github.com/KarinaInsights/Projeto_Mack/blob/main/codigofonte.ino).

---

## **Links Relacionados**
- [Repositório no GitHub](https://github.com/KarinaInsights/Projeto_Mack/tree/main)
- [Dashboard no Adafruit IO](https://io.adafruit.com/)
- [Código Fonte](https://github.com/KarinaInsights/Projeto_Mack/blob/main/codigofonte.ino)

---
