#include "UIScreen.h"

void UIScreenClass::begin() {
  CGDisplay.begin();
}

CGRect UIScreenClass::bounds() {
  return CGDisplay.bounds();
}

CGSize UIScreenClass::size() {
  return CGDisplay.size();
}

UIScreenClass UIScreen;
