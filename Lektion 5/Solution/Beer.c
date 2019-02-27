#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Beer.h"

static int g_nNumberOfBeers=0; /* Made static so it only can be accessed here */
                               /* g_ is for "global" */

struct Beer *addBeer(struct Beer *beer) {
   struct Beer *new_beer;
   /* Allocate space for new element/node: */
   new_beer=(struct Beer *)malloc(sizeof(struct Beer));
   /* Insert new element/beer before any other element: */
   new_beer->next=beer;

   printf("Type: ");
   scanf("%s",new_beer->type);
   printf("Price: ");
   scanf("%f",&new_beer->price);
   printf("Percentage: ");
   scanf("%f",&new_beer->alc);
   printf("Amount [ml]: ");
   scanf("%f",&new_beer->ml);

   g_nNumberOfBeers++; /* We increment since we just added a beer */
   return new_beer;
}

void seeBeers(struct Beer *beer) {
   struct Beer *tmp;
   int i;
   for (i=0; i<g_nNumberOfBeers; i++) {
      tmp=beer->next;
      printf("Type: %s\n",beer->type);
      printf("Price: %f\n",beer->price);
      printf("Percentage: %f\n",beer->alc);
      printf("Amount [ml]: %f\n",beer->ml);
      beer=tmp;
   }
}

struct Beer *removeBeer(struct Beer *beer,char *szID) {
   struct Beer *start,*old;
   int i;
   start=beer; /* Vi gemmer oprindelig entry til listen til senere brug */
   old=NULL; /* Til at starte med antager vi, at der ikke er en tidl. node */
   for (i=0; i<g_nNumberOfBeers; i++) {
      if (!strcmp(szID,beer->type)) { /* Fundet saa derfor slet */
         if (!old) { /* Hovsa! Det var faktisk den foerste node vi ville slette! */
            old=beer->next; /* Vi bruger nu old som den nye foerste node og sparer en variabel */
            free(beer); /* beers naeste er gemt, saa ud med beer */
            g_nNumberOfBeers--;
            return old; /* Entry til listen er aendret saa vi maa returnere denne */
         }
         /* Vi naar kun hertil, hvis vi er et sted inde i listen */
         old->next=beer->next; /* Vi springer over den node der skal slettes */
         free(beer); /* Vi kan nu roligt slette noden, da beer->next er gemt */
         g_nNumberOfBeers--;
         return start; /* Da foerste node ikke matchede, returnerer vi bare den oprindelige entry */
      }
      old=beer; /* Vi gemmer lige den gamle beer */
      beer=beer->next; /* Intet match, saa vi hopper videre til naeste node */
   }
   return start; /* Vi har ikke fundet en bajer der matchede */
}

