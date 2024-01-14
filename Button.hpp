#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "Arduino.h"

class Button
{
  public:
    Button(int pin);
    ~Button();
    void update();
    boolean is_once_click();

  private:
    int pin;
    boolean is_clicked = false;
};

#endif
