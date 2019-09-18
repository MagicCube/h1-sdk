#pragma once

#include <Arduino.h>

#include "UIView.h"

// A class represents a window.
// Tipically there's only one window in an application.
class UIWindow : public UIView {
public:
  // Creates a new instance of `UIWindow`.
  UIWindow(CGRect frame);

  // Gets the root view of the window.
  UIView *rootView();

  // Sets the root view of the window.
  void rootView(UIView *rootView);

  bool needsRedraw() override;

  void update() override;

  void redraw(bool force = false) override;

  void draw() override;

private:
  UIView *_rootView = nullptr;
};
