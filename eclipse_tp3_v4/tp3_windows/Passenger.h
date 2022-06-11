#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[10];
	int estadoVuelo;

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametrosTxt(char* idStr,char* nombreStr,char* apellidoStr,char* precio,char* codigoVuelo,char* tipoPasajeroStr,char* estadoVuelo);
Passenger* Passenger_newParametros(int idStr,char* nombreStr,char* apellidoStr,float precio,int tipoPasajeroStr,char* codigoVuelo,int estadoVuelo);
void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo);

//Setters Txt
int Passenger_setIdTxt(Passenger* this,char* id);
int Passenger_setPrecioTxt(Passenger* this,char* precio);
int Passenger_setEstadoVueloTxt(Passenger* this,char* estadoVuelo);
int Passenger_setTipoPasajeroTxt(Passenger* this,char* tipoPasajero);

int Passenger_showOnePassenger(Passenger* pOnePassenger);
int Passenger_showListPassenger(Passenger** arrayPassenger,int len);
int Passenger_initArrayPPassenger(Passenger** arrayPPassenger,int len);
int Passenger_findEmpty(Passenger** arrayPassenger,int len);
int Passenger_add(Passenger** arrayPassenger,int len);
Passenger* Passenger_searchPassengerById(LinkedList* arrayPassenger,int idIngresado);
int Passenger_printOneWith(Passenger* pOnePassenger);
int Passenger_orderByPrecio(void* passenger1,void* passenger2);
int Passenger_orderByName(void* passenger1,void* passenger2);
int Passenger_tomaDeDatoTipo(char* tipoPasajero);
int Passenger_tomaDeDatoEstado(char* estadoVuelo);
#endif /* PASSENGER_H_ */
