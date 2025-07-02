#include "TemperatureSensor.h"
#include <OneWire.h>
#include <DallasTemperature.h>

static OneWire oneWire(D2);
static DallasTemperature sensors(&oneWire);

void TemperatureSensor::begin() {
  sensors.begin();
}

float TemperatureSensor::read() {
  sensors.requestTemperatures();
  return sensors.getTempCByIndex(0);
}