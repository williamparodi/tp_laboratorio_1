#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "utn.h"
#include "parser.h"
#include "Controller.h"
#include "menu.h"

#define BUFFER 1000
#define ACTIVO 1
#define CANCELADO 2
#define DEMORADO 3
#define PRIMERA  1
#define EJECUTIVO 2
#define TURISTA 3

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int itsOk = -1;

	FILE* pFile;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile=fopen(path,"r");
	}

	if(pFile != NULL)
	{
		if(!parser_PassengerFromText(pFile,pArrayListPassenger))
		{
			itsOk = 0;
		}
	}
	fclose(pFile);
	return itsOk;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int itsOk = -1;
	FILE* pFile;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile= fopen(path,"rb");
	}
	if(pFile != NULL)
	{
		if(!parser_PassengerFromBinary(pFile,pArrayListPassenger))
		{
			itsOk = 0;
		}
	}
	fclose(pFile);

	return itsOk;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int itsOk = -1;

	if(pArrayListPassenger != NULL)
	{
		if(!Passenger_addPassenger(pArrayListPassenger))
		{
			itsOk = 0;
		}
	}

	return itsOk;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{

	int itsOk = -1;
	if(pArrayListPassenger != NULL)
	{
		if(!Passenger_modPassenger(pArrayListPassenger))
		{
			itsOk=0;
		}
	}
	return itsOk;
}


/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int itsOk = -1;

	if(pArrayListPassenger != NULL)
	{
		if(!Passenger_removePassenger(pArrayListPassenger))
		{
			itsOk = 0;
		}
	}
	return itsOk;
}


/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int itsOk = -1;
	int len;
	Passenger* auxPassenger;
	if(pArrayListPassenger != NULL)
	{
		len=ll_len(pArrayListPassenger);
		printf("--------------------------------------Lista de pasajeros----------------------------------------\n");
		printf("Id   Nombre   	     Apellido       Precio     Codigo de Vuelo    Clase         Estado de vuelo \n");
		printf("------------------------------------------------------------------------------------------------\n");
		for(int i=0;i<len;i++)
		{
			auxPassenger = ll_get(pArrayListPassenger,i);
			if(auxPassenger != NULL)
			{
				Passenger_printOneWith(auxPassenger);
			}
		}
		itsOk = 0;
	}
    return itsOk;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int itsOk = -1;
	int order;
	int option;
	if(pArrayListPassenger != NULL)
	{
		printf("Ordenar Pasajeros\n");
		if(!utn_getInt(&order,"Eliga Orden : 1 Ascendente, 2 Descendente ","Error,opcion incorrecta",1,2,5))
		{
			if(order == 2)
			{
				order = 0;
			}
			if(!utn_getInt(&option,"Elija una opcion: 1-Ordenar por Precio o 2-Ordenar por Nombre\n","Opcion invalida\n",1,2,5))
			{
				switch(option)
				{
				case 1:
					ll_sort(pArrayListPassenger,Passenger_orderByPrecio,order);
					break;
				case 2:
					ll_sort(pArrayListPassenger,Passenger_orderByName,order);
					break;
				default:
					printf("Opcion invalida\n");
					break;
				}
			}
			itsOk = 0;
		}
	}
    return itsOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int itsOk = -1;
	int len;
	int auxId;
	char auxNombre[BUFFER];
	char auxApellido[BUFFER];
	float auxPrecio;
	int tipoDePasajero;
	char auxCodigoVuelo[BUFFER];
	int estadoVuelo;
	char auxEstadoVuelo[BUFFER];
	char auxTipoDePasajero[BUFFER];
	Passenger* auxPassenger;

	FILE* pFile;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile=fopen(path,"w");
	}

	if(pFile != NULL)
	{

		len = ll_len(pArrayListPassenger);
		fprintf(pFile,"id,Nombre,Apellido,Precio,Codigo,Clase,Estado\n");
		for(int i= 0;i<len;i++)
		{
			auxPassenger = ll_get(pArrayListPassenger,i);
			if(!Passenger_getId(auxPassenger,&auxId)&&
					!Passenger_getNombre(auxPassenger, auxNombre)&&
					!Passenger_getApellido(auxPassenger, auxApellido)&&
					!Passenger_getPrecio(auxPassenger,&auxPrecio) &&
					!Passenger_getTipoPasajero(auxPassenger,&tipoDePasajero) &&
					!Passenger_getCodigoVuelo(auxPassenger, auxCodigoVuelo) &&
					!Passenger_getEstadoVuelo(auxPassenger,&estadoVuelo))
			{
				switch(tipoDePasajero)
				{
				case PRIMERA:
					strcpy(auxTipoDePasajero,"PRIMERA");
					break;
				case EJECUTIVO:
					strcpy(auxTipoDePasajero,"EJECUTIVO");
					break;
				case TURISTA:
					strcpy(auxTipoDePasajero,"TURISTA");
					break;
				}

				switch(estadoVuelo)
				{
				case ACTIVO:
					strcpy(auxEstadoVuelo,"ACTIVO");
					break;
				case DEMORADO:
					strcpy(auxEstadoVuelo,"DEMORADO");
					break;
				case CANCELADO:
					strcpy(auxEstadoVuelo,"CANCELADO");
					break;
				}

				fprintf(pFile,"%d,%s,%s,%.2f,%s,%s,%s\n",auxId,auxNombre,auxApellido,auxPrecio,auxCodigoVuelo,auxTipoDePasajero,auxEstadoVuelo);
			}
		}
		itsOk = 0;
	}
	fclose(pFile);

	return itsOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int itsOk = -1;
	int len;
	Passenger* auxPassenger;
	FILE* pFile = fopen(path,"wb");

	if(pFile != NULL)
	{
		len = ll_len(pArrayListPassenger);

		for(int i=0;i<len;i++)
		{
			auxPassenger = ll_get(pArrayListPassenger,i);
			if(auxPassenger != NULL)
			{
				fwrite(auxPassenger,sizeof(Passenger),1,pFile);
			}
			itsOk = 0;
		}
	}
	fclose(pFile);

	return itsOk;
}

