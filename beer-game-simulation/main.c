#include <stdio.h>
#include <stdlib.h>
#include "beersim.h"
#include <time.h>

int menu() {
   int nSelection; /*Menu element selection variable*/
   printf("Please choose what you want to do:\n");       /*Print options */
   printf("1) Play game?\n");
   printf("2) Calculate average beer price, and get advice?\n");
   printf("3) Stop program?\n");
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
                if (priceAvg > 10) {
                    printf("It is cheaper just to buy the beer.\n");
                }
                else if (priceAvg == 10)
                    {
                    printf("Same price, but maybe you're lucky.\n");
                }
                else {
                    printf("Go for it. Let's play!\n");
                };
                break;
            case 3:
                goto End;
        }
    }
    End:
    return 0;
}

