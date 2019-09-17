#include <h1.UI.h>

#include "ClockView.h"

class AppDelegate : public UIApplicationDelegate {
public:
  void applicationDidBegin() override {
    _clockView = new ClockView(UIScreen.bounds().centerRect(216, 48));
  }

  void applicationWillUpdate() override {
    _clockView->update();
  }

  void applicationWillRedraw() override {
    _clockView->redraw();
  }

private:
  ClockView *_clockView;
};
