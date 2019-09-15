#include <Arduino.h>

#include <h1.CoreFoundation.h>
#include <h1.CoreGraphics.h>
#include <h1.UI.h>

CGBitmap bitmap = CGBitmap(CGSize(16, 16), CGColorDepth::MONO_1_BIT);
CGDrawingContext *context;

void setup() {
  Serial.begin(115200);
  CGDisplay.begin();

  context = bitmap.createDrawingContext();
  context->drawCircle(bitmap.bounds().center(), bitmap.size().width / 2, CGCOLOR_YELLOW);

  context = new CGDrawingContext(CGDisplay.nativeTFT(), CGRect(CGPointZero, TFT_WIDTH, TFT_HEIGHT), false);
  context->fill(CGCOLOR_BLACK);
  context->fillRect(context->frame().pad(20), CGCOLOR_BLUE);
  context->fillCircle(context->frame().center(), context->size().width / 2 - 20, CGCOLOR_RED);

  // context->drawBitmap(bitmap, context->frame().center());

  bitmap.free();
}

void loop() {
}
