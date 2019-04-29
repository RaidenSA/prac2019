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
  int getAlreadyVaccinated();
};

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

class Fund
{ private:
  int coffers;
  public:
  Fund(int fundSize);
  int getCoffers();
  void takeTaxes(City&);
  void payAllowance(City&);
  void payment(int);
};

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
  //vector<int> getIllCities();
};



