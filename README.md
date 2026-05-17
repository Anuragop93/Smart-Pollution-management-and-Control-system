# REAL-TIME SMART POLLUTION MEASUREMENT AND CONTROL SYSTEM

## Introduction

The **Real-Time Smart Pollution Measurement and Control System** is an IoT and AI-based environmental monitoring project developed to reduce industrial air pollution and improve worker safety to support cleaner and smarter industrial environments in India. The system is mainly designed for coal industries, mining industries, steel plants, manufacturing industries, and power plants where harmful gases and particulate pollutants are generated continuously.

Traditional pollution monitoring systems are expensive and mostly lack real-time automation and predictive capabilities. This project provides a low-cost and smart solution capable of real-time pollution monitoring, automated control, remote IoT monitoring, and AI-based prediction.

The system continuously monitors harmful gases and particulate matter using gas and dust sensors. Whenever pollution levels exceed predefined threshold values, the system automatically activates a wet scrubber filtration mechanism and generates safety alerts for workers and nearby environments.

---

# Objectives

* Real-time industrial pollution monitoring
* Detection of harmful gases and particulate matter
* Automated pollution control mechanism
* Remote IoT monitoring using Blynk
* Worker safety alert system
* AI-based pollution prediction
* Smart and low-cost environmental protection system

---

# Components Used

* ESP32 Microcontroller
* MQ135 Gas Sensor
* PMSA003 PM2.5 Sensor
* OLED Display
* IRLZ44N MOSFET
* Submersible Water Pump
* MT3608 Boost Converter
* Lithium-Ion Battery
* LED Indicators
* Active Buzzer

---

# Block Diagram

<img width="700" height="700" alt="architecture" src="https://github.com/user-attachments/assets/16fbbe32-98bd-4990-870c-e649e2ee484d" />



---

# System Architecture Diagram

<img width="650" height="700" alt="ckt_connection" src="https://github.com/user-attachments/assets/83125762-098d-4fcb-a5fc-a90bf1f1572d" />



---

# WORKING MODEL 

<img width="4096" height="2304" alt="WhatsApp Image 2026-05-17 at 10 52 28-2" src="https://github.com/user-attachments/assets/6f406d4e-cf47-4538-b142-4f824fee8285" />


---

# Circuit Working

## 1. Pollution Detection

The MQ135 sensor continuously detects harmful gases such as NH3, CO2, smoke, alcohol vapors, and other pollutants. Simultaneously, the PMSA003 sensor monitors particulate matter including PM1.0, PM2.5, and PM10 particles present in the atmosphere.

Both sensor outputs are continuously sent to the ESP32 microcontroller for processing and analysis.

---

## 2. Real-Time Monitoring

The ESP32 processes all sensor data in real time and displays pollution levels on the OLED display. The measured values are also transmitted wirelessly to the Blynk IoT cloud platform using Wi-Fi connectivity.

Users can remotely monitor:

* Gas concentration
* PM2.5 levels
* Pollution status
* Alert notifications
* Environmental conditions

through smartphones and web dashboards.

---

## 3. Automated Pollution Control

When pollution exceeds predefined threshold levels:

* The ESP32 activates the IRLZ44N MOSFET
* The MOSFET switches ON the submersible water pump
* Water is sprayed inside the wet scrubber chamber
* Harmful smoke and particulate pollutants are reduced

Once pollution levels decrease below the threshold value, the ESP32 automatically turns OFF the pump.

---

## 4. Worker Safety Alert System

If hazardous gas concentration becomes dangerous:

* Red warning LEDs are activated
* The buzzer generates alert sounds
* OLED display shows warning messages

This helps improve worker safety inside industrial environments.

---

# Machine Learning Integration

The project also integrates Machine Learning algorithms for pollution prediction and data analysis.

Algorithms used:

* LSTM
* Random Forest
* Linear Regression

These models analyze sensor data patterns and predict future pollution levels, helping industries take preventive actions before pollution becomes severe.

---

# Features

* Real-time pollution monitoring
* IoT-based remote monitoring
* Automated wet scrubber mechanism
* AI-based pollution prediction
* Low-cost implementation
* Smart industrial safety system
* Wireless environmental monitoring
* Real-time alert system

---

# Applications

* Coal Industries
* Mining Industries
* Steel Plants
* Manufacturing Industries
* Power Plants
* Smart City Environmental Monitoring

---

# Output

The project successfully demonstrated:

* Real-time monitoring of harmful gases and PM2.5
* Automatic pollution reduction mechanism
* Remote cloud-based monitoring
* Worker safety alert generation
* AI-based pollution trend prediction

The system provides a scalable and energy-efficient solution for smart industrial pollution management.

* LSTM Prediction vs Actual
  <img width="750" height="350" alt="image" src="https://github.com/user-attachments/assets/5f6303af-ecc1-4caa-a044-472a0c17b844" />

* PM2.5 Spike Detection
  <img width="800" height="350" alt="image" src="https://github.com/user-attachments/assets/fb0733d6-873f-4cb6-a1ea-40fe64d46983" />

* Air Quality over time
  <img width="850" height="350" alt="image" src="https://github.com/user-attachments/assets/aca02ef3-bc4e-4c5c-87d6-1c62d5927b21" />

* REAL TIME DASHBOARD
  <img width="900" height="1200" alt="image" src="https://github.com/user-attachments/assets/04582263-c3df-434e-9611-cd83d7600799" />

---

# Future Scope

* Integration with advanced AI models
* Smart city pollution management
* Government environmental monitoring systems
* Multi-industry deployment
* Data logging and analytics
* Solar-powered environmental monitoring

---

# Conclusion

The Real-Time Smart Pollution Measurement and Control System demonstrates how IoT, Embedded Systems, Automation, and AI can work together to create smart environmental protection systems. The project aims to make small-scale industries and power plants across India smarter, safer, and more environmentally responsible while contributing towards cleaner air and a healthier future.
