#include <h1.UI.h>

#include "ClockView.h"

class AppDelegate : public UIApplicationDelegate {
public:
  void applicationDidBegin() override {
    _clockView = new ClockView(UIScreen.bounds().centerRect(140, 48));
  }

  void applicationWillUpdate() override {
    _clockView->update();
    _clockView->redraw();
  }

private:
  ClockView *_clockView;
};
