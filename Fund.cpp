#include "Fund.h"

Fund::Fund(int fundSize)
{
  coffers = fundSize;
};

int Fund::getCoffers()
{
  return(coffers);
};

void Fund::takeTaxes(City &cities)
{
  coffers += cities.taxes;
  cities.taxes = 0; 
};

void Fund::payAllowance(City &cities)
{
  int currValue = coffers - cities.allowance;
  if (currValue >=0)
  {
    coffers = currValue;
    cities.allowance = 0;
  }; 
};

void Fund::payment(int funds)
{
  coffers -= funds;
};
