#pragma once
#include <cmath>
#include <cstdlib>

class HealthyCounter
{ private:
  int vaccinated[3];
  public:
  int healthy;
  HealthyCounter();
  void vaccinate(int);
  int getIll();
  int getVaccinated();
  int getAlreadyVaccinated();
};
