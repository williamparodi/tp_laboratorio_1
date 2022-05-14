
#ifndef INFORMES_H_
#define INFORMES_H_
/**\brief Sort the elements in the array of passengers, the criteria is alphabetical order
 * (form z - a) and if are the same, the order will be by numerical order(more -less)
 * @param list
 * @param len
 * @return  int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortByLastNameAndTypeDown(Passenger list[],int len);

/***
 * brief Sort the elements in the array of passengers, the criteria is alphabetical order
 * (form a - z) and if are the same, the order will be by numerical order(less - more)
 * @param list
 * @param len
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortByLastNameAndTypeUp(Passenger list[],int len);
/***
 * brief print only the passenger with status flight Activo
 * @param list
 * @param length
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int printPassengersByCodeaAndActive(Passenger* list, int length);
/***
 * Accumulate the price of the array list
 * @param list
 * @param len
 * @param pAccumulator
 * @return 1 ok 0 error
 */
int accumulatePrice(Passenger list[],int len,float* pAccumulator);

/***
 * brief Calculates average price
 * @param accumulator
 * @param count
 * @param pAverage
 * @return  1 ok 0 error
 */
float calculateAveragePrice(float accumulator,int count,float *pAverage);

/***
 * brief Calculates above average price
 * @param list
 * @param len
 * @param average
 * @param pCountAbovePrice
 * @return
 */
float calculateAboveAveragePrice(Passenger list[],int len,float average,int* pCountAbovePrice);

/***
 * print all the results of total price.
 * @param totalPrice
 * @param average
 * @param countAbovePrice
 */
void printPriceAverageTotal(float totalPrice, float averagePrice, int countAboveAverage);

/***
 * brief count Passenger
 * @param list
 * @param len
 * @return 0 if is not passengers or the count of the passengers
 */
int countPassengers(Passenger list[],int len);

#endif /* INFORMES_H_ */
