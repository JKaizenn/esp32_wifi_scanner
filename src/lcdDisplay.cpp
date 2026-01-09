#include "lcdDisplay.h"

/**************
 * DEFAULT CONSTRUCTOR
 **************/
LcdDisplay::LcdDisplay() : brightnessIndex(0), lastButtonState(HIGH) { }

/**************
 * BEGIN
 **************/
void LcdDisplay::begin()
{
    lcd.begin(16, 2);                                  // Initialize 16x2 LCD
    pinMode(BACKLIGHT_PIN, OUTPUT);                    // Set backlight pin as output
    pinMode(BUTTON_PIN, INPUT_PULLUP);                 // Set button pin with pull-up
    setBrightness(BRIGHTNESS_LEVELS[brightnessIndex]); // Set initial brightness
}

/**************
 * SET BRIGHTNESS
 **************/
void LcdDisplay::setBrightness(int level) {
    analogWrite(BACKLIGHT_PIN, level);
}

/**************
 * CHECK BUTTON
 **************/
void LcdDisplay::checkButton()
{
    bool currentState {digitalRead(BUTTON_PIN)}; // Set current state to BUTTON_PIN output
    if (currentState == LOW && lastButtonState == HIGH)
    {
        delay(50);                                            // Debounce (wait for button to settle)
        brightnessIndex = (brightnessIndex + 1) % NUM_LEVELS; // Cycle 0-1-2-3-4-0
        setBrightness(BRIGHTNESS_LEVELS[brightnessIndex]);    // Apply new level
    }

    lastButtonState = currentState; 
}

/**************
 * PRINT
 **************/
void LcdDisplay::print(const String& text)
{
    lcd.print(text);
}

/**************
 * PRINT LINE
 * Set Cursor to row, clear it, then print
 **************/
void LcdDisplay::printLine(int row, const String& text)
{
    lcd.setCursor(0, row);          // Column 0, row 0 or 1
    lcd.print("                ");  // Clear row (16 spaces)
    lcd.setCursor(0, row);          // Clear row (16 spaces)
    lcd.print(text);
}

/**************
 * CLEAR
 **************/
void LcdDisplay::clear()
{
    lcd.clear(); // Clears the lcd screen
}

/**************
 * BRIGHTNESS LEVELS
 **************/
const int LcdDisplay::BRIGHTNESS_LEVELS[5] = {255, 191, 127, 64, 0};