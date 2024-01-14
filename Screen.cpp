#include "Screen.hpp"

Screen::Screen()
{
  Row *upRow = new Row();
  Row *downRow = new Row();
  this->upRow = upRow;
  this->downRow = downRow;
}
Screen::~Screen()
{
  
}

void Screen::setUpRow(Row *upRow)
{
  this->upRow = upRow;
}

Row *Screen::getUpRow()
{
  return this->upRow;
}

void Screen::setDownRow(Row *downRow)
{
  this->downRow = downRow;
}

Row *Screen::getDownRow()
{
  return this->downRow;
}

void Screen::update(LiquidCrystal_I2C *lcd)
{
  this->upRow->update(lcd, 0);
  this->downRow->update(lcd, 1);
}
