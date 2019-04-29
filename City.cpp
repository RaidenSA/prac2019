#include "City.h"

City::City(int tRate, int alRate, int vacCost)
{
  cityType = 1+rand()%3;
  well.healthy = cityType*1000;
  funds = 0;
  taxes = 0;
  allowance = 0;
  vaccinationCost = vacCost;
  taxRate = tRate;
  allowanceRate =alRate;
};

void City::epidemicDevelopment() //Main function for making well and ill, payments.For 1tic
{
  well.healthy += deseased.cure();//People get cured
  payment(); //We pay allowance and collect taxes
  int currSick = well.getIll(cityType); //People get ill
  deseased.becomeSick(currSick);
  currSick = 0;
  int currVaccinated = funds / vaccinationCost;
  int currHealthy = well.healthy - well.getVaccinated();
  if (currVaccinated > currHealthy) currVaccinated = currHealthy;
  well.vaccinate(currVaccinated);
  funds = 0;
};

void City::payment()//Function to count money in city
{
  allowance += deseased.allSick()*allowanceRate;
  taxes += well.healthy*65/100*taxRate;
};
