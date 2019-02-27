#include <stdio.h>

#include "Beer.h"

int menu() {
   int nSelection; /*Menu element selection variable*/
   printf("What do you want to do?:\n");       /*Print options */
   printf("1) Add new beer\n");
   printf("2) See all beers\n");
   printf("3) Delete beer\n");
   printf("4) Save beers to file\n");
   printf("5) Import beers from file\n");
   printf("6) Stop program\n");
   scanf("%d",&nSelection); /*Look for choice */
   return nSelection; /* Return choice */
}

int main() {
    Beer *beer; /*Create beer struct */
    beer=NULL;
    while (1) {
      switch (menu()) {
         case 1:
            beer=addBeer(beer);
            break;
         case 2:
            seeBeers(beer);
            break;
         case 3:
            deleteBeer(beer);
            break;
         case 4:
            saveBeers(beer);
            break;
         case 5:
            beer=importBeers(beer); /* Simple appending */
            break;
         case 6:
            goto End;
      }
   }
   End:
    return 0;
}
