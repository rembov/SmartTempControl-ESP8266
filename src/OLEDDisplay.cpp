#include "OLEDDisplay.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

static Adafruit_SSD1306 oled(128, 64, &Wire);

void OLEDDisplay::begin() {
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void OLEDDisplay::showWelcome() {
  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setTextColor(SSD1306_WHITE);
  oled.setCursor(0, 0);
  oled.print("TempControl");
  oled.display();
  delay(1000);
}

void OLEDDisplay::update(float temperature, Mode mode, int fanSpeed) {
  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setCursor(0, 0);
  oled.print("Temp: ");
  oled.print(temperature);
  oled.print(" C");
  oled.setCursor(0, 16);
  oled.print("Mode: ");
  oled.print(mode);
  oled.setCursor(0, 32);
  oled.print("Fan: ");
  oled.print(fanSpeed * 100 / 255);
  oled.print(" %");
  oled.display();
}