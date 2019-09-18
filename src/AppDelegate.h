#include <h1.UI.h>

#include "ClockView.h"

class AppDelegate : public UIApplicationDelegate {
public:
  void applicationReadyToBegin() override {
    _clockView = new ClockView(window()->frame());
    window()->rootView(_clockView);
  }

private:
  ClockView *_clockView;
};
