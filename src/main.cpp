#include <Arduino.h>

#define DEBUG

#include <H1CoreFoundation.h>
#include <H1CoreGraphics.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  auto rect = CGRectZero;
  String name = "Rect";
  LOG_D("%s (%d, %d, %d, %d)", name.c_str(), rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
  delay(1000);
}
