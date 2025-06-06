# Medidor de umidade do solo – FloodSafe

**Integrantes**

|João Pedro Raimundo Marcilio | RM: 561603 |       
|Lucas Zanella Clemente | RM: 563880 |       
|João Pedro Ribeiro Palermo | RM: 562077 |       

Este projeto foi desenvolvido pelo grupo FloodSafe, com a ideia de criar uma solução para prevenção ou alerta de possíveis enchentes ou deslizamentos, com o objetivo de proteger a qualidade de vida das pessoas da região afetada ou até mesmo causar impactos econômicos, ambientais e etc.

Pensando nisso, este dispositivo realiza um monitoramento ambiental completo, em tempo real, medindo a umidade do solo, e disparando alertar quando passam de uma certa medida de limite.

Link vídeo: https://youtu.be/jW36lihm5H4      
Link Wokwi: https://wokwi.com/projects/433045673630087169

## 🎯 Objetivo

Alertar todas as pessoas de uma situação com risco de enchente ou deslizamento em tempo real.

---

## 🛠 Tecnologias e Componentes

- Arduino
- LCD 16x2 (I2C) -> telinha que mostra as coisas
- Analog Joystick -> o controle lá vermelho
- Buzzer -> a roda preta, toca som
- Sensor de umidade -> na verdade é um "potentiometer", pq não tem um sensor de umidade no wokwi, então pegamos esse para simular dados falsos da umidade do solo
---

## 📦 Funcionalidades


### Monitoramento de Umidade (💧)
Verifica constantemente a umidade relativa do solo. Se a umidade estiver muito alta ou muito baixa, o sistema alerta da mesma forma que a temperatura, com aviso no visor e som de alarme.


### Alerta Sonoro (🔊 Buzzer)
Quando qualquer um dos três parâmetros (temperatura, umidade ou luminosidade) estiver fora dos limites definidos, o aparelho emite um som de alerta automático, indicando que alguma ação deve ser tomada para proteger os vinhos.

### Navegação por Joystick (🕹️)
O sistema possui um controle por joystick analógico, facilitando a navegação entre os menus do visor LCD. Com movimentos simples (cima, baixo, esquerda, direita e botão central), o usuário pode consultar dados em tempo real ou acessar registros antigos.



## 📋 Navegação no Menu

Utiliza joystick analógico em um único pino para:

- `▲`, `◀`, `▶`, `●` = controle intuitivo

---

## 🔔 Alertas

- ⚠️ **Buzzer** é acionado quando o valor limite de risco é ultrapassado, podendo ter tanto uma enchente ou um deslizamento no local.
- 💡 O LCD também pisca ícones para indicar o tipo de alerta visualmente.

---

## 🚀 Como Usar

1. Carregue o código no Arduino
2. Ligue o sistema
3. Use o joystick para navegar pelas opções, clique com o joystick para confirmar
4. Navegue pelas estados e selecione qual o dispositivo está presente
5. O sistema monitora a umidade do solo e avisa em tempo real uma porcentagem
6. Quando a porcentagem ultrapassar o limite imposto, o buzzer tocará e aparecerá na tela uma mensagem de perigo
7. Caso queira mudar o estado, só é necessário navegar para as configuarções e selecionar o estado que desejareal

---
 ## Circuito


📍 Projeto desenvolvido para combater enchentes
