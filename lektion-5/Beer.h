typedef struct Beer{
   char type[81]; /* Type of beer - max of 80 letters */
   float price;   /* Price */
   float alc;     /* Percentage */
   float ml;      /* Amount milliliter [ml] */
   struct Beer *next; /* Pointer to next element in linked list */
}Beer;

Beer *addBeer( Beer *beer);
void deleteBeer(Beer *beer);
void seeBeers(Beer *beer);
Beer *deleteSpecificBeer(Beer *beer, char type[81]);
int noOfBeers();
void saveBeers(Beer *beer);
Beer *importBeers(Beer *beer);
