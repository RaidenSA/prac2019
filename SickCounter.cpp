#include "SickCounter.h"

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
