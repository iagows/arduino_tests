#include "display.h"
#include <SoftwareSerial.h>

Display dis;
int y;
int x;

SoftwareSerial bt(10, 9);

void setup() {
  Serial.begin(38400);
  bt.begin(38400);
  dis.setup(2, true);
  
  Serial.println("begin");
}

void loop() {
  y = 0;

  String data = "";

  bool changed = false;
  while (bt.available() > 0) {
    char input = char(bt.read());

    if (input == ':') {
      y = data.toInt();
      if (y == 0) {
        dis.clearDisplay();
      }
      data = "";
    } else if (input != '\n') {
      data += input;
    }
    else {
      dis.draw(data, y);
      Serial.print(y);
      Serial.print(":");
      Serial.println(data);
      Serial.print("------");
      Serial.println(input);
    }
  }
  dis.show();

  // Um pequeno delay para evitar bugs estranhos.
  delay(10);
}
