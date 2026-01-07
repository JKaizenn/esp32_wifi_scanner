#include <Arduino.h>
#include <WiFi.h> 
#include "networkScanner.h"
#include "wifiManager.h"

void setup() 
{
    Serial.begin(115200);
    
    // Wait for user to be ready
    Serial.println("Press Enter to start...");
    while (!Serial.available()) { }
    Serial.readStringUntil('\n');
    
    WiFi.mode(WIFI_STA);
    
    // Keep trying until connected
    while (!WiFi.isConnected())
    {
        // Get SSID from user
        Serial.println("Enter SSID:");
        while (!Serial.available()) { }
        String ssid = Serial.readStringUntil('\n');
        ssid.trim();
        
        // Get password from user
        Serial.println("Enter Password:");
        while (!Serial.available()) { }
        String password = Serial.readStringUntil('\n');
        password.trim();
        
        // Try to connect
        WifiManager wifi(ssid, password);
        wifi.connect();
        
        if (!WiFi.isConnected())
        {
            Serial.println("Try again...\n");
        }
    }
    
    Serial.println("Ready!\n");
}

void loop() 
{
    static NetworkScanner scanner;
    
    // Scan for networks
    scanner.scan();
    
    Serial.print("Found ");
    Serial.print(scanner.getCount());
    Serial.println(" networks!");
    
    // Sort and display results
    scanner.sortBySignal();
    scanner.printAll();
    
    Serial.println();
    delay(5000);
}