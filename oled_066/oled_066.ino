//http://www.esp8266learning.com/wemos-oled-shield-example.php
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// SCL GPIO5
// SDA GPIO4
#define OLED_RESET 22  // GPIO 22
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16

void setup()   {
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 64x48)
  // init done
}

int x = 72;
int y = 8;

int vx = -1;
int vy = 1;
void loop() {
  display.display();
  //delay(500);

  // Clear the buffer.
  display.clearDisplay();

  // text display tests
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(x, y);
  display.println("Iago");

  //display.drawPixel(32,20, 0xFFFF);

  display.display();
  //delay(500);
  //display.clearDisplay();
  x += vx;
  y += vy;
  if (x < 33 || x > 71) {
    vx *= -1;
  }
  if(y < 9 || y > 23){
    vy *=-1;
  }
}
