#include "UIView.h"

UIView::UIView(CGRect frame) {
  _frame = frame;
  _bounds = CGRect(CGPointZero, frame.size);
}

CGRect UIView::frame() {
  return _frame;
}

CGRect UIView::bounds() {
  return _bounds;
}

CGSize UIView::size() {
  return _frame.size;
}

CGPoint UIView::origin() {
  return _frame.origin;
}

bool UIView::needsRedraw() {
  return _needsRedraw;
}

void UIView::setNeedsRedraw() {
  _needsRedraw = true;
}

void UIView::redraw(bool force) {
  if (force || _needsRedraw) {
    draw();
  }
  _needsRedraw = false;
}

void UIView::draw() {
}

void UIView::update() {
}
