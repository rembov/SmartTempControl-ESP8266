#pragma once
#include <functional>

class ButtonHandler {
public:
  void begin();
  void read();
  bool isPressed(int pin);
};