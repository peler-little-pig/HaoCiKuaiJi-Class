#include "Row.hpp"

Row::Row()
{

}

Row::~Row()
{
  
}
    
void Row::setMessage(const char *message)
{
  this->message = message;
}
    
char *Row::getMessage()
{
  return this->message;
}
    
void Row::update(LiquidCrystal_I2C *lcd, int row)
{
  lcd->setCursor(0,row);
  lcd->print(this->message);
}
    
