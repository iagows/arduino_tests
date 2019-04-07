#include "display.h"

const int resetPin = 2;
Display dis;

void setup()
{
  dis.setup(resetPin);
}

void loop() {
  for (int i = 0; i < 64; ++i) {
    for (int j = 0; j < 48; ++j) {
      dis.draw(i, j);
    }
  }

  dis.show();
  delay(2000);
}
