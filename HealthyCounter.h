#pragma once
#include <cmath>
#include <cstdlib>

enum {newVaccinated, weekAgoVaccinated, alreadyVaccinated};

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
