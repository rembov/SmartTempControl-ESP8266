#include "ModeManager.h"
#include "ButtonHandler.h"
#include <Arduino.h>

void ModeManager::setEEPROM(EEPROMManager* e) {
  eeprom = e;
}

void ModeManager::loadMode() {
  currentMode = (Mode)eeprom->loadMode();
}

void ModeManager::update(ButtonHandler& buttons) {
  if (buttons.isPressed(D5)) currentMode = MODE_AUTO;
  if (buttons.isPressed(D6)) currentMode = MODE_MANUAL;
  eeprom->saveMode(currentMode);
}

Mode ModeManager::getCurrentMode() const {
  return currentMode;
}