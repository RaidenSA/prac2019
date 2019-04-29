#pragma once
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "HealthyCounter.h"
#include "SickCounter.h"

class City 
{ public:
  int cityType; 
  int funds; 
  int allowance;
  int taxes; 
  int vaccinationCost; 
  int taxRate;
  int allowanceRate;
  SickCounter deseased; 
  HealthyCounter well; 
  City(int, int, int);
  void epidemicDevelopment(); 
  void payment();
};
