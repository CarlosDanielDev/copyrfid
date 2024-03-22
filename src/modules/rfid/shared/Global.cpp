#include "Global.h"
#include <Arduino.h>

State currentState = READ_MODE;
bool readUID;
byte UID[20];
uint8_t UIDLength;
