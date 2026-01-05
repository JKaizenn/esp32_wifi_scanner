#include "led.h"
#include <Arduino.h> // For pin access

/**************
 * DEFAULT CONSTRUCTOR
 **************/
Led::Led(int pin) : pin(pin) 
{
    pinMode(pin, OUTPUT);
}

/**************
 * ON
 **************/
void Led::on()
{
    digitalWrite(pin, HIGH);
}

 /**************
 * OFF
 **************/
void Led::off()
{
    digitalWrite(pin, LOW);
}

 /**************
 * BLINK
 **************/
void Led::blink(int duration)
{
    on();
    delay(duration);
    off();
    delay(duration);
}
