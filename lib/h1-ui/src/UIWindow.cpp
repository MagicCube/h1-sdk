#include "UIWindow.h"

UIWindow::UIWindow(CGRect frame) : UIView(frame) {
}

UIView *UIWindow::rootView() {
  return _rootView;
}

void UIWindow::rootView(UIView *view) {
  _rootView = view;
}

bool UIWindow::needsRedraw() {
  if (UIView::needsRedraw()) {
    return true;
  } else {
    return _rootView != nullptr && _rootView->needsRedraw();
  }
}

void UIWindow::update() {
  UIView::update();
  if (_rootView != nullptr) {
    _rootView->update();
  }
}

void UIWindow::redraw(bool force) {
  UIView::redraw(force);
  if (_rootView != nullptr) {
    _rootView->redraw(force);
  }
}

void UIWindow::draw() {
  UIView::draw();
  if (_rootView != nullptr) {
    _rootView->draw();
  }
}
