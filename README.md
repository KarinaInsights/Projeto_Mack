# Projeto_Mack

# **🌡️ Sistema de Monitoramento de Temperatura e Umidade em Fábricas**

🔧 Este projeto implementa um sistema de **IoT** para monitoramento ambiental em fábricas e ambientes industriais. Ele mede **temperatura** e **umidade** em tempo real, utilizando a placa **ESP8266**, o sensor **DHT11**, e um buzzer para alertas locais. Os dados são enviados para a plataforma **Adafruit IO** por meio do protocolo **MQTT**, permitindo visualização remota e controle inteligente.

---

## **📂 Código e Documentação**

📜 O arquivo principal é o [`codigofonte.ino`](src/codigofonte.ino), desenvolvido em **Arduino IDE**, e contém:
- 📡 Configuração da conexão Wi-Fi.
- 📦 Integração com o protocolo MQTT.
- 📊 Funções de leitura do sensor e emissão de alertas via buzzer.

> 🛠️ **Dica:** Antes de rodar o código, edite as credenciais de Wi-Fi e do Adafruit IO no cabeçalho do arquivo.
>
> 📄 **Artigo Completo:** A documentação detalhada deste projeto está disponível no arquivo PDF [`artigo_documentacao.pdf`](artigo_documentacao.pdf). Este artigo inclui todas as etapas do desenvolvimento, diagramas, e análises dos resultados.

---

## **🔌 Hardware Utilizado**

🖥️ **Componentes Principais**:
- 🟢 **ESP8266 NodeMCU CH340:** Controla o sistema e gerencia a comunicação Wi-Fi.
- 🔵 **Sensor DHT11:** Mede a **temperatura** e a **umidade** do ambiente.
- 🔴 **Buzzer Ativo 3V:** Emite alertas sonoros para condições críticas.
- ⚙️ **Protoboard 400 pontos (2x):** Facilita a montagem do circuito.
- 🔌 **Fios Jumper:** Conectam os componentes de forma prática e segura.
- 🔗 **Cabo Micro USB:** Alimenta a placa e permite programação.

> 💡 **Nota:** O esquema do circuito está disponível no arquivo [`diagrama_circuito.fzz`](diagrama_circuito.fzz) em imgs.

---

## **🌐 Interfaces e Protocolos de Comunicação**

💬 Este projeto utiliza o **protocolo MQTT** para envio e recebimento de dados entre o **ESP8266** e o **Adafruit IO**.

🔗 **Feeds MQTT Configurados**:
- 🌡️ `/feeds/temperatura`: Envia os valores de temperatura.
- 💧 `/feeds/umidade`: Envia os valores de umidade.
- 🚨 `/feeds/TemperatureAlarm`: Publica alertas de temperatura crítica.

👨‍💻 **Plataforma Adafruit IO**:
- 📊 Visualização gráfica em tempo real.
- 📈 Histórico de dados para análise de tendências.
- 🔔 Notificações visuais para condições críticas.

---

## **⚙️ Como Reproduzir o Projeto**

### **1️⃣ Baixe o Repositório**
Faça o download ou clone este repositório:
```bash
git clone https://github.com/KarinaInsights/Projeto_Mack.git
```

### **2️⃣ Configure o Código**
- Abra o arquivo `codigofonte.ino` em **Arduino IDE**.
- Insira as suas credenciais:
  ```cpp
  #define WIFI_SSID "SuaRedeWiFi"
  #define WIFI_PASSWORD "SuaSenha"
  #define AIO_USERNAME "SeuUsuarioAdafruit"
  #define AIO_KEY "SuaChaveAdafruit"
  ```

### **3️⃣ Monte o Circuito**
Siga o esquema no arquivo [`diagrama_circuito.fzz`](diagrama_circuito.fzz) pasta `imgs`.

### **4️⃣ Faça o Upload do Código**
Conecte o ESP8266 ao computador via cabo USB e envie o código pela Arduino IDE.

### **5️⃣ Monitore e Controle**
Acesse o **Adafruit IO** para visualizar os dados e receber alertas em tempo real.

---

## **📈 Componentes**

| Componente        | Descrição                      |
|--------------------|--------------------------------|
| ESP8266 NodeMCU    | Gerencia comunicação e controle |
| DHT11             | Mede temperatura e umidade     |
| Buzzer Ativo       | Emite alertas sonoros          |
| Protoboard         | Facilita conexões              |

> 📸 **Imagens do Protótipo:** Veja as fotos na pasta `imgs/`.

---

## **💡 Links úteis**

- 🌐 [Adafruit IO](https://www.adafruit.com/)
- 📄 [Arduino IDE](https://docs.arduino.cc/software/ide/)
- 🛠️ [Fritzing](https://fritzing.org/)
- 📘 [MQTT Protocolo](https://aws.amazon.com/pt/what-is/mqtt/)
- 🎥 [YouTube - Projetos IoT](https://www.youtube.com/watch?v=01j5eJVQ6os&list=PLqseg0xtT4cFM_cj9qFOchPr6M3wZNHdB)

---
