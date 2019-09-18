#include <Arduino.h>

#include "UIWindow.h"

// A delegate for `UIApplication`.
// Please set the delegate of `UIApplication` using `delegate(v)` before `begin()`.
class UIApplicationDelegate {
  friend class UIApplicationClass;

public:
  // Gets the main window of the application.
  UIWindow *window() {
    return _window;
  }

  // Fires immediately before the end of `application.begin()`.
  virtual void applicationDidBegin() {
  }

  // Fires immediately after calling `application.update()`.
  virtual void applicationWillUpdate() {
  }

private:
  UIWindow *_window;
};
