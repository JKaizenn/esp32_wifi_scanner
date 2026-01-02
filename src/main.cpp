#include "network.h"
#include <Arduino.h>
#include <WiFi.h> // Library for wifi scanning
#include <vector> 
#include <algorithm> // For sorting the vector
#define LED_PIN 32

void setup() 
{
  Serial.begin(115200);      // Inits Serial Monitor with a communication speed (baud rate)
  WiFi.mode(WIFI_STA);       // Sets device wifi mode to STA (Station Mode) which connects to other networks
  pinMode(LED_PIN, OUTPUT);
}

void loop() 
{
  int networkCount {WiFi.scanNetworks()}; // Create a network count variable that inits scanNetworks function
  std::vector<Network> networks;

  Serial.print("Found ");
  Serial.print(networkCount); // Prints out number of networks that were found
  Serial.println(" networks!");

  // Fill the vector using constructor
  for (int i{}; i < networkCount; i++)
  {
    Network net(WiFi.SSID(i), WiFi.RSSI(i), WiFi.channel(i));
    networks.push_back(net);
  }
  
  // Sort the vector by strongest signal
  std::sort(networks.begin(), networks.end(), [](const Network& a, const Network& b) {
    return a.getRssi() > b.getRssi();  // descending order
  });

  // Print using the class
  for (int i{0}; i < networkCount; i++)
  {
    Serial.print(i + 1);
    Serial.print(": ");
    networks[i].print();
  }

  Serial.println();
  delay(5000);
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}