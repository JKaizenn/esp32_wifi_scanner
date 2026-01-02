#include "network.h"

/**************
 * DEFAULT CTOR
 **************/
Network::Network(String ssid, int rssi, int channel) 
    : ssid(ssid), rssi(rssi), channel(channel) 
{ 
}

/**************
 * PRINT
 * Outputs info about the network: SSID, RSSI, and Channel
 **************/
void Network::print()
{
    Serial.print(ssid);
    Serial.print(" (");
    Serial.print(rssi);
    Serial.print(" dBm) Ch: ");
    Serial.println(channel);
}

/**************
 * GET RSSI
 * Returns the rssi object
 **************/
int Network::getRssi() const
{
    return rssi;
}