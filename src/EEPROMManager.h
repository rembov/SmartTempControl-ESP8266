#pragma once

class EEPROMManager {
public:
  void begin();
  void saveMode(int mode);
  int loadMode();
};