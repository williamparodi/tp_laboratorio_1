/*
 * informes.h
 *
 *  Created on: 14 may. 2022
 *      Author: Willy
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int sortByLastNameAndTypeDown(Passenger list[],int len);
int sortByLastNameAndTypeUp(Passenger list[],int len);
int accumulatePrice(Passenger list[],int len,float* pAccumulator);
float calculateAveragePrice(float accumulator,int count,float *pAverage);
float calculateAboveAveragePrice(Passenger list[],int len,float average,int* pCountAboveSalary);
void printPriceAverageTotal(float totalSalary, float averageSalary, int countAboveAverage);
int countPassengers(Passenger list[],int len);

#endif /* INFORMES_H_ */
