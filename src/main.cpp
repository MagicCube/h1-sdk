#include <Arduino.h>

#include <h1.CoreFoundation.h>
#include <h1.CoreGraphics.h>
#include <h1.UI.h>

CGDrawingContext context(UIScreen.display());

uint8_t radius = 0;
int8_t direction = 1;

void setup() {
  Serial.begin(115200);
  UIScreen.begin();
}

void loop() {
  context.fill(CGCOLOR_BLACK);
  context.fillCircle(context.frame().center(), radius, CGCOLOR_WHITE);
  radius += direction;
  if (radius >= context.size().width / 2) {
    direction = -1;
  } else if (radius <= 0) {
    direction = 1;
  }
}
