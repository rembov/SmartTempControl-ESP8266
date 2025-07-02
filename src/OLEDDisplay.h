#pragma once
#include "ModeManager.h"

class OLEDDisplay {
public:
  void begin();
  void showWelcome();
  void update(float temperature, Mode mode, int fanSpeed);
};