#pragma once

#include <Arduino.h>

#include "CGDrawable.h"

// An abstract class represents a drawable canvas.
class CGCanvas : public CGDrawable {
public:
  // Gets the size of the drawable object.
  virtual CGSize size() = 0;

  // Gets a `CGRect` represents origin and size of the contextual canvas in
  // parental coordinate.
  virtual CGRect frame() = 0;

  // Gets a `CGRect` represents origin and size of the contextual canvas in
  // relative coordinate which location is always (0, 0).
  virtual CGRect bounds() = 0;

  // Gets the origin of the drawable object in parental coordinate.
  virtual CGPoint origin() = 0;
};
