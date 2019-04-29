#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
using std::vector;

class SickCounter 
{ private:
  int sick[4];
  public:
  SickCounter();
  int cure();
  int allSick();
  void becomeSick(int);
};

class HealthyCounter
{ private:
  int vaccinated[3];
  public:
  int healthy;
  HealthyCounter();
  void vaccinate(int);
  int getIll();
  int getVaccinated();
};

class City 
{ public:
  int cityType; 
  int funds; 
  int allowance;
  int taxes; 
  int vaccinationCost; 
  SickCounter deseased; 
  HealthyCounter well; 
  City();
  void epidemicDevelopment(); 
  void payment();
};

class Fund
{ private:
  int coffers;
  public:
  Fund();
  int getCoffers();
  void takeTaxes(City&);
  void payAllowance(City&);
  void payment(int);
};

class Country 
{ public: 
  int numberOfCities;
  int timeBorders;
  Fund stock;
  float threshold;
  vector<City> cities; 
  Country(int number);
  void timeFloat(); 
  int getHealthy();
  int getIll();
  //vector<int> getIllCities();
};



