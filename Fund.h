#pragma once
#include "City.h"
#include <cstdlib>

class Fund
{ private:
  int coffers;
  public:
  Fund(int fundSize);
  int getCoffers();
  void takeTaxes(City&);
  void payAllowance(City&);
  void payment(int);
};
