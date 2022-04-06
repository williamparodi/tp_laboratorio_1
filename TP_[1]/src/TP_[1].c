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

int main(void)
{
	setbuf(stdout,NULL);

	char seguir = 's';
	int kilometros = 0;
	float precioAerolineas = 0;
	float precioLatam = 0;
	int descuento = 10;
	int interes = 25;
	float precioConDebitoAerolineas;
	float precioConDebitoLatam;
	float precioConTarjetaAerolineas;
	float precioConTarjetaLatam;
	float precioPorKilometroAerolineas;
	float precioPorKilometroLatam;

	do
	{
		switch(elegirOpcion(kilometros,precioAerolineas,precioLatam))
		{
			case 1:
				kilometros = ingresarInt("Ingrese los kilometros: \n");
				break;
			case 2:
				precioAerolineas = ingresarInt("Ingrese precio de Vuelo Aeorolineas: ");
				precioLatam = ingresarInt("Ingrese precio de vuelo Latam: ");
				break;
			case 3:
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
			case 6:
				seguir = 'n';
		}
	}while(seguir == 's');


	return EXIT_SUCCESS;
}
