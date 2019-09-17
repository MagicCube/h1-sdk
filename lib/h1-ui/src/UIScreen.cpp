#include "UIScreen.h"

UIScreenClass::UIScreenClass() {
  _display = new TFTDisplay();
}

CGDisplay *UIScreenClass::display() {
  return _display;
}

void UIScreenClass::rotation(uint8_t rotation) {
  _display->rotation(rotation);
}

CGRect UIScreenClass::frame() {
  return _display->bounds();
}

CGRect UIScreenClass::bounds() {
  return _display->bounds();
}

CGPoint UIScreenClass::origin() {
  return _display->origin();
}

CGSize UIScreenClass::size() {
  return _display->size();
}

void UIScreenClass::begin() {
  _display->begin();
}

void UIScreenClass::clear() {
  _display->fill(CGCOLOR_BLACK);
}

CGDrawingContext *UIScreenClass::createDrawingContext(CGRect specificFrame) {
  return _display->createDrawingContext(specificFrame);
}

CGDrawingContext *UIScreenClass::drawingContext() {
  if (_drawingContext == nullptr) {
    _drawingContext = createDrawingContext();
  }
  return _drawingContext;
}

UIScreenClass UIScreen;
