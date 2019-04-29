#include "Country.h"

Country::Country(int cityCounter, int fundSize, int week,
      int taxRate, int allowanceRate, int vaccinationCost):stock(fundSize)
{
  numberOfCities = cityCounter;
  for (int i = 0; i < numberOfCities; i++)
  {
    cities.push_back(City(taxRate, allowanceRate, vaccinationCost, 1+rand()%3));
  };
  threshold = 50;
  weeks = week;
};

void Country::payAllAllowance()
{
  for (int i=0; i < numberOfCities; i++) //loop for every city
  {
    stock.payAllowance(cities[i]);
    if (stock.getCoffers() <= 0) break;
  };
  if (stock.getCoffers() > 0)
  { 
    int currFunds = stock.getCoffers()/2;
    stock.payment(currFunds);
    for (int i=0; i<numberOfCities; i++)       
    {
      cities[i].funds += currFunds/numberOfCities;
    };
  }; 
};

void Country::takeAllTaxes()
{
  for (int i=0; i<numberOfCities; i++) 
    {
      stock.takeTaxes(cities[i]);
    };
};

void Country::developAll()
{
  for (int i=0; i<numberOfCities; i++) 
  {
    cities[i].epidemicDevelopment();   
  };
};

void Country::timeFloat() // 1 step of simulation
{ 
  takeAllTaxes();
  payAllAllowance();     
  developAll();
  //At this point the step is finished and we are redy to display information
};

int Country::step()
{
  if(weeks > 0)
  {
    timeFloat();
    weeks--;
    return 1;
  };
  return 0;
};

int Country::getHealthy()
{
  int sum =0;
  for (int i=0; i<numberOfCities; i++) //loop for every city
  {
    sum += cities[i].well.healthy; 
      
  };
  return sum;
};

int Country::getIll()
{
  int sum =0;
  for (int i=0; i<numberOfCities; i++) //loop for every city
  {
    sum += cities[i].deseased.allSick();   
  };
  return sum;
};

int Country::getAllVaccinated()
{
  int sum =0;
  for (int i=0; i<numberOfCities; i++) //loop for every city
  {
    sum += cities[i].well.getAlreadyVaccinated();   
  };
  return sum;
};

int Country::deseasedProportion()
{
  int proportion = getIll() * 100 / (getIll() + getHealthy());
  return proportion;
}

vector<int> Country::deseasedProportionCities()
{
  vector<int> percentage;
  for (int i=0; i<numberOfCities; i++)
  {
    int proportion = (cities[i].deseased.allSick() * 100) / (cities[i].deseased.allSick() 
                   + cities[i].well.healthy);
    percentage.push_back(proportion);
  };
  return percentage;
};
