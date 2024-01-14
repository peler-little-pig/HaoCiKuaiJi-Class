#include "LCD.hpp"

LCD::LCD(LiquidCrystal_I2C *lcd)
{
  this->lcd = lcd;
  this->screen = new Screen();
}

LCD::~LCD()
{
  
}

void LCD::setScreen(Screen *screen)
{
  this->lcd->clear();
  this->screen = screen;
  this->update();
}

Screen *LCD::getScreen()
{
  return this->screen;
}

void LCD::update()
{
  this->lcd->clear();
  this->screen->update(this->lcd);
}
