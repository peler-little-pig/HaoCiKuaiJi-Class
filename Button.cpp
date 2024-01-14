#include "Button.hpp"

Button::Button(int pin)
{
  this->pin = pin;
}

Button::~Button()
{
  
}
    
void Button::update()
{
  
}
    
boolean Button::is_once_click()
{
  if (digitalRead(this->pin))
  {
    if (this->is_clicked)
    {
      return false;
    }
    else
    {
      this->is_clicked = true;
      return true;
    }
  }
  else
  {
    this->is_clicked = false;
    return false;
  }
}
    
