#ifndef ROW_HPP
#define ROW_HPP

#include "Arduino.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class Row
{
  public:
    Row();
    ~Row();
    void setMessage(const char* message);
    char* getMessage();
    void update(LiquidCrystal_I2C *lcd, int row);

  private:
    char* message;
};

#endif
