#ifndef DICT_HPP
#define DICT_HPP

#include "Arduino.h"

class Dict
{
  public:
    Dict();
    ~Dict();
    char *getWord();
    void next();
    char *random_choice();
    void write_init();
    void write(const char *data);

  private:
    char dict[300][15];
    int point = 0;
    int len;
    int write_point=0;
};

#endif
