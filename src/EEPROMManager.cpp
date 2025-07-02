#include "EEPROMManager.h"
#include <EEPROM.h>

void EEPROMManager::begin() {
  EEPROM.begin(512);
}

void EEPROMManager::saveMode(int mode) {
  EEPROM.write(0, mode);
  EEPROM.commit();
}

int EEPROMManager::loadMode() {
  return EEPROM.read(0);
}