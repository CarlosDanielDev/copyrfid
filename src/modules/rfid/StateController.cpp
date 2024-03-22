#include <M5StickCPlus2.h>
#include <Arduino.h>

#include "StateController.h"
#include "core/DisplayController.h"
#include "shared/Global.h"
#include "core/SoundController.h"


void StateController::switchToReadMode() {
  SoundController::playReady();
  currentState = READ_MODE;
  DisplayController::displayReadMode();
}

void StateController::switchToWriteMode() {
  SoundController::playAlert();
  currentState = WRITE_MODE;
  DisplayController::displayWriteMode();
}

void StateController::handleStateChange() {
  if (M5.BtnA.wasReleased() && readUID) {
    DisplayController::cls();
    switch (currentState) {
    case READ_MODE:
      StateController::switchToWriteMode();
      break;
    case WRITE_MODE:
      readUID = false;
      StateController::switchToReadMode();
      break;
    }
  }
}
