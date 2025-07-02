#include "ButtonHandler.h"
#include <Arduino.h>

void ButtonHandler::begin() {
  pinMode(D5, INPUT_PULLUP);
  pinMode(D6, INPUT_PULLUP);
}

void ButtonHandler::read() {}

bool ButtonHandler::isPressed(int pin) {
  return digitalRead(pin) == LOW;
}