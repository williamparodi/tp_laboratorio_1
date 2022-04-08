/*
 ============================================================================
 Name        : TP_[1].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#include "Utn.h"
#define REINTENTOS 5

int main(void)
{
	setbuf(stdout,NULL);
    int seguir;
	int validarKilometros;
	int validarPrecioAerolineas;
	int validarPrecioLatam;
	int kilometros;
	int flagKilometros;
	int flagPrecios;
	int flagCalculos;
	float precioAerolineas;
	float precioLatam;
	int descuento;
	int interes;
	float precioConDebitoAerolineas;
	float precioConDebitoLatam;
	float precioConTarjetaAerolineas;
	float precioConTarjetaLatam;
	float precioPorKilometroAerolineas;
	float precioPorKilometroLatam;

	kilometros = 0;
	precioAerolineas = 0;
	precioLatam = 0;
	descuento = 10;
	interes = 25;
	flagKilometros = 0;
	flagPrecios = 0;
	flagCalculos = 0;

	do
	{
		switch(elegirOpcion(kilometros,precioAerolineas,precioLatam))
		{
			case 1:
				validarKilometros = utn_getInt(&kilometros,"Ingrese los kilometros:\n","Error al ingresar los kilometros\n",1,10000,REINTENTOS);
				if(validarKilometros == 0)
				{
					flagKilometros = 1;
				}
				break;
			case 2:
				validarPrecioAerolineas = utn_getFloat(&precioAerolineas,"Ingrese precio de vuelo Aerolineas:\n","Error al ingresar el precio\n",1,1000,REINTENTOS);
				validarPrecioLatam = utn_getFloat(&precioLatam,"Ingrese precio de vuelo Latam:\n","Error al ingresar el precio\n",1,1000,REINTENTOS);
				if(validarPrecioAerolineas == 0 && validarPrecioLatam == 0)
				{
					flagPrecios = 1;
				}
				break;
			case 3:
<<<<<<< HEAD
<<<<<<< HEAD
				if(flagPrecios == 1 && flagKilometros == 1)
				{
					sacarDescuento(precioAerolineas,descuento,&precioConDebitoAerolineas);
					sacarDescuento(precioLatam,descuento,&precioConDebitoLatam);
					sacarInteres(precioAerolineas,interes,&precioConTarjetaAerolineas);
					sacarInteres(precioLatam,interes,&precioConTarjetaLatam);
					calcularPrecioPorKilometro(precioAerolineas,kilometros,&precioPorKilometroAerolineas);
					calcularPrecioPorKilometro(precioLatam,kilometros,&precioPorKilometroLatam);
					//FALta BTC / Diferencia de precios /
					flagCalculos = 1;
				}
				else
				{
					printf("No se pueden hacer los calculos sin ingresar precios y kilometros\n");
				}
				break;
			case 4:
				if(flagCalculos ==1)
				{
					printf("Precio con debito: %.2f\n",precioConDebitoAerolineas);
					printf("Precio con debito: %.2f\n",precioConDebitoLatam);
					printf("Precio con tarjeta: %.2f\n",precioConTarjetaAerolineas);
					printf("Precio con tarjeta: %.2f\n",precioConTarjetaLatam); // esto en una funcion que muestre
				}
				else
				{
					printf("No se pueden mostrar los precios sin antes realizar los calculos\n");
				}

				break;
				// Falta case 5 Carga forzada
=======
=======
>>>>>>> 4189bf2ce79e20d7cf139df223fc673832b89383
				precioConDebitoAerolineas = sacarDescuento(precioAerolineas,descuento);
				precioConDebitoLatam = sacarDescuento(precioLatam,descuento);
				precioConTarjetaAerolineas = sacarInteres(precioAerolineas,interes);
				precioConTarjetaLatam = sacarInteres(precioLatam,interes);
				precioPorKilometroAerolineas = calcularPrecioPorKilometro(precioAerolineas,kilometros);
				precioPorKilometroLatam = calcularPrecioPorKilometro(precioLatam,kilometros);
				break;
				//FALta BTC / Diferencia de precios /
			case 4:
				printf("Precio con debito: %.2f\n",precioConDebitoAerolineas);
				printf("Precio con debito: %.2f\n",precioConDebitoLatam);
				printf("Precio con tarjeta: %.2f\n",precioConTarjetaAerolineas);
				printf("Precio con tarjeta: %.2f\n",precioConTarjetaLatam);
				break;
<<<<<<< HEAD
>>>>>>> 4189bf2ce79e20d7cf139df223fc673832b89383
=======
>>>>>>> 4189bf2ce79e20d7cf139df223fc673832b89383
			case 6:
				seguir = 6;
				printf("Gracias por usar nuestro programa\n");
				break;
		}
	}while(seguir != 6);


	return EXIT_SUCCESS;
}
