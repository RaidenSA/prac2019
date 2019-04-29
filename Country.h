#pragma once
#include <cstdlib>
#include <vector>
#include "City.h"
#include "Fund.h"

using std::vector;

class Country 
{ public: 
  int numberOfCities;
  int timeBorders;
  int weeks;
  Fund stock;
  float threshold;
  vector<City> cities; 
  Country(int cityCounter, int fundSize, int week, int taxRate, int allowanceRate,
    int vaccinationCost);
  void takeAllTaxes();
  void payAllAllowance();
  void developAll();
  void timeFloat(); 
  int getHealthy();
  int getIll();
  int step();
  int deseasedProportion();
  vector<int> deseasedProportionCities();
};
