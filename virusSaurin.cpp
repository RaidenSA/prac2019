#include "virusSaurin.h"
// piechart
////SickCounter
  
  SickCounter::SickCounter()
  {
    for (int i=0; i<4; i++)
      sick[i]=0;
  }; 

  int SickCounter::cure()
  {
    int cured = sick[3]; //Process how people cure
    sick[3]=sick[2];
    sick[2]=sick[1];
    sick[1]=sick[0];
    sick[0]=0;
    return cured; //Returns number of cured people
  };

  int SickCounter::allSick()
  {
    return (sick[0]+sick[1]+sick[2]
                + sick[3]);//Returns number of all sick. Is needed for GUI
  };

  void SickCounter::becomeSick(int currSick)
  {
    sick[0] += currSick*15/100; // Need to make percentage somehow later
    sick[1] += currSick*60/100;
    currSick -= currSick*75/100;
    sick[2] += currSick;
  };

/////HealthyCounter

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
    int sick = (healthy - vaccinated[2]) / 5;
    if (sick<=0) sick=0;
    healthy = healthy - sick;
    vaccinated[1] -= vaccinated[1] / 5;
    vaccinated[0] -= vaccinated[0] / 5;
    return sick; 
  };

  int HealthyCounter::getAlreadyVaccinated()
  {
    return vaccinated[2];
  };

/////City 

  City::City()
  {
    cityType = 1+rand()%3;
    well.healthy = cityType*1000;
    funds = 0;
    taxes = 0;
    vaccinationCost =1;
    allowance = 0;
  };

  void City::epidemicDevelopment() //Main function for making well and ill, payments.For 1tic
  {
    well.healthy += deseased.cure();//People get cured
    payment(); //We pay allowance and collect taxes
    int currSick = well.getIll(); //People get ill
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
    allowance = deseased.allSick()*3;
    taxes = well.healthy*65/100*3;
  };

//////Fund

  Fund::Fund(int fundSize)
  {
    coffers = fundSize;
  };

  int Fund::getCoffers()
  {
    return(coffers);
  };

  void Fund::takeTaxes(City &cities)
  {
    coffers += cities.taxes;
    cities.taxes = 0; 
  };

  void Fund::payAllowance(City &cities)
  {
    coffers -=cities.allowance;
    cities.allowance = 0; 
  };
  void Fund::payment(int funds)
  {
    coffers -= funds;
  };

//Country

  Country::Country(int cityCounter, int fundSize, int mounth):stock(fundSize)
  {
    numberOfCities = cityCounter;
    vector<City> cities1;
    for (int i = 0; i < numberOfCities; i++)
    {
      cities1.push_back(City());
    };
    cities = cities1;
    threshold = 50;
	mounth = mounth;
  };

  int Country::step()
  {
	if(mounth > 0){
		timeFloat();
		mounth--;
		return 1;
	}
	return 0;
  }

  void Country::timeFloat() // 1 step of simulation
  {
    for (int i=0; i<numberOfCities; i++) //loop for every city
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
     // Here check if coffers is > 0
     // And desision about vaccination
    for (int i=0; i<numberOfCities; i++) //loop for every city
    {
      cities[i].epidemicDevelopment(); 
      
    };
    for (int i=0; i<numberOfCities; i++) //loop for every city
    {
      stock.takeTaxes(cities[i]);
    };
    
    //At this point the step is finished and we are redy to display information
  }
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


