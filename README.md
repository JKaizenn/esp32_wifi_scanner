# ESP32 WiFi Scanner

A WiFi network scanner built with C++ for the ESP32 microcontroller. Scans nearby networks and displays detailed information sorted by signal strength.

## Features

- Scans for local WiFi networks
- Sorts networks by signal strength (RSSI)
- Displays SSID, signal strength (dBm), and channel
- LCD display (16x2) showing connection status and scan results
- Button-controlled LCD brightness
- Serial interface for WiFi credential input

## Hardware

- ESP32 DevKitC
- LCD 1602 display (parallel mode)
- Pushbutton for brightness control
- Breadboard and jumper wires

## Project Structure
```
include/
    network.h          # Network data structure
    networkScanner.h   # Scanning and sorting logic
    wifiManager.h      # WiFi connection handling
    lcdDisplay.h       # LCD and brightness control
src/
    network.cpp
    networkScanner.cpp
    wifiManager.cpp
    lcdDisplay.cpp
    main.cpp
```

## Getting Started

1. Install [PlatformIO](https://platformio.org/)
2. Clone this repository
3. Open in VS Code with PlatformIO extension
4. Build and upload to your ESP32

## Roadmap

- [ ] Store WiFi credentials in flash memory
- [ ] Web server to view scan results from phone/browser
- [ ] Network connection functionality

## License

MIT
