#include "display.h"

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

void Display::draw(String x, int y) {
  for (int i = 0, s = x.length(); i < s; i++) {
    char c = x.charAt(i);
    if(c == '1'){
      draw(i, y);
    }
  }
}

void Display::show()
{
  display->display();
}
