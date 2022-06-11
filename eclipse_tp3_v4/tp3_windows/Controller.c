#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "utn.h"
#include "parser.h"
#include "Controller.h"
#include "menu.h"

#define LIMITE_NOMBRE 50
#define LIMITE_CODIGO 10
#define LIMITE_ID 10
#define BUFFER 1000
int static incrementaId()
{
	static int id = 1;
	id++;
	return id;
}
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
	Passenger* newPassenger=NULL;
	int itsOk = -1;
	int auxid = 0;
	char auxNombre[1000];
	char auxApellido[1000];
	float auxPrecio;
	char auxCodigo[1000];
	int auxTipo;
	int auxEstado;

	if(pArrayListPassenger != NULL)
	{
		if(!utn_getNombreCompleto(auxNombre,"Ingrese nombre del pasajero:\n","Error,solo letras\n",LIMITE_NOMBRE,5)&&
				!utn_getNombreCompleto(auxApellido,"Ingrese apellido del pasajero:\n","Error,solo letras\n",LIMITE_NOMBRE,5)&&
				!utn_getFloat(&auxPrecio,"Ingrese Precio de Vuelo:\n","Error, solo precios mayores a 1000 y menores a 10 millon\n",1000,10000000,5)&&
				!utn_getFlyCode(auxCodigo,"Ingrese el codigo de vuelo:\n",
						"Error,el codigo tiene 3 letras iniciales y hasta 4 numeros(Ejemplo ARD0013)\n",LIMITE_CODIGO,5) &&
						!utn_getInt(&auxTipo,
								"Ingrese la clase:\n "
								"1-Primera clase\n "
								"2-Ejecutivo\n "
								"3-Turista\n",
								"Error,clase incorrecta",1,3,5) &&
								!utn_getInt(&auxEstado,
										"Ingrese estado de vuelo:\n "
										"1-ACTIVO\n "
										"2-DEMORADO\n "
										"3-CANCELADO\n","Error,estado erroneo\n",1,3,5))
		{
			auxid = incrementaId();
			newPassenger = Passenger_newParametros(auxid, auxNombre, auxApellido, auxPrecio, auxTipo, auxCodigo,auxEstado);
		}
		if(newPassenger != NULL)
		{
			ll_add(pArrayListPassenger,newPassenger);
			itsOk=0;
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
	int opcion;
	int id;
	char auxNombre[1000];
	char auxApellido[1000];
	float auxPrecio;
	char auxCodigoVuelo[1000];
	int auxTipoPasajero;
	Passenger* auxPassenger;

	if(pArrayListPassenger != NULL)
	{
		printf("--------Modificar Pasajero ----------\n");
		printf("Id  Nombre  Apellido  Precio   Codigo de vuelo  Clase\n");
		controller_ListPassenger(pArrayListPassenger);
		if(!utn_getInt(&id,"\nIngrese el id del pasajero a Modificar:\n","Error,id incorrecto\n",1,5000,5))
		{
			auxPassenger = Passenger_searchPassengerById(pArrayListPassenger,id);
			if(auxPassenger != NULL)
			{
				itsOk=0;
				Passenger_showOnePassenger(auxPassenger);
				do
				{
					menuModificarPasajero();
					if(!utn_getInt(&opcion,"Que campo desea modificar?\n",
							"Error,opcion incorrecta\n",1,6,5))
					{
						switch(opcion)
						{
						case 1:
							if(!utn_getNombreCompleto(auxNombre,"Ingrese el nombre nuevo:\n","Error,solo letras\n",50,5))
							{
								Passenger_setNombre(auxPassenger,auxNombre);
								printf("Nombre modificado\n");
							}
							else
							{
								printf("Error al modificar nombre\n");
							}
							break;
						case 2:
							if(!utn_getNombreCompleto(auxApellido,"Ingrese el apellido nuevo:\n","Error,solo letras\n",50,5))
							{
								Passenger_setApellido(auxPassenger,auxApellido);
								printf("Apellido modificado\n");
							}
							else
							{
								printf("Error al modificar\n");
							}
							break;
						case 3:
							if(!utn_getFloat(&auxPrecio,"Ingrese el nuevo precio:\n",
									"Error,precios mayores a 1000 y menores a 10 millones",1000,10000000,5))
							{
								Passenger_setPrecio(auxPassenger,auxPrecio);
								printf("Precio modificado\n");
							}
							else
							{
								printf("Error al  modificar\n");
							}
							break;
						case 4:
							if(!utn_getInt(&auxTipoPasajero,
									"Ingrese la nueva clase:\n "
									"1-Primera clase\n "
									"2-Ejecutivo\n "
									"3-Turista\n",
									"Error,clase incorrecta",1,3,5))
							{
								Passenger_setTipoPasajero(auxPassenger,auxTipoPasajero);
								printf("Clase modificada\n");
							}
							else
							{
								printf("Error al modificar\n");
							}
							break;
						case 5:
							if(!utn_getFlyCode(auxCodigoVuelo,"Ingrese el nuevo codigo de vuelo:\n",
									"Error,el codigo tiene 3 letras iniciales y hasta 4 numeros(Ejemplo ARD0013)\n",LIMITE_CODIGO,5))
							{
								Passenger_setCodigoVuelo(auxPassenger, auxCodigoVuelo);
								printf("Codigo de Vuelo modificado\n");
							}
							else
							{
								printf("Error al modificar\n");
							}
							break;

						case 6:
							printf("Se vuelve al menu principal\n");
							break;
						}
					}

				}while(opcion != 6);
			}
			else
			{
				printf("Id incorrecto\n");
			}
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
	int index;
	int opcion;
	int id;
	Passenger* auxPassenger = NULL;

	if(pArrayListPassenger != NULL)
	{
		printf("-----------------------------Baja--de--Pasajero----------------------------------------------------\n");
		printf("Id   Nombre   	      Apellido       Precio     Codigo de Vuelo    Clase         Estado de vuelo   \n");
		printf("---------------------------------------------------------------------------------------------------\n");
		controller_ListPassenger(pArrayListPassenger);
		if(!utn_getInt(&id,"\nIngrese el id del pasajero a borrar:\n","Error,id incorrecto\n",1,5000,5))
		{
			auxPassenger = Passenger_searchPassengerById(pArrayListPassenger,id);
			if(auxPassenger!= NULL)
			{
				printf("Pasajero a Borrar: \n");
				Passenger_showOnePassenger(auxPassenger);
				if(!utn_getInt(&opcion,"Esta seguro que quiere borrar este Pasajero? 1-Si o 2-No\n",
						"Error,opcion incorrecta\n",1,2,5))
				{
					if(opcion ==1)
					{
						index = ll_indexOf(pArrayListPassenger,auxPassenger);
						ll_pop(pArrayListPassenger,index);// o puedo usar remove
						printf("Pasajero borrado\n");
						itsOk=0;
					}
					else
					{
						printf("Baja cancelada\n");
						itsOk=1;
					}
				}
			}
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
	char auxNombre[1000];
	char auxApellido[1000];
	float auxPrecio;
	int auxTipoPasajero;
	char auxCodigoVuelo[1000];
	int auxEstadoVuelo;
	Passenger* auxPassenger;

	FILE* pFile;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile=fopen(path,"w");
	}

	if(pFile != NULL)
	{

		len = ll_len(pArrayListPassenger);

		for(int i= 0;i<len;i++)
		{
			auxPassenger = ll_get(pArrayListPassenger,i);
			if(Passenger_getId(auxPassenger,&auxId)&&
					Passenger_getNombre(auxPassenger, auxNombre)&&
					Passenger_getApellido(auxPassenger, auxApellido)&&
					Passenger_getPrecio(auxPassenger,&auxPrecio) &&
					Passenger_getTipoPasajero(auxPassenger,&auxTipoPasajero) &&
					Passenger_getCodigoVuelo(auxPassenger, auxCodigoVuelo) &&
					Passenger_getEstadoVuelo(auxPassenger,&auxEstadoVuelo))
			{
				fprintf(pFile,"%d,%s,%s,%f,%s,%d,%d\n",auxId,auxNombre,auxApellido,auxPrecio,auxCodigoVuelo,auxTipoPasajero,auxEstadoVuelo);
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

