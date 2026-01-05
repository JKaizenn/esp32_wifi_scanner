#include "wifiManager.h"
#include <WiFi.h>

/**************
 * DEFAULT CONSTRUCTOR
 * SSID, PASSWORD
 **************/
WifiManager::WifiManager(const String& ssid, const String& password) 
    : ssid(ssid), password(password) { }

/**************
 * CONNECT TO WIFI
 **************/
void WifiManager::connect()
{
    Serial.print("Connecting to: ");
    Serial.print(ssid);

    WiFi.begin(ssid, password);

    int attempts {};
    while(WiFi.status() != WL_CONNECTED && attempts < 20)
    {
        delay(500);
        Serial.print(".");
        attempts++;
    }

    if(isConnected())
    {
        Serial.println("Connected!");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());
    }

    else {
        Serial.println("\nFailed to connect!");
    }

}

/**************
 * IS CONNECTED
 **************/
bool WifiManager::isConnected() const
{
    return WiFi.isConnected();
}

/**************
 * GET IP ADDRESS
 **************/
String WifiManager::getIpAddress() const
{
    return WiFi.localIP().toString();
}



