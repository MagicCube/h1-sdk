#include <h1.UI.h>

#include "ClockView.h"

class AppDelegate : public UIApplicationDelegate {
public:
  void applicationReadyToBegin() override {
  }

  void applicationWillUpdate() override {
  }

private:
  ClockView *_clockView;
};
