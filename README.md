# ⚡ IoT Smart Grid Monitoring and Fault Detection System

<p align="center">
  <img src="https://img.shields.io/badge/ESP32-IoT-blue?style=for-the-badge">
  <img src="https://img.shields.io/badge/Blynk-Cloud-green?style=for-the-badge">
  <img src="https://img.shields.io/badge/Embedded-C++-orange?style=for-the-badge">
  <img src="https://img.shields.io/badge/Status-Completed-success?style=for-the-badge">
</p>

## 📌 Overview

The **IoT Smart Grid Monitoring and Fault Detection System** is an intelligent power monitoring solution designed to continuously monitor electrical parameters and detect abnormal conditions in real time.

The system uses an **ESP32 microcontroller** to collect voltage, current, frequency, temperature, and light intensity data. It automatically identifies faults such as overvoltage, undervoltage, overload, high temperature, and emergency conditions, then activates protection mechanisms including relays, buzzers, and visual indicators.

Data is displayed simultaneously on:

* 🌐 Web Dashboard
* 📱 Blynk IoT Dashboard
* 🖥 OLED Display
* 📟 Serial Monitor

---

## 🚀 Features

### Real-Time Monitoring

* Voltage Monitoring
* Current Monitoring
* Frequency Monitoring
* Temperature Monitoring
* Light Intensity Monitoring

### Fault Detection

* Overvoltage Detection
* Undervoltage Detection
* Overload Detection
* Frequency Fault Detection
* High Temperature Detection
* Emergency Shutdown Detection

### Protection System

* Automatic Relay Control
* Fault Isolation
* Audible Alarm System
* Visual Fault Indicators

### IoT Capabilities

* WiFi Connectivity
* Blynk Cloud Integration
* Web-Based Dashboard
* Remote Monitoring

---

## 🏗 System Architecture

```text
Sensors
   │
   ▼
ESP32 Controller
   │
   ├── OLED Display
   ├── Relay Protection
   ├── Buzzer Alarm
   ├── LEDs
   │
   ▼
WiFi Network
   │
   ├── Blynk Dashboard
   ├── Web Dashboard
   └── Serial Monitoring
```

## 🔌 Hardware Components

| Component       | Purpose                |
| --------------- | ---------------------- |
| ESP32 DevKit V1 | Main Controller        |
| DHT22           | Temperature Monitoring |
| OLED SSD1306    | Local Display          |
| Relay Module    | Load Protection        |
| Buzzer          | Alarm System           |
| Photodiode      | Light Detection        |
| Push Button     | Emergency Trigger      |
| LEDs            | Status Indicators      |
| Potentiometers  | Sensor Simulation      |

---

## 📊 Parameters Monitored

| Parameter       | Range       |
| --------------- | ----------- |
| Voltage         | 180V - 260V |
| Current         | 0A - 20A    |
| Frequency       | 45Hz - 55Hz |
| Temperature     | 0°C - 100°C |
| Light Intensity | 0 - 4095    |

---

## ⚠ Fault Conditions

| Fault Type       | Trigger Condition   |
| ---------------- | ------------------- |
| Overvoltage      | Voltage > 245V      |
| Undervoltage     | Voltage < 200V      |
| Overload         | Current > 15A       |
| Frequency Fault  | Frequency > 51Hz    |
| High Temperature | Temperature > 45°C  |
| Emergency        | Push Button Pressed |

---

## 🛡 Protection Logic

When a fault is detected:

✅ Relay Disconnects Load

✅ Buzzer Activates

✅ Red LED Turns ON

✅ Green LED Turns OFF

✅ Dashboard Updates

✅ Status Logged to Serial Monitor

---

## 📱 Dashboard Features

### Blynk Dashboard

* Live Voltage Gauge
* Current Gauge
* Frequency Gauge
* Temperature Gauge
* Status Display
* Real-Time Updates

### Web Dashboard

* Modern Responsive Interface
* Live Monitoring
* Auto Refresh
* Fault Status Visualization

---

## 🖥 OLED Display

Displays:

```text
Voltage
Current
Frequency
Temperature
Light Intensity
System Status
```

---

## 📂 Project Structure

```text
IoT-Smart-Grid-Monitoring-System/
│
├── src/
│   └── main.ino
│
├── images/
│   ├── dashboard.png
│   ├── hardware.png
│   └── architecture.png
│
├── docs/
│   └── project_report.pdf
│
├── README.md
└── LICENSE
```

---

## 🛠 Technologies Used

* ESP32
* Embedded C++
* WiFi
* Blynk IoT
* Web Server
* OLED Graphics
* IoT Monitoring
* Fault Detection Systems

---

## 🎯 Applications

* Smart Grid Monitoring
* Industrial Automation
* Power Distribution Systems
* Energy Management
* Smart Infrastructure
* Electrical Safety Systems

---

## 📈 Future Enhancements

* AI-Based Fault Prediction
* Power Consumption Analytics
* Cloud Database Integration
* Mobile Notifications
* Predictive Maintenance
* Energy Forecasting

---

## 👨‍💻 Author

### Sumit Kumar

Electrical & Electronics Engineering (EEE)

Embedded Systems | IoT | AI & Robotics

📍 Bihar, India

---

## ⭐ If you found this project useful

Give this repository a star and support future IoT innovations.
