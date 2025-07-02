#pragma once
#include "ModeManager.h"

class FanController {
public:
  void begin();
  void control(float temperature, Mode mode);
  int getSpeed() const;
private:
  int pwmValue = 0;
};