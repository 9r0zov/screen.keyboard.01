#include "Arduino.h"
#include <Wire.h>
#include <Keypad.h>
#include <../lib/LiquidCrystal_I2C/LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

const byte cols = 4;
const byte rows = 4;

char buttons[rows][cols] = {
  {'1', '2', '3', '4'},
  {'5', '6', '7', '8'},
  {'9', 'a', 'b', 'c'},
  {'d', 'e', 'f', 'g'}
};

byte rowPins[rows] = {7, 6, 5, 4};
byte colPins[cols] = {10, 11, 12, 13};

Keypad keypad = Keypad(makeKeymap(buttons), rowPins, colPins, rows, cols);

byte smiley[8] = {
  B00000, B10001, B00000, B00000, B10001, B01110, B00000,
};

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);

  lcd.backlight();

  lcd.createChar(0, smiley);

  lcd.setCursor(0, 0);
  lcd.print("***Input key:***");
  lcd.setCursor(0, 1);

  lcd.write(byte(0));
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    lcd.clear();
    lcd.setCursor(0, 0);

    lcd.print("key pressed: ");
    lcd.print(key);
  }
}
