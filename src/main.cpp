#include <Arduino.h>
#include <SPI.h>

#define DEBUG

#include <h1.CoreFoundation.h>
#include <h1.CoreGraphics.h>
#include <h1.UI.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  auto rect = CGRectZero;
  String name = "Rect";
  LOG_D("%s (%d, %d, %d, %d)", name.c_str(), rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
  delay(1000);
}
