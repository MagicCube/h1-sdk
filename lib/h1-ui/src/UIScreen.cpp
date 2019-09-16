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

CGDrawingContext *UIScreenClass::createDrawingContext(CGRect specificFrame) {
  return _display->createDrawingContext(specificFrame);
}

UIScreenClass UIScreen;
