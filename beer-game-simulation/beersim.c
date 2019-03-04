#include <stdio.h>
#include <stdlib.h>
#include "beersim.h"

int i, j, k;
int numbers[3];
int avg, sumsum;
int sums[100];
int n = 3;

void generateRandomNumbers()
{
    printf("Generating random numbers...\n");

    /* Print 3 random numbers from 0 to 49 */
    for( i = 0 ; i < n ; i++ ) {
        numbers[i] = (rand() % 6) + 1;
        printf("Number %d is: ", i+1);
        printf("%d\n",numbers[i]);
    }
}

int sumNumbers()
{
    printf("Summing numbers...\n");
    int sum = 0;
    for( j = 0 ; j < n ; j++ ) {
      sum = sum + numbers[j];
    }
    printf("Sum is: %d\n",sum);
    return sum;
}

void playGame()
{
    generateRandomNumbers();
    if (numbers[0]==numbers[1] && numbers[1]==numbers[2])
    {
        printf("Free beer!\n");
    }
    else
    {
        sumNumbers();
    }
}

int avgPrice()
{
    avg = 0;
    sumsum = 0;
    int m = 99;
    printf("Finding avg price...\n");
    for (k=0; k < m; k++){
        generateRandomNumbers();
        sums[k] = sumNumbers();
    }

    for (k=0; k < m; k++) {
        sumsum = sumsum + sums[k];
    }
    avg = sumsum/m;
    return avg;
}
