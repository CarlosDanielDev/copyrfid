#ifndef RFIDCONTROLLER_H
#define RFIDCONTROLLER_H

class RFIDController {
public:
  static void initialize();
  static void handleCardDetection();
  static void readCard();
  static void writeCard();
};

#endif
