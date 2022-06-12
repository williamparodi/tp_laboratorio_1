#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"
#define LIMITE_NOMBRE 100
#define LIMITE_CODIGO 10
#define LIMITE_ID 10
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

Passenger* Passenger_new()
{
	Passenger * newPassenger;
	newPassenger = (Passenger*) malloc(sizeof(Passenger));
	if(newPassenger != NULL)
	{
		return newPassenger;
	}
	else
	{
		return NULL;
	}

}

Passenger* Passenger_newParametrosTxt(char* idStr,char* nombreStr,char* apellidoStr,char* precio,char* codigoVuelo,char* tipoPasajeroStr,char* estadoVuelo)
{
	Passenger * newPassengerParam = NULL;
	newPassengerParam = Passenger_new();
	if(newPassengerParam != NULL)
	{
		Passenger_setIdTxt(newPassengerParam, idStr);
		Passenger_setNombre(newPassengerParam,nombreStr);
		Passenger_setApellido(newPassengerParam,apellidoStr),
		Passenger_setPrecioTxt(newPassengerParam,precio);
		Passenger_setTipoPasajeroTxt(newPassengerParam,tipoPasajeroStr);
		Passenger_setCodigoVuelo(newPassengerParam,codigoVuelo);
		Passenger_setEstadoVueloTxt(newPassengerParam,estadoVuelo);
	}
	return newPassengerParam;
}

void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int Passenger_setId(Passenger* this,int id)
{
	int itsOk = -1;
	if(this!= NULL && id >0)
	{
		this->id= id;
		itsOk = 0;
	}
	return itsOk;
}

int Passenger_getId(Passenger* this,int* id)
{
	int itsOk = -1;
	if(this != NULL && id != NULL && id >0)
	{
		*id = incrementaId();
		*id = this->id;
		itsOk = 0;
	}
	return itsOk;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int itsOk = -1;
	if(this != NULL && nombre != NULL && esLetra(nombre,LIMITE_NOMBRE))
	{
		strcpy(this->nombre,nombre);
		itsOk=0;
	}
	return itsOk;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int itsOk = -1;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		itsOk = 0;
	}
	return itsOk;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int itsOk = -1;
	if(this != NULL && apellido != NULL && esLetra(apellido,LIMITE_NOMBRE))
	{
		strcpy(this->apellido,apellido);
		itsOk=0;
	}
	return itsOk;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int itsOk = -1;
	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido,this->apellido);
		itsOk=0;
	}
	return itsOk;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int itsOk = -1;
	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		itsOk=0;
	}
	return itsOk;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int itsOk = -1;
	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		itsOk=0;
	}
	return itsOk;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int itsOk = -1;
	if(this != NULL)
	{
		this->tipoPasajero = tipoPasajero;
		itsOk=0;
	}
	return itsOk;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int itsOk = -1;
	if(this != NULL && tipoPasajero != NULL && tipoPasajero >0)
	{
		*tipoPasajero = this->tipoPasajero;
		itsOk=0;
	}
	return itsOk;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int itsOk = -1;
	if(this != NULL)
	{
		this->precio = precio;
		itsOk=0;
	}
	return itsOk;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int itsOk = -1;
	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		itsOk=0;
	}
	return itsOk;
}

int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo)
{
	int itsOk = -1;
	if(this != NULL)
	{
		this->estadoVuelo = estadoVuelo;
		itsOk=0;
	}
	return itsOk;
}

int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo)
{
	int itsOk = -1;
	if(this != NULL && estadoVuelo != NULL)
	{
		*estadoVuelo = this->estadoVuelo;
		itsOk=0;
	}
	return itsOk;
}

//Setter Txt

int Passenger_setIdTxt(Passenger* this,char* id)
{
	int itsOk = -1;
	if(this != NULL && id != NULL && esNumero(id,2000))
	{
		this->id= atoi(id);
		itsOk=0;
	}
	return itsOk;
}

int Passenger_setPrecioTxt(Passenger* this,char* precio)
{
	int itsOk = -1;
	if(this != NULL && precio != NULL && esFloat(precio,2000))
	{
		this->precio= atof(precio);
		itsOk=0;
	}
	return itsOk;
}

int Passenger_setTipoPasajeroTxt(Passenger* this,char* tipoPasajero)
{
	int itsOk = -1;
	int auxTipo;
	if(this != NULL && tipoPasajero != NULL)
	{
		auxTipo = Passenger_tomaDeDatoTipo(tipoPasajero);
		this->tipoPasajero= auxTipo;
		itsOk=0;
	}
	return itsOk;
}

int Passenger_setEstadoVueloTxt(Passenger* this,char* estadoVuelo)
{
	int itsOk = -1;
	int auxEstado;
	if(this != NULL && estadoVuelo != NULL)
	{
		auxEstado = Passenger_tomaDeDatoEstado(estadoVuelo);
		this->estadoVuelo = auxEstado;
		itsOk=0;
	}
	return itsOk;
}

int Passenger_showOnePassenger(Passenger* pOnePassenger)
{
	int itsOk = -1;
	int auxId;
	char auxNombre[1000];
	char auxApellido[1000];
	float auxPrecio;
	int auxTipoDePasajero;
	char auxCodigoDeVuelo[1000];
	int auxEstadoVuelo;

	if(pOnePassenger != NULL &&
			!Passenger_getId(pOnePassenger,&auxId) &&
			!Passenger_getNombre(pOnePassenger,auxNombre) &&
			!Passenger_getApellido(pOnePassenger,auxApellido) &&
			!Passenger_getPrecio(pOnePassenger,&auxPrecio) &&
			!Passenger_getTipoPasajero(pOnePassenger,&auxTipoDePasajero) &&
			!Passenger_getCodigoVuelo(pOnePassenger,auxCodigoDeVuelo) &&
			!Passenger_getEstadoVuelo(pOnePassenger,&auxEstadoVuelo))
	{
		printf("%d,%s,%s,%.2f,%s,%d,%d\n",
						auxId,auxNombre,auxApellido,auxPrecio,auxCodigoDeVuelo,auxTipoDePasajero,auxEstadoVuelo);

		itsOk = 0;
	}
	return itsOk;
}

int Passenger_printOneWith(Passenger* pOnePassenger)
{
	int itsOk = -1;
	int auxId;
	char auxNombre[1000];
	char auxApellido[1000];
	float auxPrecio;
	int tipoDePasajero;
	char auxCodigoDeVuelo[1000];
	int estadoVuelo;
	char auxTipoDePasajero[1000];
	char auxEstadoVuelo[1000];
	if(pOnePassenger != NULL &&
			!Passenger_getId(pOnePassenger,&auxId) &&
			!Passenger_getNombre(pOnePassenger,auxNombre) &&
			!Passenger_getApellido(pOnePassenger,auxApellido) &&
			!Passenger_getPrecio(pOnePassenger,&auxPrecio) &&
			!Passenger_getTipoPasajero(pOnePassenger,&tipoDePasajero) &&
			!Passenger_getCodigoVuelo(pOnePassenger,auxCodigoDeVuelo) &&
			!Passenger_getEstadoVuelo(pOnePassenger,&estadoVuelo))
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
		printf("%d %-15s  %-10s    %-5.f    %-15s    %-15s    %-8s\n",
				auxId,auxNombre,auxApellido,
				auxPrecio,
				auxCodigoDeVuelo,
				auxTipoDePasajero,
				auxEstadoVuelo);
		itsOk=0;
	}
	return itsOk;
}

int Passenger_showListPassenger(Passenger** arrayPassenger,int len)
{
	int itsOk = -1;
	if(arrayPassenger != NULL && len >0)
	{
		for(int i=0;i < len;i++)
		{
			Passenger_showOnePassenger(*(arrayPassenger + i));
		}
		itsOk = 0;
	}
	return itsOk;
}


Passenger* Passenger_newParametros(int id,char* nombre,char* apellido,float precio,int tipoPasajero,char* codigoVuelo,int estadoVuelo)
{
	Passenger * newPassengerParam=NULL;
	newPassengerParam = Passenger_new();
	if(newPassengerParam != NULL)
	{
		Passenger_setId(newPassengerParam,id);
		Passenger_setNombre(newPassengerParam,nombre);
		Passenger_setApellido(newPassengerParam,apellido);
		Passenger_setPrecio(newPassengerParam,precio);
		Passenger_setTipoPasajero(newPassengerParam,tipoPasajero);
		Passenger_setCodigoVuelo(newPassengerParam,codigoVuelo);
		Passenger_setEstadoVuelo(newPassengerParam,estadoVuelo);
	}
	return newPassengerParam;
}



Passenger* Passenger_searchPassengerById(LinkedList* arrayPassenger,int idIngresado)
{
	Passenger* auxPassenger=NULL;
	Passenger* retorno;
	int auxId;
	int len;
	if(arrayPassenger != NULL && idIngresado >0)
	{
		len= ll_len(arrayPassenger);
		for(int i=0;i<len;i++)
		{
			auxPassenger= ll_get(arrayPassenger,i);
			Passenger_getId(auxPassenger,&auxId);
			if(idIngresado == auxId && auxPassenger != NULL)
			{
				retorno = auxPassenger;
				break;
			}
		}
	}
	return retorno;
}

int Passenger_orderByName(void* passenger1,void* passenger2)
{
	int retorno;
	char auxNombre1[1000];
	char auxNombre2[1000];

	if(passenger1 != NULL && passenger2 != NULL)
	{
		Passenger_getNombre(passenger1,auxNombre1);
		Passenger_getNombre(passenger2,auxNombre2);
        retorno = stricmp(auxNombre1,auxNombre2);
	}
	return retorno;
}

int Passenger_orderByPrecio(void* passenger1,void* passenger2)
{
	int retorno = 0;
	float auxPrecio1;
	float auxPrecio2;
	if(passenger1 != NULL && passenger2 != NULL)
	{
		Passenger_getPrecio(passenger1,&auxPrecio1);
		Passenger_getPrecio(passenger2,&auxPrecio2);

		if(auxPrecio1 > auxPrecio2)
		{
			retorno = 1;
		}
		else if(auxPrecio1 < auxPrecio2)
		{
			retorno = -1;
		}
	}
	return retorno;
}

int Passenger_tomaDeDatoTipo(char* tipoPasajero)
{
	int auxTipo;
	if(tipoPasajero != NULL)
	{
		if(!strcmp(tipoPasajero,"PRIMERA"))
		{
			auxTipo = 1;
		}
		else if(!strcmp(tipoPasajero,"EJECUTIVO"))
		{
			auxTipo = 2;
		}
		else if(!strcmp(tipoPasajero,"TURISTA"))
		{
			auxTipo = 3;
		}
	}
	return auxTipo;
}

int Passenger_tomaDeDatoEstado(char* estadoVuelo)
{
	int auxEstado;
	if(estadoVuelo != NULL)
	{
		if(!strcmp(estadoVuelo,"ACTIVO"))
		{
			auxEstado = 1;
		}
		else if(!strcmp(estadoVuelo,"CANCELADO"))
		{
			auxEstado = 2;
		}
		else if(!strcmp(estadoVuelo,"DEMORADO"))
		{
			auxEstado = 3;
		}
	}
	return auxEstado;
}



