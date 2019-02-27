/**
 * Solutions for Lecture 3
 */

#include <stdio.h>

#include "Beer.h"

/**
 * We have added to menu: Remove beer
 */

int menu() {
   int nSelection;
   printf("Options:\n");
   printf("1) Add new beer\n");
   printf("2) Remove beer\n");
   printf("3) See all beers\n");
   printf("4) Stop program\n");
   scanf("%d",&nSelection);
   return nSelection;
}

/**
 * We have added to main: Remove beer and which one to remove
 */

int main() {
   struct Beer *beer;
   char szType[81];
   int nSelection=0;
   beer=NULL;
   while (nSelection!=4) {
      nSelection=menu();
      if (nSelection==1) beer=addBeer(beer);
      else if (nSelection==2) {
         printf("Which beer do you wanna remove? ");
         scanf("%s",szType);
         beer=removeBeer(beer,szType);
      }
      else if (nSelection==3) seeBeers(beer);
   }
   return 0;
}

