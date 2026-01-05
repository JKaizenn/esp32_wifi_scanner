#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <Arduino.h>

class WifiManager
{
public:
    WifiManager(const String& ssid, const String& password);

    void connect();
    bool isConnected() const;
    String getIpAddress() const;

private:
    String ssid;
    String password;
};

#endif