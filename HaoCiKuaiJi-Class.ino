#include "Arduino.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Screen.hpp"
#include "LCD.hpp"
#include "Row.hpp"
#include "Dict.hpp"
#include "Button.hpp"

LiquidCrystal_I2C *lcd_I2C;
LCD *lcd;
Screen *init_screen;
Screen *test_screen;
Screen *receive_screen;

Button *button9;
Button *button8;

Dict *dict;

String inString="";

void setup() {
  // put your setup code here, to run once:
  lcd_I2C = new LiquidCrystal_I2C(0x27, 16, 2);
  lcd = new LCD(lcd_I2C);
  init_screen = lcd->getScreen();
  test_screen = new Screen();
  receive_screen = new Screen();

  button9 = new Button(9);
  button8 = new Button(8);

  dict = new Dict();

  Serial.begin(9600);
  
  lcd_I2C->init();
  lcd_I2C->backlight();

  pinMode(9,INPUT);
  pinMode(8, INPUT);

  //init
  init_screen->getUpRow()->setMessage("A: Start test");
  init_screen->getDownRow()->setMessage("B: Import Data");
  lcd->update();
  test_screen->getUpRow()->setMessage(dict->getWord());
  test_screen->getDownRow()->setMessage("A: Exit B: Next");
  receive_screen->getUpRow()->setMessage("Receiving A:Exit");
  receive_screen->getDownRow()->setMessage("");
}

void loop() {
  // put your main code here, to run repeatedly:
  /////////////////////////////////////////
  // init
  /////////////////////////////////////////
  if (lcd->getScreen() == init_screen)
  {
    Serial.println("init");
    if (button9->is_once_click())
    {
      lcd->setScreen(test_screen);
      lcd->update();
    }
    if (button8->is_once_click())
    {
      lcd->setScreen(receive_screen);
      lcd->update();
    }
  }
  /////////////////////////////////////////
  // test
  /////////////////////////////////////////
  else if (lcd->getScreen() == test_screen)
  {
    Serial.println("test");
    if (button9->is_once_click())
    {
      lcd->setScreen(init_screen);
      lcd->update();
    }
    if (button8->is_once_click())
    {
      dict->next();
      test_screen->getUpRow()->setMessage(dict->random_choice());
      Serial.println(dict->getWord());
      lcd->update();
    }
  }
  /////////////////////////////////////////
  // receive
  /////////////////////////////////////////
  else if (lcd->getScreen() == receive_screen)
  {
    Serial.println("receive");
    if (button9->is_once_click())
    {
      lcd->setScreen(init_screen);
      lcd->update();
    }
    while(Serial.available()>0)
    {
      inString += char(Serial.read());
      delay(2);
    }
    if(inString!="")
    {
      if (inString=="haocikuaiji")
      {
        dict->write_init();
      }
      else
      {
        receive_screen->getDownRow()->setMessage(inString.c_str());
        dict->write(inString.c_str());
        lcd->update();
      }
    }
    inString="";
  }
//  delay(100);
}
