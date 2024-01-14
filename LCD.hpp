#ifndef LCD_HPP
#define LCD_HPP

#include "Arduino.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Screen.hpp"

class LCD
{
  public:
    LCD(LiquidCrystal_I2C *lcd);
    ~LCD();
    void setScreen(Screen *screen);
    Screen *getScreen();
    void update();

  private:
    LiquidCrystal_I2C *lcd;
    Screen* screen;
};

#endif
