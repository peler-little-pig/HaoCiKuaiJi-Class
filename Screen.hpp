#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "Arduino.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Row.hpp"

class Screen
{
  public:
    Screen();
    ~Screen();
    void setUpRow(Row *upRow);
    Row *getUpRow();
    void setDownRow(Row *downRow);
    Row *getDownRow();
    void update(LiquidCrystal_I2C *lcd);

  private:
    Row *upRow;
    Row *downRow;
};

#endif
