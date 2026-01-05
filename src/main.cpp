#include <Arduino.h>
#include <WiFi.h> 
#include "network.h"
#include "networkScanner.h"
#include "led.h"

void setup() 
{
  Serial.begin(115200);      // Inits Serial Monitor with a communication speed (baud rate)
  WiFi.mode(WIFI_STA);       // Sets device wifi mode to STA (Station Mode) which connects to other networks
}

void loop() 
{
  NetworkScanner scanner;
  static Led statusLed(32);
  scanner.scan();

  Serial.print("Found ");
  Serial.print(scanner.getCount()); // Prints out number of networks that were found
  Serial.println(" networks!");

  scanner.sortBySignal();
  scanner.printAll();

  Serial.println();
  delay(5000);
  statusLed.blink(1000);
}