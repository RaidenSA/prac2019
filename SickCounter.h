#pragma once
#include <cmath>
#include <cstdlib>

enum {threeWeeksToCure, twoWeeksToCure, oneWeekToCure, readyToCure};

class SickCounter 
{ private:
  int sick[4];
  public:
  SickCounter();
  int cure();
  int allSick();
  void becomeSick(int);
};
