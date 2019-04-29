#include "HealthyCounter.h"

HealthyCounter::HealthyCounter()
{
  vaccinated[newVaccinated] = 0;
  vaccinated[weekAgoVaccinated] = 0;
  vaccinated[alreadyVaccinated] = 0;
  healthy = 0;
}

void  HealthyCounter::vaccinate(int number)
{
  vaccinated[alreadyVaccinated] += vaccinated[weekAgoVaccinated];
  vaccinated[weekAgoVaccinated] = vaccinated[newVaccinated];
  vaccinated[newVaccinated] = number;
};
  
int HealthyCounter::getVaccinated()
{
  return (vaccinated[newVaccinated]+vaccinated[weekAgoVaccinated]+vaccinated[alreadyVaccinated]);
};

int HealthyCounter::getIll() // Returns a number of new ill
{ // Should be much more coplicated, but later
  int sick = (healthy - vaccinated[alreadyVaccinated]) / 4;
  if (sick<=0) sick=0;
  healthy = healthy - sick;
  vaccinated[weekAgoVaccinated] -= vaccinated[weekAgoVaccinated] / 4;
  vaccinated[newVaccinated] -= vaccinated[newVaccinated] / 4;
  return sick; 
};

int HealthyCounter::getAlreadyVaccinated()
{
  return vaccinated[alreadyVaccinated];
};

