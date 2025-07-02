#include "src/TemperatureSensor.h"
#include "src/FanController.h"
#include "src/OLEDDisplay.h"
#include "src/EEPROMManager.h"
#include "src/ButtonHandler.h"
#include "src/ModeManager.h"

TemperatureSensor tempSensor;
FanController fan;
OLEDDisplay display;
EEPROMManager eeprom;
ButtonHandler buttons;
ModeManager modes;

void setup() {
  Serial.begin(115200);
  eeprom.begin();
  modes.setEEPROM(&eeprom);
  tempSensor.begin();
  fan.begin();
  display.begin();
  buttons.begin();
  modes.loadMode();
  display.showWelcome();
}

void loop() {
  buttons.read();
  modes.update(buttons);
  float temperature = tempSensor.read();
  fan.control(temperature, modes.getCurrentMode());
  display.update(temperature, modes.getCurrentMode(), fan.getSpeed());
  delay(1000);
}
