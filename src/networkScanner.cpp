#include "networkScanner.h"
#include <WiFi.h>
#include <algorithm>


/**************
 * DEFAULT CONSTRUCTOR
 **************/
NetworkScanner::NetworkScanner() { }

/**************
 * SCAN
 * Scan all networks 
 **************/
void NetworkScanner::scan()
{
    networks.clear(); // Clear old results
    int count = WiFi.scanNetworks();

    for (int i {}; i < count; i++)
    {
        Network net(WiFi.SSID(i), WiFi.RSSI(i), WiFi.channel(i));
        networks.push_back(net);
    }
}

/**************
 * SORT BY SIGNAL
 **************/
void NetworkScanner::sortBySignal()
{
    std::sort(networks.begin(), networks.end(), [](const Network& a, const Network& b) {
    return a.getRssi() > b.getRssi();  // descending order
  });
}

/**************
 * PRINT ALL
 **************/
void NetworkScanner::printAll() const
{
    // Print using the class
    for (int i{0}; i < networks.size(); i++)
    {
        Serial.print(i + 1);
        Serial.print(": ");
        networks[i].print();
  }
}

/**************
 * GET COUNT
 **************/
int NetworkScanner::getCount() const
{
    return networks.size();
}

