#include <Arduino.h>

#include <h1.CoreFoundation.h>
#include <h1.CoreGraphics.h>
#include <h1.UI.h>

void setup() {
  Serial.begin(115200);
  UIScreen.begin();

  auto context = new CGDrawingContext(UIScreen.display());
  context->fill(CGCOLOR_BLACK);
  context->fillRect(context->frame().pad(20), CGCOLOR_BLUE);
  context->fillCircle(context->frame().center(), context->size().width / 2 - 20, CGCOLOR_RED);
}

void loop() {
}
