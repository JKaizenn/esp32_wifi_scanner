#include <Arduino.h>
#include <WiFi.h> 
#include "networkScanner.h"
#include "wifiManager.h"
#include "lcdDisplay.h"

LcdDisplay display;

void setup() 
{
    display.begin();
    display.printLine(0, "WiFi Scanner");
    display.printLine(1, "Press Enter...");
    Serial.begin(115200);
    
    // Wait for user to be ready
    Serial.println("Press Enter to start...");
    while (!Serial.available()) { display.checkButton(); }
    Serial.readStringUntil('\n');
    
    WiFi.mode(WIFI_STA);
    
    // Keep trying until connected
    while (!WiFi.isConnected())
    {
        // Get SSID from user
        display.printLine(0, "Enter SSID:");
        display.printLine(1, "See Serial...");
        Serial.println("Enter SSID:");
        while (!Serial.available()) { display.checkButton(); }
        String ssid = Serial.readStringUntil('\n');
        ssid.trim();
        
        // Get password from user
        display.printLine(0, "Enter Password:");
        display.printLine(1, "See Serial...");
        Serial.println("Enter Password:");
        while (!Serial.available()) { display.checkButton(); }
        String password = Serial.readStringUntil('\n');
        password.trim();
        
        // Try to connect
        display.printLine(0, "Connecting...");
        display.printLine(1, ssid);
        WifiManager wifi(ssid, password);
        wifi.connect();
        
        if (!WiFi.isConnected())
        {
            display.printLine(0, "Failed!");
            display.printLine(1, "Try again...");
            Serial.println("Try again...\n");
        }
    }

    // Show success
    display.printLine(0, "Connected!");
    display.printLine(1, WiFi.localIP().toString());    
    Serial.println("Ready!\n");
}

void loop() 
{
    display.checkButton();  
    static NetworkScanner scanner;
    
    // Scan for networks
    scanner.scan();
    
    display.printLine(0, "Networks: " + String(scanner.getCount()));
    display.printLine(1, WiFi.localIP().toString());
    
    Serial.print("Found ");
    Serial.print(scanner.getCount());
    Serial.println(" networks!");
    
    // Sort and display results
    scanner.sortBySignal();
    scanner.printAll();
    
    Serial.println();
    delay(5000);
}