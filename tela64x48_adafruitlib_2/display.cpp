#include "display.h"

// SCL GPIO5
// SDA GPIO4

Display::Display() {

}

Display::~Display() {
  delete display;
}

void Display::setup(int resetPin, bool showIntro) {
  display = new Adafruit_SSD1306(resetPin);
  display->begin(SSD1306_SWITCHCAPVCC, 0x3C);
  if (showIntro) {
    display->display();
    delay(500);
  }
  display->clearDisplay();
}

void Display::clearDisplay() {
  display->clearDisplay();
}

void Display::draw(int x, int y)
{
  display->drawPixel(x + 32, y + 8, WHITE);
}

void Display::show()
{
  display->display();
}
