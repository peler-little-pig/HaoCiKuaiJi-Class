#include "Dict.hpp"

Dict::Dict()
{
  strcpy(this->dict[0], "aaaa");
  strcpy(this->dict[1], "bbbb");
  strcpy(this->dict[2], "cccc");
  this->len = 2;
}

Dict::~Dict()
{
  
}

char* Dict::getWord()
{
  return this->dict[this->point];
}

void Dict::next()
{
  if (this->point == this->len)
    this->point = 0;
  else
    this->point++;
}

char *Dict::random_choice()
{
  randomSeed(analogRead(A0));
  int number = random(0, this->len+1);
  while (number==this->point)
    number = random(0, this->len+1);
  this->point = number;
  return this->dict[this->point];
}

void Dict::write_init()
{
  this->write_point = 0;
  this->point = 0;
}

void Dict::write(const char *data)
{
  strcpy(this->dict[write_point], data);
  this->write_point++;
  this->len = this->write_point;
}
