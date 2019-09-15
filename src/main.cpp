#include <Arduino.h>

#include <h1.CoreFoundation.h>
#include <h1.CoreGraphics.h>
#include <h1.UI.h>

TFT_eSPI tft;
CGDrawingContext context(&tft, CGRect(CGPointZero, TFT_WIDTH, TFT_HEIGHT), false);

void setup() {
  Serial.begin(115200);
  tft.begin();
  context.fill(CG_COLOR_BLACK);
  context.drawRect(context.frame(), CG_COLOR_WHITE);
  context.drawRect(context.frame().pad(10, 20, 30, 40), CG_COLOR_WHITE);
}

void loop() {
}
