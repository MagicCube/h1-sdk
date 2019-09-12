#include "CGDrawingContext.h"

CGDrawingContext::CGDrawingContext(CGRect frame, bool inMemory) {
  _frame = frame;
  _zeroTranslation = _frame.equals(CGRectZero);
  _inMemory = inMemory;
}

CGDrawingContext::CGDrawingContext(TFT_eSPI *tft, CGRect frame, bool inMemory) : CGDrawingContext(frame, inMemory) {
  _drawable = tft;
}

CGRect CGDrawingContext::frame() {
  return _frame;
}

void CGDrawingContext::drawPixel(CGPoint point, cg_color_t color) {
  auto absPoint = translatePoint(point);
  _drawable->drawPixel(absPoint.x, absPoint.y, color);
}

void CGDrawingContext::drawLine(CGPoint p1, CGPoint p2, cg_color_t color) {
  auto absP1 = translatePoint(p1);
  auto absP2 = translatePoint(p2);
  _drawable->drawLine(absP1.x, absP1.y, absP2.x, absP2.y, color);
}

void CGDrawingContext::drawFastVLine(CGPoint origin, cg_unit_t height, cg_color_t color) {
  auto absOrigin = translatePoint(origin);
  _drawable->drawFastVLine(absOrigin.x, absOrigin.y, height, color);
}

void CGDrawingContext::drawFastHLine(CGPoint origin, cg_unit_t width, cg_color_t color) {
  auto absOrigin = translatePoint(origin);
  _drawable->drawFastHLine(absOrigin.x, absOrigin.y, width, color);
}

void CGDrawingContext::drawRect(CGRect rect, cg_color_t color) {
  auto absRect = translateRect(rect);
  _drawable->drawRect(absRect.origin.x, absRect.origin.y, absRect.size.width, absRect.size.height, color);
}

void CGDrawingContext::drawRoundRect(CGRect rect, cg_unit_t roundness, cg_color_t color) {
  auto absRect = translateRect(rect);
  _drawable->drawRoundRect(absRect.origin.x, absRect.origin.y, absRect.size.width, absRect.size.height, roundness,
                           color);
}

void CGDrawingContext::drawCircle(CGPoint center, cg_unit_t radius, cg_color_t color) {
  auto absCenter = translatePoint(center);
  _drawable->drawCircle(absCenter.x, absCenter.y, radius, color);
}

void CGDrawingContext::drawString(String string, CGPoint position) {
  auto absPosition = translatePoint(position);
  _drawable->drawString(string, absPosition.x, absPosition.y);
}

void CGDrawingContext::fill(cg_color_t color) {
  if (_inMemory) {
    ((TFT_eSprite *)_drawable)->fillSprite(color);
  } else {
    _drawable->fillScreen(color);
  }
}

void CGDrawingContext::fillRect(CGRect rect, cg_color_t color) {
  auto absRect = translateRect(rect);
  _drawable->fillRect(absRect.origin.x, absRect.origin.y, absRect.size.width, absRect.size.height, color);
}

void CGDrawingContext::fillRoundRect(CGRect rect, cg_unit_t roundness, cg_color_t color) {
  auto absRect = translateRect(rect);
  _drawable->fillRoundRect(absRect.origin.x, absRect.origin.y, absRect.size.width, absRect.size.height, roundness,
                           color);
}

void CGDrawingContext::fillCircle(CGPoint center, cg_unit_t radius, cg_color_t color) {
  auto absCenter = translatePoint(center);
  _drawable->fillCircle(absCenter.x, absCenter.y, radius, color);
}
