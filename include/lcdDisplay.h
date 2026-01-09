#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H
#include <Arduino.h>
#include <LiquidCrystal.h>

class LcdDisplay
{
public:
    LcdDisplay();
    void begin();
    void print(const String& text);
    void printLine(int row, const String& text);
    void clear();
    void checkButton();

private:
    // Pin Numbers
    static constexpr int RS_PIN = 22;
    static constexpr int E_PIN = 23;
    static constexpr int D4_PIN = 5;
    static constexpr int D5_PIN = 18;
    static constexpr int D6_PIN = 19;
    static constexpr int D7_PIN = 21;
    static constexpr int BACKLIGHT_PIN = 4;
    static constexpr int BUTTON_PIN = 15;

    // LCD Object
    LiquidCrystal lcd{RS_PIN, E_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN}; 
    int brightnessIndex;           // Current brightness level (0-4)
    bool lastButtonState;          // For detecting brightness level (0-4)
    void setBrightness(int level); // Helper method

    // Brightness levels
    static const int BRIGHTNESS_LEVELS[5];
    static constexpr int NUM_LEVELS = 5;
};
#endif