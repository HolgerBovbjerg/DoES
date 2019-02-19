#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Beer.h"

static int g_nNumberOfBeers=0; /* Made static so it only can be accessed here */
                               /* g_ is for "global" */

Beer *addBeer(Beer *beer) { /*Adds a beer to database */
   Beer *new_beer; /* Allocate space for new element/node: */
   new_beer=malloc(sizeof(Beer)); /* Insert new element/beer before any other element: */
   new_beer->next=beer; /*Making the next variable of new_beer point to a Beer struct "beer"*/

   printf("Type: ");            /*Asking for information and adding that to new_beer */
   scanf("%s",new_beer->type);
   printf("Price [kr.]: ");
   scanf("%f",&new_beer->price);
   printf("Alcohol Percentage: ");
   scanf("%f",&new_beer->alc);
   printf("Size [ml]: ");
   scanf("%f",&new_beer->ml);

   g_nNumberOfBeers++; /* We increment since we just added a beer */
   return new_beer; /*Returns the new_beer*/
}

void seeBeers(Beer *beer) { /*Iterates through beer database and prints out all info*/
   Beer *tmp; /*Temporary instance of Beer for iterating */
   int i;
   for (i=0; i<g_nNumberOfBeers; i++) { /*For the total number of data entrys do */
      tmp=beer->next; /*Set temporary beer to the beer that current beer node is pointing at */
      printf("Type: %s\n",beer->type);              /*Print out info for current beer node*/
      printf("Price: %f kr.\n",beer->price);
      printf("Percentage: %f percent\n",beer->alc);
      printf("Amount: %f ml\n",beer->ml);
      beer=tmp;    /*Set current beer to the next beer node in linked list (temporary beer) */
   }
}

Beer *deleteSpecificBeer(Beer *beer, char *type) { /*Deletes a specific beer by its type (name)*/
   Beer *start,*old; /*Make start and old pointer of Beer type */
   int i; /*Integer i for iterating through beers */
   start = beer; /*Save first beer node for later use */
   old = NULL; /* Set old beer to "NULL" because there are no earilier nodes at the beginning*/
   for (i=0; i<g_nNumberOfBeers; i++) { /* For every beer node do*/
        if(!strcmp(beer->type, type)) {/*If current beers type is the one we are looking for then (means we have found what we are looking for)*/
            if(!old) { /*Check if we want to delete first node*/
                    old=beer->next; /*Set old (NULL) to first node */
            free(old); /*Free up memory space from old*/
            g_nNumberOfBeers--; /* Decrease number of beers in database by one since we just deleted a beer */
            return old; /* Return old beer because first entry is changed*/
        }
        old->next=beer->next; /* Skipping the node that we want to delete */
        free(beer); /*Free up memory space from beer we deleted */
        g_nNumberOfBeers--; /* Decrease number of beers in database by one since we just deleted a beer */
        return start; /* Return start beer because first entry is not changed */
        }
        old=beer; /* Save old beer*/
        beer=beer->next; /* Set beer to next node in linked list */
   }
   return start; /* Return start beer - no beer matched */
}

void deleteBeer(Beer *beer) { /* Deletes a beer from database */
    char beer_to_delete[81]; /* Variable for name of beer type to delete */
    printf("Which beer do you want to delete (Type)?: \n"); /*Asking for beer type to delete  */
    seeBeers(beer); /* Show options */
    scanf("%s", beer_to_delete); /* User chooses beer type to delete */
    deleteSpecificBeer(beer, beer_to_delete); /* Call delete beer by type function */
//    char yes_no[1];                                                   /*Experiment with user interface for double checking */
//    printf("Do you want to delete this beer: %s? (y/n)\n",beer->type);
//    scanf("%c", yes_no);
//    if (!strcmp(yes_no,"y")) {
//            }
//    else printf("Cancelled deletion");
}

int noOfBeers() { /* Returns no. of beers in database */
    return g_nNumberOfBeers; /* Return no. of beers variable */
}

