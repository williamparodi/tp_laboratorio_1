/*
 ============================================================================
 Name        : TP_[2].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "menu.h"
#include "utn.h"
#include "informes.h"
#define LEN 2000
#define LEN_FORZADO 5

int main(void)
{
	setbuf(stdout,NULL);
	int opcion;
	int idPasajero=1000;
	char name[50];
	char lastName[50];
	float price=0;
	int typePassenger=0;
	char flyCode[7];
	float priceAccumulator=0;
	int count=0;
	float averagePrice;
	int countAbovePrice;
	int order=0;
	Passenger list[LEN];
	Passenger listaForzada[LEN_FORZADO]={
			{1001,"Roberto","Bolaneos",32424.323,"qwe9888",1,2},
			{1002,"Luis Alberto","Benitez",15506.551,"awr1234",2,3},
			{1003,"Mariela Paula","Alvarez",45544.55,"wer3456",3,1},
			{1004,"Juana","Pereyra",15515.56,"plf5678",1,2},
			{1005,"Alan Mauro","Ortuza",98844.323,"qwe9888",3,1}};

	if(initPassengers(list,LEN))
	{
		printf("Error al inciar programa\n");
	}

	do
	{
		menuPassenger();
		if(!utn_getInt(&opcion,"Ingrese una opcion:","Error,opcion invalida\n",1,6,5))
		{
			switch(opcion)
			{
				case 1:
					if(!addPassenger(list,LEN,idPasajero,name,lastName,price,typePassenger,flyCode))
					{
						printf("Carga con exito\n");
					}
					else
					{
						printf("Error al cargar pasajeros\n");
					}
					break;
				case 2:
					if(isNotEmpty(list,LEN))
					{
						if(!modPassenger(list,LEN,idPasajero))
						{
							printf("Modificacion con exito\n");
						}
						else
						{
							printf("Error al modificar\n");
						}
					}
					else
					{
						printf("Primero debe dar de alta Pasajeros\n");
					}
					break;
				case 3:
					if(isNotEmpty(list,LEN))
					{
						if(!removePassenger(list,LEN,idPasajero))
						{
							printf("Baja con exito\n");
						}
						else
						{
							printf("Baja cancelada\n");
						}
					}
					else
					{
						printf("Primero debe dar de alta Pasajeros\n");
					}
					break;
				case 4:
					count=countPassengers(list,LEN);
					if(count)
					{
						sortPassengers(list,LEN,order);
						printPassengers(list,LEN);
						accumulatePrice(list,LEN,&priceAccumulator);
						calculateAveragePrice(priceAccumulator,count,&averagePrice);
						calculateAboveAveragePrice(list,LEN,averagePrice,&countAbovePrice);
						printPriceAverageTotal(priceAccumulator,averagePrice,countAbovePrice);
						sortPassengersBycode(list,LEN,order);
						printPassengersByCodeaAndActive(list,LEN);
					}
					else
					{
						printf("No hay pasajeros cargados\n");
					}
					break;
				case 5:
					if(!cargaForzada(list,LEN,listaForzada,LEN_FORZADO))
					{
						printf("Carga forzada exitosa\n");
					}
					else
					{
						printf("Error al cargar\n");
					}
					break;
				case 6:
					printf("Gracias por utilizar nuestro programa\n");
					break;
			}
		}
	}while(opcion != 6);
	return 0;
}
