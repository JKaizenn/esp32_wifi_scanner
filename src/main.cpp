#include <Arduino.h>
#include <WiFi.h> 
#include "network.h"
#include "networkScanner.h"
#define LED_PIN 32

void setup() 
{
  Serial.begin(115200);      // Inits Serial Monitor with a communication speed (baud rate)
  WiFi.mode(WIFI_STA);       // Sets device wifi mode to STA (Station Mode) which connects to other networks
  pinMode(LED_PIN, OUTPUT);
}

void loop() 
{
  NetworkScanner scanner;
  scanner.scan();

  Serial.print("Found ");
  Serial.print(scanner.getCount()); // Prints out number of networks that were found
  Serial.println(" networks!");

  scanner.sortBySignal();
  scanner.printAll();

  Serial.println();
  delay(5000);

  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}