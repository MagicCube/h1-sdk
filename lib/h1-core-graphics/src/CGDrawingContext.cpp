#include "CGDrawingContext.h"

CGDrawingContext::CGDrawingContext(CGRect frame) {
  _frame = frame;
  _zeroTranslation = _frame.equals(CGRectZero);
}

CGDrawingContext::CGDrawingContext(CGRect frame, TFT_eSPI *canvas) : CGDrawingContext(frame) {
  _canvas = canvas;
}

CGRect CGDrawingContext::frame() {
  return _frame;
}

void CGDrawingContext::drawPixel(CGPoint point, cg_color_t color) {
  auto absPoint = translatePoint(point);
  _canvas->drawPixel(absPoint.x, absPoint.y, color);
}

void CGDrawingContext::drawLine(CGPoint p1, CGPoint p2, cg_color_t color) {
  auto absP1 = translatePoint(p1);
  auto absP2 = translatePoint(p2);
  _canvas->drawLine(absP1.x, absP1.y, absP2.x, absP2.y, color);
}

void CGDrawingContext::drawFastVLine(CGPoint origin, cg_unit_t height, cg_color_t color) {
  auto absOrigin = translatePoint(origin);
  _canvas->drawFastVLine(absOrigin.x, absOrigin.y, height, color);
}

void CGDrawingContext::drawFastHLine(CGPoint origin, cg_unit_t width, cg_color_t color) {
  auto absOrigin = translatePoint(origin);
  _canvas->drawFastHLine(absOrigin.x, absOrigin.y, width, color);
}

void CGDrawingContext::drawRect(CGRect rect, cg_color_t color) {
  auto absRect = translateRect(rect);
  _canvas->drawRect(absRect.origin.x, absRect.origin.y, absRect.size.width, absRect.size.height, color);
}

void CGDrawingContext::drawRoundRect(CGRect rect, cg_unit_t roundness, cg_color_t color) {
  auto absRect = translateRect(rect);
  _canvas->drawRoundRect(absRect.origin.x, absRect.origin.y, absRect.size.width, absRect.size.height, roundness, color);
}

void CGDrawingContext::drawCircle(CGPoint center, cg_unit_t radius, cg_color_t color) {
  auto absCenter = translatePoint(center);
  _canvas->drawCircle(absCenter.x, absCenter.y, radius, color);
}

void CGDrawingContext::drawString(String string, CGPoint position) {
  auto absPosition = translatePoint(position);
  _canvas->drawString(string, absPosition.x, absPosition.y);
}

void CGDrawingContext::fill(cg_color_t color) {
}

void CGDrawingContext::fillRect(CGRect rect, cg_color_t color) {
  auto absRect = translateRect(rect);
  _canvas->fillRect(absRect.origin.x, absRect.origin.y, absRect.size.width, absRect.size.height, color);
}

void CGDrawingContext::fillRoundRect(CGRect rect, cg_unit_t roundness, cg_color_t color) {
  auto absRect = translateRect(rect);
  _canvas->fillRoundRect(absRect.origin.x, absRect.origin.y, absRect.size.width, absRect.size.height, roundness, color);
}

void CGDrawingContext::fillCircle(CGPoint center, cg_unit_t radius, cg_color_t color) {
  auto absCenter = translatePoint(center);
  _canvas->fillCircle(absCenter.x, absCenter.y, radius, color);
}
