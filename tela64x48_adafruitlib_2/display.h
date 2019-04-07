#ifndef DISPLAY_H
#define DISPLAY_H

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

class Display
{
  public:
    Display();
    ~Display();
    void setup(int resetPin, bool showIntro = false);
    void clearDisplay();
    void draw(int x, int y);
    void show();

  private:
    Adafruit_SSD1306 *display;
};

#endif // DISPLAY_H
