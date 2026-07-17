# Aura-Home-An-Integrated-IoT-Framework-for-a-Cloud-based-Domestic-Automation-System

AuraHome is an IoT-based smart home automation system that enables real-time control of household lighting using the Arduino IoT Cloud. The project integrates the LPC2129 (ARM7) microcontroller with an ESP8266 NodeMCU through UART communication, allowing users to control four lighting devices remotely while displaying their status on a 20×4 LCD.

 📌 Features

- ☁️ Cloud-based device control using Arduino IoT Cloud
- 📶 ESP8266 NodeMCU for Wi-Fi connectivity
- 🖥️ LPC2129 ARM7 microcontroller as the main controller
- 🔄 UART communication between ESP8266 and LPC2129
- 💡 Control of four independent lighting devices
- 📟 20×4 LCD for real-time device status
- ✨ Custom CGRAM glowing bulb animation
- 🔁 Scrolling project title on LCD
- ⚡ MQTT-based cloud communication
- 🧪 Proteus simulation support

🛠️ Hardware Requirements

- LPC2129 ARM7 Development Board
- ESP8266 NodeMCU
- 20×4 LCD (HD44780 Compatible)
- 4 LEDs / Relays
- 330Ω Resistors
- USB Cable
- Power Supply

 💻 Software Requirements

- Keil µVision
- Arduino IDE
- Arduino IoT Cloud
- Proteus Professional
- Embedded C

📂 Project Structure

AuraHome/
│── LPC2148/
│   ├──  smart main.c
│   |   lcd.c
│   |   uart.c
│   |   delay.c
│   └── finalheader.h
│
│── ESP8266/
│   ├── AuraHome.ino
│   └── thingProperties.h
│
│── Proteus/
│   ├── AuraHome.pdsprj
│   └── Circuit.dsn
│
└── README.md

 ⚙️ Working Principle

1. User toggles a switch from the Arduino IoT Cloud dashboard.
2. ESP8266 receives the MQTT message.
3. ESP8266 sends a UART command to the LPC2129.
4. LPC2129 processes the command and controls the selected light.
5. The LCD updates the ON/OFF status and displays the bulb animation.

 🔤 UART Commands

| Device | ON | OFF |
|--------|----|-----|
| Bulb 1 | A  | a   |
| Bulb 2 | B  | b   |
| Bulb 3 | C  | c   |
| Bulb 4 | D  | d   |

 🚀 Technologies Used

- Embedded C
- LPC2129 (ARM7)
- ESP8266 NodeMCU
- Arduino IoT Cloud
- MQTT
- UART Communication
- Proteus
- Keil µVision

## 📸 Project Preview

- Arduino IoT Cloud Dashboard
- Hardware Simulation
- 20×4 LCD Display
- LPC2129 Controller
- ESP8266 NodeMCU

 🔮 Future Enhancements

- Voice control using Google Assistant or Alexa
- Mobile app notifications
- Energy consumption monitoring
- Motion and temperature sensors
- Smart scheduling and automation
- Relay-based AC appliance control

 👨‍💻 Author

**S.K.Santhosh**
