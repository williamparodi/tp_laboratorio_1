/*
 * ArrayPassenger.h
 *
 *  Created on: 14 may. 2022
 *      Author: Willy
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}Passenger;

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger* list, int len);

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[]);

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len,int id);

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id);

/**
 * \brief Find an empty space an return the index
 * @param list Passenger
 * @param len int
 * @return int Return (-1) if Error or the index if OK
 */
int findEmptyPlace(Passenger* list,int len);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int len, int order);

/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassengers(Passenger* list, int length);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
\return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int sortPassengersBycode(Passenger* list, int len, int order);

/**\brief Sort the elements in the array of passengers, the criteria is alphabetical order
 * (form z - a) and if are the same, the order will be by numerical order(more -less)
 * @param list
 * @param len
 * @return  int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortByCodeAndStatusDown(Passenger list[],int len);

/***
 * brief Sort the elements in the array of passengers, the criteria is alphabetical order
 * (form a - z) and if are the same, the order will be by numerical order(less - more)
 * @param list
 * @param len
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortByCodeAndStatusUp(Passenger list[],int len);
/***
 * brief print only the added Passenger on the array
 * @param list
 * @param len
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int printOnlyAddedPassengers(Passenger list[],int len);
/***
 * brief print one passenger
 * @param onePassenger
 */
void printOnePassenger(Passenger onePassenger);

/***
 * brief
 * @param list
 * @param len
 * @param listaForzada
 * @param lenForzado
 * @return
 */
int cargaForzada(Passenger list[],int len,Passenger listaForzada[],int lenForzado);

/***
 * brief it gives the option to change the different items of the passenger,
 * it find it by ID
 * @param list
 * @param len
 * @param id
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int modPassenger(Passenger list[],int len,int id);
/***
 * brief Search in the array a place whith data , if it find it, return 1
 * @param list
 * @param len
 * @return int Return (0) or  [Invalid length or NULL pointer] - 1 if it find  Ok
 */
int isNotEmpty(Passenger list[],int len);
#endif /* ARRAYPASSENGER_H_ */
