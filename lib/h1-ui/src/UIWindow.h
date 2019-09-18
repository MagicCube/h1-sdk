#pragma once

#include <Arduino.h>

#include "UIView.h"

// A class represents a window.
// Tipically there's only one window in an application.
class UIWindow : public UIView {
public:
  UIWindow(CGRect frame);
private:
};
