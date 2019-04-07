// Henry's Bench Hello World - for use with Monochrome OLEDs

#include "U8g2lib.h"

//**************************************************
// Change this constructor to match your display!!!
U8G2_SSD1306_64X48_ER_1_SW_I2C u8g(U8G2_R0, 1,2,3);
//**************************************************

void setup() {
  Serial.begin(9600);
  u8g.begin();
}

void loop() {
  u8g.firstPage();
  do {
    draw();
  } while ( u8g.nextPage() );
  delay(1000);
}

void draw() {
  uint16_t w = 3;//24;
  uint16_t h = 7;

  uint16_t d[w * h] = {
    0xff, 0xff, 0xff, 0xff,
    0x80, 0x00, 0x00, 0x01,
    0x80, 0x00, 0x00, 0x01,
    0x80, 0x00, 0x00, 0x01,
    0x80, 0x00, 0x00, 0x01,
    0x80, 0x00, 0x00, 0x01,
    0xff, 0xff, 0xff, 0xff
  };
  uint16_t linha = 0;
  uint16_t coluna = 0;
  uint16_t s = sizeof(uint16_t);
  const uint16_t bitsLinha = s * w;
  const uint16_t bitsTotal = w * h;
  for (uint16_t i = 0; i < bitsTotal; ++i) {
    for (uint16_t bits = s * w ; bits > -1; --bits) {
      if (d[i] & (1 << bits)) {
        u8g.drawPixel(coluna, linha);
      }
      coluna++;
    }

    if (coluna > 8 * w) {
      coluna = 0;
      linha++;
    }
  }
  //u8g.drawBitmapP(i, j, 1, 1, dot);
}
