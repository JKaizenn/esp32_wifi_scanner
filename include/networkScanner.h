#ifndef NETWORK_SCANNER_H
#define NETWORK_SCANNER_H

#include "network.h"
#include <vector>

class NetworkScanner
{
public:
    NetworkScanner();      // Default Constructor
    void scan();           // Calls wifi.scanNetworks()
    void sortBySignal();   // Sort networks by rssi number 
    void printAll() const; // Loop through and print all network info
    int getCount() const;  // Returns the number of networks found

private:
    std::vector<Network> networks; // Store a vector of network objects
};
#endif