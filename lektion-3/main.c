#include <stdio.h>

#include "Beer.h"

int menu() {
   int nSelection; /*Menu element selection variable*/
   printf("What do you want to do?:\n");       /*Print options */
   printf("1) Add new beer\n");
   printf("2) See all beers\n");
   printf("3) Delete beer\n");
   printf("4) Stop program\n");
   scanf("%d",&nSelection); /*Look for choice */
   return nSelection; /* Return choice */
}

int main() {
    Beer *beer; /*Create beer struct */
    int nSelection=0; /*Set menu element selcetion variable to zero*/
    while (nSelection!=4) { /*As long as stop program option is not chosen run*/
        nSelection=menu(); /*Run menu function */
        if (nSelection==1) beer=addBeer(beer); /*If choice is 1 run addBeer function */
        else if (nSelection==2) seeBeers(beer); /*If choice is 2 run seeBeers function*/
        else if (nSelection==3) { /*If choice is 3 run deleteBeer function*/
            if (noOfBeers() != 0) deleteBeer(beer); /*If there are beers in the database do */
            else printf("No beers to delete.\n"); /*If there are no beers in database print*/
        }
    }
    return 0;
}

