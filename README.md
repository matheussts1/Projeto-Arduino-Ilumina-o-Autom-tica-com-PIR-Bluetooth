# Projeto-Arduino-Ilumina-o-Autom-tica-com-PIR-Bluetooth
Este projeto utiliza Arduino, sensor PIR, módulo Bluetooth (HC-05/HC-06) e uma fita de LED controlada por transistor. O sistema permite ligar e desligar a iluminação via Bluetooth e também aciona automaticamente quando detecta movimento.


## 🛠 Componentes Utilizados
- Arduino UNO  
- Sensor PIR HC-SR501  
- Módulo Bluetooth HC-05 / HC-06  
- Transistor (TIP122 / 2N2222 / MOSFET logic level)  
- Resistor 220Ω  
- Fita LED 5V  
- Fonte 5V  
- Jumpers  

---

## 🔌 Ligações (Pinout)

| Componente          | Pino Arduino |
|---------------------|--------------|
| Sensor PIR          | D2           |
| Transistor (Gate)   | D9 (PWM)     |
| Bluetooth RX        | D10          |
| Bluetooth TX        | D11          |
| Fonte / LEDs        | 5V e GND     |

---

## 📲 Comandos Bluetooth

| Comando | Função |
|--------|--------|
| **1** | Liga o sistema |
| **0** | Desliga o sistema |

---

## 💡 Funcionamento
- O sistema pode ser ativado ou desativado pelo celular (Bluetooth).  
- Quando ligado, o PIR detecta movimento.  
- Ao detectar, a fita LED acende com brilho máximo.  
- Após **1 segundo sem movimento**, a luz é desligada automaticamente.

---

## 🧾 Código (arquivo em: `/src/sistema_pir_bluetooth.ino`)

```cpp
#include <SoftwareSerial.h>

// ============================
// PINOS
// ============================
#define SENSOR_PIR 2         // entrada do PIR
#define TRANSISTOR_PIN 9     // pino PWM → resistor 220Ω → Gate/Base

SoftwareSerial BT(10, 11);   // RX = 10, TX = 11 (Bluetooth HC-05/HC-06)

unsigned long ultimoMovimento = 0;
bool sistemaLigado = false;  // começa desligado
 Serial.begin(9600);
  BT.begin(9600);

  BT.println("Bluetooth conectado!");
  BT.println("Envie 1 para ligar o sistema.");
  BT.println("Envie 0 para desligar.");
}
