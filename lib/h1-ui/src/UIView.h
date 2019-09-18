#pragma once

#include <Arduino.h>

#include <h1.CoreGraphics.h>

// A class represents a view which is a rectangle area on the screen.
class UIView {
public:
  // Creates a new instance of `UIView`.
  UIView(CGRect frame);

  virtual ~UIView(){};

  // Gets a `CGRect` represents origin and size of the view in
  // parental coordinate.
  CGRect frame();

  // Gets a `CGRect` represents origin and size of the view in
  // relative coordinate which location is always (0, 0).
  CGRect bounds();

  // Gets the size of the view.
  CGSize size();

  // Gets the origin of the view in parental coordinate.
  CGPoint origin();

  // Gets a boolean value, true if the view needs redraw.
  // The only way to set it true is to invoke `needsRedraw()`.
  bool needsRedraw();

  // Sets `needsRedraw()` to true.
  void setNeedsRedraw();

  // Try to redraw the image of view.
  // It will only invoke `draw()` if the `force` parameter is `true` or `needsRedraw()` returns `true`.
  void redraw(bool force = false);

  // Draws the image of the view. The default implementation does nothing.
  virtual void draw();

  // Automatically called by event loop or parent view.
  virtual void update();

private:
  CGRect _frame;
  CGRect _bounds;
  bool _needsRedraw;
};
