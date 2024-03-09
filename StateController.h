#ifndef STATECONTROLLER_H
#define STATECONTROLLER_H

class StateController {
public:
  static void switchToReadMode();
  static void switchToWriteMode();
  static void handleStateChange();
};

#endif
