#pragma once
#include "EEPROMManager.h"
#include "ButtonHandler.h"

enum Mode { MODE_OFF, MODE_MANUAL, MODE_AUTO };

class ModeManager {
public:
  void setEEPROM(EEPROMManager* e);
  void loadMode();
  void update(ButtonHandler& buttons);
  Mode getCurrentMode() const;
private:
  EEPROMManager* eeprom;
  Mode currentMode = MODE_AUTO;
};