#ifndef SOUNDCONTROLLER_H
#define SOUNDCONTROLLER_H

class SoundController {
public:
  static void playReady();
  static void playAlert();
  static void playOk();
  static void playError();
  static void playMelody(int melody[], int melodySize);
};

#endif
