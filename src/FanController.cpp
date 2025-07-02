#include "FanController.h"
#include <Arduino.h>

void FanController::begin() {
  pinMode(D1, OUTPUT);
  analogWriteFreq(25000);
  analogWrite(D1, 0);
}

void FanController::control(float temperature, Mode mode) {
  if (mode == MODE_OFF) pwmValue = 0;
  else if (mode == MODE_MANUAL) pwmValue = 128;
  else if (mode == MODE_AUTO) {
    if (temperature < 30.0f) pwmValue = 0;
    else if (temperature < 50.0f) pwmValue = map(temperature, 30, 50, 76, 178);
    else pwmValue = 255;
  }
  analogWrite(D1, pwmValue);
}

int FanController::getSpeed() const {
  return pwmValue;
}