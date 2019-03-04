#include <stdio.h>
#include "lotto.h"

int num[6];
int i, j, tmp;

void scanNumbers()
{
    printf("Enter the lotto numbers: \n");
    for (i=0; i<7; i++) {
        scanf("%d", &num[i]);
    }
}

void sortNumbers()
{
    for (i=0; i<7; i++) {
        for (j=i+1; j < 7; j++)
        {
            if ( num[i] > num[j])
            {
                tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
        }
    }
    printf("Lotto numbers in ascending order are:  \n");
    for (i = 0; i < 7; ++i) printf("%d\n", num[i]);

}
