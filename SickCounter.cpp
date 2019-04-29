#include "SickCounter.h"

SickCounter::SickCounter()
{
  for (int i=0; i<4; i++)
    sick[i]=0;
}; 

int SickCounter::cure()
{
  int cured = sick[readyToCure]; //Process how people cure
  sick[readyToCure]=sick[oneWeekToCure];
  sick[oneWeekToCure]=sick[twoWeeksToCure];
  sick[twoWeeksToCure]=sick[threeWeeksToCure];
  sick[threeWeeksToCure]=0;
  return cured; //Returns number of cured people
};

int SickCounter::allSick()
{
  return (sick[threeWeeksToCure]+sick[twoWeeksToCure]+sick[oneWeekToCure]
               + sick[readyToCure]);//Returns number of all sick. Is needed for GUI
};

void SickCounter::becomeSick(int currSick)
{
  sick[threeWeeksToCure] += currSick*15/100; // Need to make percentage somehow later
  sick[twoWeeksToCure] += currSick*60/100;
  currSick -= currSick*75/100;
  sick[oneWeekToCure] += currSick;
};
