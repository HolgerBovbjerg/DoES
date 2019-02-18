/**
 * Solutions for Lecture 2
 */

#include <stdio.h>

/**
 * Exercise 2.1
 */

int my_strlen(char *sz) {
   int i;
   for (i=0; sz[i]!='\0'; i++);
   return i;
}

/**
 * Exercise 2.2
 */

char *my_strstr(char *szHaystack,char *szNeedle) {
   int i,j,nHaystackLength,nNeedleLength;
   nNeedleLength=my_strlen(szNeedle);
   nHaystackLength=my_strlen(szHaystack)-nNeedleLength+1; /* We have to reduce the length or we will go outside the string */
   for (j=0; j<nHaystackLength; j++) { /* Traverse the haystack */
      for (i=0; i<nNeedleLength; i++) if (szNeedle[i]!=szHaystack[j+i]) goto not_found; /* Jump out if mismatch */
      return szHaystack+j; /* Return pointer + offset */
      not_found:; /* Not found (yet), continue to walk through the haystack */
   }
   return NULL; /* Needle not found at all! */
}

int main() {
   char szName[]={"Johnny"};
   char szNeedle[]={"nn"};
   char *found;

   /* Test of my_strlen: */
   printf("Length of name is: %d\n",my_strlen(szName));

   /* Test of my_strstr: */
   found=my_strstr(szName,szNeedle);
   if (found) printf("Needle found at position: %d\n",(int)(found-szName));
   else printf("Cannot find the needle!\n");

   return 0;
}
