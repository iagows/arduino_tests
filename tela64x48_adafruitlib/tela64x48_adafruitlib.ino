//https://learn.adafruit.com/i31fl3731-16x9-charliplexed-pwm-led-driver/library-reference
//https://wiki.wemos.cc/products:retired:oled_shield_v1.1.0?s[]=64x48
//https://learn.adafruit.com/adafruit-gfx-graphics-library/graphics-primitives
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// SCL GPIO5
// SDA GPIO4
#define RESET 2  // GPIO 2
Adafruit_SSD1306 display(RESET);

const uint16_t tamanho = sizeof(uint16_t);
static unsigned char valores[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x7d, 0xf1, 0x9f, 0x11, 0x86, 0x11, 0x91, 0x00, 
0x05, 0x30, 0x91, 0x10, 0x82, 0x10, 0x91, 0x00, 
0x7d, 0x50, 0x9f, 0x20, 0x82, 0x20, 0x9f, 0x00, 
0x41, 0x90, 0x91, 0x20, 0x82, 0x20, 0x81, 0x00, 
0x7d, 0xf0, 0x9f, 0x40, 0x82, 0x40, 0x81, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x7d, 0xf3, 0x91, 0x22, 0xfa, 0x20, 0x00, 0x00, 
0x4d, 0x13, 0x91, 0x22, 0x8b, 0x60, 0x00, 0x00, 
0x55, 0xf0, 0x1f, 0x3e, 0xfb, 0xe0, 0x00, 0x00, 
0x65, 0x13, 0x81, 0x02, 0x8a, 0x20, 0x00, 0x00, 
0x7d, 0xf3, 0x81, 0x02, 0x8a, 0x20, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x7d, 0xf7, 0xdf, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x11, 0x14, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x11, 0xf4, 0xd1, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x11, 0x14, 0x51, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x7d, 0x17, 0xdf, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x07, 0x9e, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x04, 0x51, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x05, 0xde, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x04, 0x54, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x07, 0x91, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x1e, 
0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0xe0, 0x12, 
0x00, 0x00, 0x00, 0x00, 0x70, 0x38, 0x1c, 0x12, 
0x00, 0x00, 0x00, 0x01, 0x81, 0xc7, 0x03, 0x12, 
0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0xc0, 0x1e, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x1e, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
bool changed = true;

void setup()   {
  //Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 64x48)
  // init done

  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(500);

  if (changed) {
    // Clear the buffer.
    display.clearDisplay();

    uint16_t w = 64;
    uint16_t h = 31;
    uint16_t total = 15;
    uint16_t linha = 0;
    uint16_t coluna = 0;
    //Serial.print("Coluna:\t");
    for (int i = 0; i < w*h; ++i) {
      for (int x = 7; x > -1; x--) {

        if ((valores[i] >> x) & 0x1 > 0) {
          display.drawPixel(coluna, linha, WHITE);
        }
        //Serial.print((valores[i] >> x) & 0x1 > 0);

        
        coluna++;

        if (coluna == w) {
          //Serial.print("\nColuna:\t");

          coluna = 0;
          linha++;
        }
      }
    }
    display.display();
    delay(2000);
    changed = false;
  }
}

void loop() {

}