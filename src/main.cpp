#include <Arduino.h>

#include <h1.CoreFoundation.h>
#include <h1.CoreGraphics.h>
#include <h1.UI.h>

CGDrawingContext *screenContext;
TFTBitmap bitmap(UIScreen.size(), CGColorDepth::COLOR_8_BIT);
CGDrawingContext *bitmapContext;

uint8_t radius = 0;
int8_t direction = 1;

void setup() {
  Serial.begin(115200);
  UIScreen.begin();

  screenContext = UIScreen.createDrawingContext();
  bitmapContext = bitmap.createDrawingContext();
  bitmapContext->fontFamily(CGFontFamily::MEDIUM_26PX);
  bitmapContext->textColor(CGCOLOR_BLACK);
  bitmapContext->textAlign(CGTextAlign::CENTER);
  bitmapContext->textBaseline(CGTextBaseline::MIDDLE);
  screenContext->fill(CGCOLOR_BLACK);
}

void loop() {
  bitmapContext->fill(CGCOLOR_RED);
  bitmapContext->fillCircle(bitmapContext->frame().center(), radius, CGCOLOR_WHITE);
  radius += direction * 6;
  if (radius >= bitmapContext->size().width / 2) {
    direction = -1;
  } else if (radius <= 0) {
    direction = 1;
  }
  bitmapContext->drawString("Hello", bitmapContext->frame().center());
  screenContext->drawBitmap(&bitmap, CGPointZero);
}
