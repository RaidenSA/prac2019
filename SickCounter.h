#pragma once
#include <cmath>
#include <cstdlib>

class SickCounter 
{ private:
  int sick[4];
  public:
  SickCounter();
  int cure();
  int allSick();
  void becomeSick(int);
};
