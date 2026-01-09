#include "lcdDisplay.h"

/**************
 *DEFAULT CONSTRUCTOR
 **************/
LcdDisplay::LcdDisplay() : brightnessIndex(0), lastButtonState(HIGH) { }

/**************
 *BEGIN
 **************/
void LcdDisplay::begin()
{
    lcd.begin(16, 2);                                  // Initialize 16x2 LCD
    pinMode(BACKLIGHT_PIN, OUTPUT);                    // Set backlight pin as output
    pinMode(BUTTON_PIN, INPUT_PULLUP);                 // Set button pin with pull-up
    setBrightness(BRIGHTNESS_LEVELS[brightnessIndex]); // Set initial brightness
}

/**************
 *SET BRIGHTNESS
 **************/
void LcdDisplay::setBrightness(int level) {
    analogWrite(BACKLIGHT_PIN, level);
}

/**************
 *CHECK BUTTON
 **************/
void LcdDisplay::checkButton()
{
    
}