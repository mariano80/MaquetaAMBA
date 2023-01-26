#include <Wire.h>
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows




lcd.clear();
lcd.print("Detecte un boton");
lcd.setCursor(0, 1);
lcd.print(w);