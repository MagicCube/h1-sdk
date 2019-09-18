#include <h1.UI.h>

#include "ClockView.h"

class AppDelegate : public UIApplicationDelegate {
public:
  void applicationReadyToBegin() override {
    // Create a clock view centered to the parent window.
    _clockView = new ClockView(window()->frame().centerRect(214, 50));
    // Make clock view as the root view.
    window()->rootView(_clockView);
  }

private:
  ClockView *_clockView;
};
