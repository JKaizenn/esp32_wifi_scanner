#include <Arduino.h>
#include <WiFi.h> 
#include <nvs_flash.h>
#include "networkScanner.h"
#include "wifiManager.h"
#include "lcdDisplay.h"
#include "credentialManager.h"

LcdDisplay display;
CredentialManager* credentials;

void setup() 
{
    nvs_flash_init();
    credentials = new CredentialManager();

    Serial.begin(115200);
    delay(1000);
    
    display.begin();
    display.printLine(0, "WiFi Scanner");
    display.printLine(1, "Starting...");
    
    WiFi.mode(WIFI_STA);
    
    String ssid;
    String password;
    
    Serial.println("Checking for saved credentials...");
    
    if (credentials->hasCredentials())
    {
        Serial.println("Found saved credentials!");
        
        ssid = credentials->getSsid();
        password = credentials->getPassword();
        
        Serial.print("SSID: ");
        Serial.println(ssid);
        
        display.printLine(0, "Found saved");
        display.printLine(1, "credentials!");
        delay(1000);
        
        display.printLine(0, "Connecting...");
        display.printLine(1, ssid);
        
        WifiManager wifi(ssid, password);
        wifi.connect();
    }
    else
    {
        Serial.println("No saved credentials found.");
    }
    
    while (!WiFi.isConnected())
    {
        display.printLine(0, "Enter SSID:");
        display.printLine(1, "See Serial...");
        Serial.println("Enter SSID:");
        while (!Serial.available()) { display.checkButton(); }
        ssid = Serial.readStringUntil('\n');
        ssid.trim();
        
        display.printLine(0, "Enter Password:");
        display.printLine(1, "See Serial...");
        Serial.println("Enter Password:");
        while (!Serial.available()) { display.checkButton(); }
        password = Serial.readStringUntil('\n');
        password.trim();
        
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
    
    credentials->save(ssid, password);
    Serial.println("Credentials saved to flash!");
    
    display.printLine(0, "Connected!");
    display.printLine(1, WiFi.localIP().toString());
    Serial.println("Ready!\n");
}

void loop() 
{
    display.checkButton();  
    static NetworkScanner scanner;
    
    scanner.scan();
    
    display.printLine(0, "Networks: " + String(scanner.getCount()));
    display.printLine(1, WiFi.localIP().toString());
    
    Serial.print("Found ");
    Serial.print(scanner.getCount());
    Serial.println(" networks!");
    
    scanner.sortBySignal();
    scanner.printAll();
    
    Serial.println();
    delay(5000);
}