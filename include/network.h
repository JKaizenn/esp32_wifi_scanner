#ifndef NETWORK_H
#define NETWORK_H

#include <Arduino.h>

class Network
{
public:
    Network(String ssid, int rssi, int channel);
    void print()  const;
    int getRssi() const;

private:
    String ssid;
    int rssi;
    int channel;
};
#endif