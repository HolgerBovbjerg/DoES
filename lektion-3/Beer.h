/** Beer
 *  \brief A typedef for struct Beer.
 *
 *  Definition of type Beer with price, alcohol content, size and pointer to next node.
 */
typedef struct Beer{
   char type[81]; /**< type of beer - max of 80 letters. */
   float price;   /**< Price. */
   float alc;     /**< Percentage. */
   float ml;      /**< Amount milliliter [ml]. */
   struct Beer *next; /** Pointer to next element in linked list. */
}Beer;

Beer *addBeer( Beer *beer); /**< Constructor for addBeer function.*/
void deleteBeer(Beer *beer);/**< constructor for deleteBeer function. */
void seeBeers(Beer *beer);/**< Constructor for seeBeers function. */
Beer *deleteSpecificBeer(Beer *beer, char type[81]);/**< Constructor for deleteSpecificBeer function. */
int noOfBeers(); /**< Constructor for noOfBeers function.*/

