#include <stdio.h>
#include <stdlib.h>
#include "beersim.h"
#include <time.h>

int menu() {
   int nSelection; /*Menu element selection variable*/
   printf("What do you want to do?:\n");       /*Print options */
   printf("1) Play game\n");
   printf("2) Calculate average beer price\n");
   printf("3) Stop program\n");
   scanf("%d",&nSelection); /*Look for choice */
   return nSelection; /* Return choice */
}

int main() {
    int priceAvg;
    /* Intializes random number generator */
    srand ( time(NULL) );
    while (1) {
        switch (menu()) {
            case 1:
                playGame();
                break;
            case 2:
                priceAvg = avgPrice();
                printf("Avg price is: %d \n", priceAvg);
                if (priceAvg > 14) {
                    printf("It is cheaper just to buy the beer.\n");
                }
                else {
                    printf("Let's play!\n");
                };
                break;
            case 3:
                goto End;
        }
    }
    End:
    return 0;
}

