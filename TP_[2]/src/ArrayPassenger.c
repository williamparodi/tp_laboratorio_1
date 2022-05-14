#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "ArrayPassenger.h"
#include "menu.h"
#include "informes.h"
#define VACIO 1
#define LLENO 0
#define PRIMERA  1
#define EJECUTIVO 2
#define TURISTA 3
#define ACTIVO 1
#define CANCELADO 2
#define DEMORADO 3

int static incrementaId()
{
	static int id = 1000;
	id++;
	return id;
}

int initPassengers(Passenger* list, int len)
{
	int itsOk;
	itsOk = -1;

	if(list != NULL && len >0)
	{
		for(int i=0;i<len;i++)
		{
			list[i].isEmpty = VACIO;
		}
		itsOk = 0;
	}
	return itsOk;
}

int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[])
{
	int itsOk;
	int index;
	itsOk=-1;
	Passenger aux;
	if(list != NULL && len > 0)
		{
			index = findEmptyPlace(list,len);
			if(index != -1)
			{
				if(!utn_getNombreCompleto(aux.name,"Ingrese nombre del pasajero:\n","Error,solo letras\n",50,5)&&
					!utn_getNombreCompleto(aux.lastName,"Ingrese apellido del pasajero:\n","Error,solo letras\n",50,5)&&
					!utn_getFloat(&aux.price,"Ingrese Precio de Vuelo:\n","Error, solo precios mayores a 10000\n",1000,1000000,5)&&
					!utn_getFlyCode(aux.flycode,"Ingrese el codigo de vuelo:\n",
							"Error,el codigo tiene 3 letras iniciales y hasta 4 numeros(Ejemplo ARD0013)\n",7,5) &&
					!utn_getInt(&aux.typePassenger,
							"Ingrese la clase:\n "
							"1-Primera clase\n "
							"2-Ejecutivo\n "
							"3-Turista\n",
							"Error,clase incorrecta",1,3,5) &&
					!utn_getInt(&aux.statusFlight,
							"Ingrese estado de vuelo:\n "
							"1-ACTIVO\n "
							"2-DEMORADO\n "
							"3-CANCELADO\n","Error,estado erroneo\n",1,3,5))
				{

					aux.id = incrementaId();
					aux.isEmpty=LLENO;
					list[index] = aux;
					printf("Pasajero:\n");
					printOnePassenger(list[index]);
					itsOk=0;
				}
			}
		}
	return itsOk;
}

int modPassenger(Passenger list[],int len,int id)
{
	int itsOk;
	int index;
	int opcion;
	itsOk = -1;
	if(list != NULL && len >0 && id >0)
	{
		if(isNotEmpty(list,len))
		{
			printf("--------Modificar Empleado ----------\n");
			printf("Id  Nombre  Apellido  Precio   Codigo de vuelo  Clase\n");
			printOnlyAddedPassengers(list,len);
			if(!utn_getInt(&id,"\nIngrese el id del pasajero a Modificar:\n","Error,id incorrecto\n",1000,2000,5))
			{
				index = findPassengerById(list,len,id);
				if(index != -1)
				{
					itsOk=0;
					printOnePassenger(list[index]);
					do
					{
						menuModificarPasajero();
						if(!utn_getInt(&opcion,"Que campo desea modificar?\n",
													"Error,opcion incorrecta\n",1,6,5))
						{
							switch(opcion)
							{
							case 1:
								if(!utn_getNombreCompleto(list[index].name,"Ingrese el nombre nuevo:\n","Error,solo letras\n",50,5))
								{
									printf("Nombre modificado\n");
								}
								else
								{
									printf("Error al modificar nombre\n");
								}
								break;
							case 2:
								if(!utn_getNombreCompleto(list[index].lastName,"Ingrese el apellido nuevo:\n","Error,solo letras\n",50,5))
								{
									printf("Apellido modificado\n");
								}
								else
								{
									printf("Error al modificar\n");
								}
								break;
							case 3:
								if(!utn_getFloat(&list[index].price,"Ingrese el nuevo precio:\n",
										"Error,precios mayores a 1000 y menores a 10 millones",1000,10000000,5))
								{
									printf("Precio modificado\n");
								}
								else
								{
									printf("Error al  modificar\n");
								}
								break;
							case 4:
								if(!utn_getFlyCode(list[index].flycode,"Ingrese el nuevo codigo de vuelo:\n",
										"Error,el codigo tiene 3 letras iniciales y hasta 4 numeros(Ejemplo ARD0013)\n",7,5))
								{
									printf("Codigo de Vuelo modificado\n");
								}
								else
								{
									printf("Error al modificar\n");
								}
								break;
							case 5:
								if(!utn_getInt(&list[index].typePassenger,
										"Ingrese la nueva clase:\n "
										"1-Primera clase\n "
										"2-Ejecutivo\n "
										"3-Turista\n",
										"Error,clase incorrecta",1,3,5))
									{
										printf("Clase modificada\n");
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
	}
	return itsOk;
}


int findPassengerById(Passenger* list, int len,int id)
{
	int itsOk;
	itsOk =-1;
	if(list != NULL && len > 0 && id >0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].id == id && list[i].isEmpty == LLENO)
			{
				itsOk = i;
				break;
			}
		}
	}
	return itsOk;
}

int findEmptyPlace(Passenger* list,int len)
{
	int index;
	index= -1;
	if(list != NULL && len >0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == VACIO)
			{
				index= i;
				break;
			}
		}
	}
	return index;
}

int removePassenger(Passenger* list, int len, int id)
{
	int itsOk;
	int index;
	int opcion;
	itsOk = -1;
	if(list != NULL && len >0 && id >0)
	{
		if(isNotEmpty(list,len))
		{
			printf("-----------------------------Baja--de--Pasajero----------------------------------------------------\n");
			printf("Id   Nombre   	      Apellido       Precio     Codigo de Vuelo    Clase         Estado de vuelo \n");
			printf("-------------------------------------------------------------------------------------------------\n");
			printOnlyAddedPassengers(list,len);
			if(!utn_getInt(&id,"\nIngrese el id del pasajero a borrar:\n","Error,id incorrecto\n",1000,2000,5))
			{
				index = findPassengerById(list,len,id);
				if(index != -1)
				{
					utn_getInt(&opcion,"Esta seguro que quiere borrar este Pasajero? 1-Si o 2-No\n",
							"Error,opcion incorrecta\n",1,2,5);
					printOnePassenger(list[index]);
					if(opcion ==1)
					{
						list[index].isEmpty = 1;
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

void printOnePassenger(Passenger onePassenger)
{
	char auxType[50];
	char auxStatus[50];
	switch(onePassenger.typePassenger)
	{
		case PRIMERA:
			strcpy(auxType,"PRIMERA");
			break;
		case EJECUTIVO:
			strcpy(auxType,"EJECUTIVO");
			break;
		case TURISTA:
			strcpy(auxType,"TURISTA");
			break;
	}
	switch(onePassenger.statusFlight)
	{
		case ACTIVO:
			strcpy(auxStatus,"ACTIVO");
			break;
		case DEMORADO:
			strcpy(auxStatus,"DEMORADO");
			break;
		case CANCELADO:
			strcpy(auxStatus,"CANCELADO");
			break;
	}
	printf("%d %-15s  %-10s    %-5.2f    %-15s    %-15s    %-8s\n",
			onePassenger.id,onePassenger.name,
			onePassenger.lastName,
			onePassenger.price,
			onePassenger.flycode,
			auxType,
			auxStatus);
}

int printPassengers(Passenger* list, int length)
{
	int itsOk;
	itsOk= -1;
	if(list != NULL && length >0)
	{
		printf("------------------------------------Pasajeros----------------------------------------------------\n");
		printf("Id   Nombre   	      Apellido       Precio     Codigo de Vuelo    Clase         Estado de vuelo \n");
		printf("-------------------------------------------------------------------------------------------------\n");
		for(int i=0;i<length;i++)
		{
			if(list[i].isEmpty==LLENO)
			{
				printOnePassenger(list[i]);
			}
		}
		itsOk=0;

	}
	return itsOk;
}

int isNotEmpty(Passenger list[],int len)
{
	int itsOk;
	itsOk = 0;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == LLENO)
			{
				itsOk = 1;
				break;
			}
		}
	}
	return itsOk;
}

int printOnlyAddedPassengers(Passenger list[],int len)
{
	int itsOk;
	itsOk=-1;
	if(list != NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty==LLENO)
			{
				printOnePassenger(list[i]);
			}
		}
		itsOk=0;
	}
	return itsOk;
}

int sortPassengers(Passenger* list, int len, int order)
{
	int itsOk;
	itsOk=-1;

	if(list != NULL && len >0)
	{
		if(isNotEmpty(list,len))
		{
			if(!utn_getInt(&order,"Ingrese orden por apellido: 1-Ascendente o 2- Descendente\n","Error,opcion invalida\n",1,2,5))
			{
				if(order==2)
				{
					sortByLastNameAndTypeDown(list,len);
				}
				else
				{
					sortByLastNameAndTypeUp(list,len);
				}
				itsOk=0;
			}
		}
	}
	return itsOk;
}

int cargaForzada(Passenger list[],int len,Passenger listaForzada[],int lenForzado)
{
	int itsOk;
	int index;
	itsOk= -1;

	if(listaForzada != NULL && len > 0 && list != NULL && lenForzado)
	{
		index=findEmptyPlace(list, len);
		if(index != -1)
		{
			for(int i=0;i<lenForzado && i<len;i++)
			{
				list[i].id = incrementaId();
				list[i]= listaForzada[i];
				list[i].isEmpty = LLENO;
				printOnePassenger(list[i]);
			}
			itsOk = 0;
		}
	}
	return itsOk;
}

int sortPassengersBycode(Passenger* list, int len, int order)
{
	int itsOk;
	itsOk=-1;
	if(list != NULL && len >0)
	{
		if(isNotEmpty(list,len))
		{
			if(!utn_getInt(&order,"Ingrese orden por codigo: 1-Ascendente o 2- Descendente\n","Error,opcion invalida\n",1,2,5))
			{
				if(order==2)
				{
					sortByCodeAndStatusDown(list, len);
				}
				else
				{
					sortByCodeAndStatusUp(list,len);
				}
				itsOk=0;
			}
		}
	}
	return itsOk;
}

int sortByCodeAndStatusDown(Passenger list[],int len)
{
	int itsOk;
	int ordenOk;
	itsOk=-1;
	Passenger aux;

	if (list != NULL && len > 0)
	{
		do
		{
			ordenOk = 1;
			len--;
			for (int i=0;i<len;i++)
			{
				if(strcmp(list[i].flycode,list[i + 1].flycode)< 0)
				{
					aux = list[i];
					list[i] = list[i + 1];
					list[i + 1] = aux;
					ordenOk = 0;
				}
				else
				{
					if(strcmp(list[i].flycode,list[i + 1].flycode)==0
							&& (list[i].typePassenger
									< list[i + 1].typePassenger))
					{
						aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = aux;
						ordenOk = 0;
					}
				}
			}
		}while(ordenOk== 0);
		itsOk = 0;
	}
	return itsOk;
}

int sortByCodeAndStatusUp(Passenger list[],int len)
{
	int itsOk;
	int ordenOk;
	itsOk=-1;
	Passenger aux;

	if (list != NULL && len > 0)
	{
		do
		{
			ordenOk = 1;
			len--;
			for (int i=0;i<len;i++)
			{
				if(strcmp(list[i].flycode,list[i + 1].flycode)> 0)
				{
					aux = list[i];
					list[i] = list[i + 1];
					list[i + 1] = aux;
					ordenOk = 0;
				}
				else
				{
					if(strcmp(list[i].flycode,list[i + 1].flycode)==0
							&& (list[i].typePassenger
									< list[i + 1].typePassenger))
					{
						aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = aux;
						ordenOk = 0;
					}
				}
			}
		}while(ordenOk== 0);
		itsOk = 0;
	}
	return itsOk;
}

