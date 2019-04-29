#include "virusSaurin.h"
#include <cstdio>
#include <cstdlib>
#include <unistd.h>

int main(int argc, char** argv)
{

 // int n = atoi(argv[1]);
  int n=5;
  Country rus(1);
  srand(time(NULL));
  n *= 4;
  while(n--)
  {
    char clear[5]={27, '[', '2', 'J', 0};
    int ill = rus.getIll();
    int health = rus.getHealthy();
    int sick = (rus.cities[0].well.healthy - rus.cities[0].well.vaccinated[2])/5;
    int vaccinated = rus.cities[0].well.vaccinated[2];
    printf("ill: %d\n", ill);
    printf("healty: %d\n", health);
    printf("sick: %d\n", sick);
    printf("vaccinated: %d\n", vaccinated);
    printf ("%s", clear);
    rus.timeFloat();
    
    usleep(2000000);
  };
  int ill = rus.getIll();
  int health = rus.getHealthy();
  int vaccinated = rus.cities[0].well.vaccinated[2];
  printf("ill: %d\n", ill);
  printf("healty: %d\n", health);
  printf("vaccinated: %d\n", vaccinated);
}
