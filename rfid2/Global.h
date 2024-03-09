#ifndef GLOBAL_H
#define GLOBAL_H

enum State {
  READ_MODE,
  WRITE_MODE
};

extern State currentState;

extern bool readUID;
extern byte UID[20];
extern uint8_t UIDLength;

#endif 
