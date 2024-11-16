# Projeto_Mack
Sistema de Monitoramento de Temperatura e Umidade em Fábricas
Este projeto implementa um sistema de IoT para monitoramento ambiental, especificamente de temperatura e umidade, em ambientes industriais. Utiliza a placa ESP8266 NodeMCU, um sensor DHT11 e um buzzer para alertas sonoros. A comunicação é realizada via MQTT com integração à plataforma Adafruit IO, permitindo monitoramento remoto e armazenamento de dados.

Código e Documentação
O código principal do sistema está localizado no arquivo codigofonte.ino e foi desenvolvido utilizando a Arduino IDE. Ele inclui:

Configuração da conexão Wi-Fi.
Integração com o protocolo MQTT.
Funções para leitura de dados do sensor DHT11.
Controle do buzzer para alertas locais.
Para executar o projeto, configure as credenciais de Wi-Fi e do Adafruit IO no código. As instruções completas estão disponíveis no arquivo principal.

Hardware
ESP8266 NodeMCU CH340: Responsável pela conectividade Wi-Fi e controle do sistema.
Sensor DHT11: Realiza medições de temperatura e umidade.
Buzzer Ativo 3V: Emite alertas sonoros quando a temperatura excede os limites configurados.
Protoboard 400 pontos (2x): Facilita a montagem do circuito sem solda.
Fios Jumper: Conectam os componentes de forma prática e segura.
Cabo Micro USB: Fornece alimentação e permite a programação da ESP8266.
Interfaces e Protocolos de Comunicação
O sistema utiliza o protocolo MQTT para comunicação com o Adafruit IO. São configurados os seguintes feeds MQTT:

Feed de Temperatura: Envia os valores de temperatura em intervalos de 5 segundos.
Feed de Umidade: Envia os valores de umidade nas mesmas condições.
Feed de Alerta de Temperatura: Publica uma mensagem de alerta quando a temperatura excede 27°C.
A interface no Adafruit IO permite:

Visualização gráfica em tempo real dos dados de temperatura e umidade.
Histórico de leituras ambientais.
Notificação visual e sonora de alertas.
Protocolo MQTT e Comunicação TCP/IP
O sistema opera sobre a rede Wi-Fi (protocolo TCP/IP) e utiliza o protocolo MQTT para comunicação eficiente entre o ESP8266 e o Adafruit IO. Configurações necessárias:

Credenciais do Wi-Fi: Configure o wifi_ssid e wifi_password no código para conectar à sua rede.
Credenciais do Adafruit IO: Insira seu AIO_USERNAME e AIO_KEY para autenticação no broker MQTT.
Feeds MQTT: Configure os feeds de temperatura, umidade e alertas diretamente na interface do Adafruit IO.
Como Reproduzir o Projeto
Baixe o Repositório:
Faça o download ou clone este repositório.

Configure o Código:
Abra o arquivo codigofonte.ino na Arduino IDE e edite as credenciais de Wi-Fi e do Adafruit IO.

Monte o Circuito:
Siga o esquema fornecido no arquivo diagrama_circuito.fzz ou na pasta imagens/.

Carregue o Código:
Conecte o ESP8266 ao computador via cabo USB e faça o upload do código.

Monitore e Controle:
Acesse o Adafruit IO para monitorar os dados e receber alertas em tempo real.

Contribuições
Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou enviar pull requests com sugestões de melhorias ou novas funcionalidades.
