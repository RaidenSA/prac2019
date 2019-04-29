#pragma once
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
