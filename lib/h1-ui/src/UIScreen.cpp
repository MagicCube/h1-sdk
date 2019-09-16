#include "UIScreen.h"

void UIScreenClass::begin() {
  _display->begin();
}

CGDisplay *UIScreenClass::display() {
  return _display;
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

UIScreenClass UIScreen;
