# ⚡ IoT Smart Grid Monitoring and Fault Detection System

<p align="center">
  <img src="images/project_view_1.png" width="1000">
</p>

<p align="center">
  <img src="https://img.shields.io/badge/ESP32-IoT-blue?style=for-the-badge">
  <img src="https://img.shields.io/badge/Blynk-Cloud-green?style=for-the-badge">
  <img src="https://img.shields.io/badge/Embedded-C++-orange?style=for-the-badge">
  <img src="https://img.shields.io/badge/Status-Completed-success?style=for-the-badge">
  <img src="https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge">
</p>

<p align="center">
  <b>Real-Time Smart Grid Monitoring, Fault Detection, and Protection System using ESP32, Blynk IoT, OLED Display, and Web Dashboard</b>
</p>

---

# 📌 Overview

The **IoT Smart Grid Monitoring and Fault Detection System** is an intelligent power monitoring solution designed to continuously monitor critical electrical parameters and automatically detect abnormal operating conditions in real time.

The system utilizes an **ESP32 microcontroller** to acquire sensor data, analyze grid conditions, trigger protection mechanisms, and provide cloud-based monitoring through **Blynk IoT**, a **Web Dashboard**, **OLED Display**, and **Serial Monitor**.

This project demonstrates concepts from:

* Smart Grids
* Embedded Systems
* Industrial Automation
* Power System Protection
* Internet of Things (IoT)

---

# 📸 Project Gallery

## Complete System

<p align="center">
  <img src="images/project_view_1.png" width="850">
</p>

## Hardware Setup

<p align="center">
  <img src="images/hardware_setup.png" width="850">
</p>

## Dashboard Screens

<p align="center">
  <img src="images/dashboard_1.png" width="850">
</p>

<p align="center">
  <img src="images/dashboard_2.png" width="850">
</p>

<p align="center">
  <img src="images/dashboard_3.png" width="850">
</p>

<p align="center">
  <img src="images/dashboard_4.png" width="850">
</p>

<p align="center">
  <img src="images/dashboard_5.png" width="850">
</p>

---

# 🚀 Features

## Real-Time Monitoring

* Voltage Monitoring
* Current Monitoring
* Frequency Monitoring
* Temperature Monitoring
* Light Intensity Monitoring

## Intelligent Fault Detection

* Overvoltage Detection
* Undervoltage Detection
* Overload Detection
* Frequency Fault Detection
* High Temperature Detection
* Emergency Shutdown Detection

## Protection System

* Automatic Relay Control
* Fault Isolation
* Audible Alarm System
* Visual Fault Indicators

## IoT Connectivity

* WiFi Connectivity
* Blynk Cloud Dashboard
* Web Dashboard
* Remote Monitoring
* Live Data Streaming

---

# 🏗 System Architecture

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
   ├── Blynk Cloud Dashboard
   ├── Web Dashboard
   └── Serial Monitoring
```

---

# 🔌 Hardware Components

| Component       | Function               |
| --------------- | ---------------------- |
| ESP32 DevKit V1 | Main Controller        |
| DHT22 Sensor    | Temperature Monitoring |
| OLED SSD1306    | Local Display          |
| Relay Module    | Load Protection        |
| Buzzer          | Fault Alarm            |
| Photodiode      | Light Monitoring       |
| Push Button     | Emergency Trigger      |
| LEDs            | Status Indication      |
| Potentiometers  | Sensor Simulation      |

---

# 📊 Parameters Monitored

| Parameter       | Range       |
| --------------- | ----------- |
| Voltage         | 180V - 260V |
| Current         | 0A - 20A    |
| Frequency       | 45Hz - 55Hz |
| Temperature     | 0°C - 100°C |
| Light Intensity | 0 - 4095    |

---

# ⚠ Fault Detection Logic

| Fault Condition  | Trigger             |
| ---------------- | ------------------- |
| Overvoltage      | Voltage > 245V      |
| Undervoltage     | Voltage < 200V      |
| Overload         | Current > 15A       |
| Frequency Fault  | Frequency > 51Hz    |
| High Temperature | Temperature > 45°C  |
| Emergency        | Push Button Pressed |

---

# 🛡 Protection Mechanism

When a fault is detected:

✅ Relay Disconnects Load

✅ Buzzer Alarm Activates

✅ Red LED Turns ON

✅ Green LED Turns OFF

✅ Dashboard Updates in Real-Time

✅ Event Logged to Serial Monitor

---

# 📱 Dashboard Features

## Blynk IoT Dashboard

* Voltage Gauge
* Current Gauge
* Frequency Gauge
* Temperature Gauge
* Status Display
* Real-Time Monitoring

## Web Dashboard

* Responsive Interface
* Auto Refresh
* Live Monitoring
* Fault Visualization
* Remote Access

---

# 🖥 OLED Display

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

# 📂 Project Structure

```text
IoT-Smart-Grid-Monitoring-System
│
├── src
│   └── main.ino
│
├── images
│   ├── project_view_1.png
│   ├── hardware_setup.png
│   ├── dashboard_1.png
│   ├── dashboard_2.png
│   ├── dashboard_3.png
│   ├── dashboard_4.png
│   └── dashboard_5.png
│
├── docs
│   └── project_report.pdf
│
├── README.md
└── LICENSE
```

---

# 🛠 Technologies Used

* ESP32
* Embedded C++
* WiFi
* Blynk IoT
* Web Server
* OLED Graphics
* IoT Monitoring
* Fault Detection Systems

---

# 🎯 Applications

* Smart Grid Monitoring
* Power Distribution Systems
* Industrial Automation
* Energy Management
* Smart Infrastructure
* Electrical Safety Systems
* Remote Monitoring Systems

---

# 📈 Future Enhancements

* AI-Based Fault Prediction
* Predictive Maintenance
* Energy Consumption Analytics
* Cloud Database Integration
* Mobile Notifications
* Smart Energy Forecasting
* Machine Learning Integration

---

# 👨‍💻 Author

## Sumit Kumar

**Electrical & Electronics Engineering (EEE)**

Embedded Systems | IoT | AI & Robotics

📍 Bihar, India

### Connect With Me

* GitHub: https://github.com/sumitraj7766
* LinkedIn:https://www.linkedin.com/in/shreyansh90/

---

# ⭐ Support

If you found this project useful:

⭐ Star this repository

🍴 Fork this repository

📢 Share it with others

---

<p align="center">
  Made with ❤️ by Sumit Kumar
</p>
