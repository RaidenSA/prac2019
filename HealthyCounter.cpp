#include "HealthyCounter.h"

HealthyCounter::HealthyCounter()
{
  vaccinated[0] = 0;
  vaccinated[1] = 0;
  vaccinated[2] = 0;
  healthy = 0;
}

void  HealthyCounter::vaccinate(int number)
{
  vaccinated[2] += vaccinated[1];
  vaccinated[1] = vaccinated[0];
  vaccinated[0] = number;
};
  
int HealthyCounter::getVaccinated()
{
  return (vaccinated[0]+vaccinated[1]+vaccinated[2]);
};

int HealthyCounter::getIll() // Returns a number of new ill
{ // Should be much more coplicated, but later
  int sick = (healthy - vaccinated[2]) / 4;
  if (sick<=0) sick=0;
  healthy = healthy - sick;
  vaccinated[1] -= vaccinated[1] / 4;
  vaccinated[0] -= vaccinated[0] / 4;
  return sick; 
};

int HealthyCounter::getAlreadyVaccinated()
{
  return vaccinated[2];
};

