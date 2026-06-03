# Cloud-Based IoT Environmental Monitoring System using ESP32 and HiveMQ Cloud

## Overview

This project demonstrates a cloud-connected IoT monitoring system using ESP32, DHT11 sensor, MQTT protocol, and HiveMQ Cloud.

The ESP32 reads temperature data from the DHT11 sensor and publishes it securely to HiveMQ Cloud using MQTT over TLS. Users can monitor sensor data remotely and control onboard devices through MQTT topics.

## Features

* Real-time Temperature Monitoring
* MQTT Publish/Subscribe Communication
* HiveMQ Cloud Integration
* Secure TLS Communication
* Remote LED Control
* Cloud-Based Monitoring
* ESP32 Firmware Development

## Hardware Components

* ESP32 Development Board
* DHT11 Temperature Sensor
* Breadboard
* Jumper Wires

## Software Tools

* Arduino IDE
* HiveMQ Cloud
* MQTT Explorer / HiveMQ Web Client
* GitHub

## MQTT Topics

| Topic             | Description        |
| ----------------- | ------------------ |
| esp32/temperature | Temperature Data   |
| esp32/status      | Device Status      |
| esp32/led         | Remote LED Control |

## Working Principle

1. ESP32 connects to WiFi.
2. ESP32 establishes a secure MQTT connection with HiveMQ Cloud.
3. DHT11 sensor measures temperature.
4. Temperature values are published to HiveMQ Cloud.
5. Remote clients subscribe to MQTT topics.
6. Users can send ON/OFF commands to control the onboard LED.

## Project Architecture

ESP32 → HiveMQ Cloud → MQTT Subscriber

MQTT Publisher → HiveMQ Cloud → ESP32

## Future Enhancements

* Humidity Monitoring
* OLED Display Integration
* Node-RED Dashboard
* Data Logging
* Mobile Notifications
* Predictive Analytics using AI

## Skills Demonstrated

* Embedded Systems
* IoT Architecture
* MQTT Protocol
* Cloud Connectivity
* ESP32 Firmware Development
* Sensor Interfacing
* Real-Time Monitoring
* Remote Device Control
