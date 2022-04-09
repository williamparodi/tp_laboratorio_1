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
#define BITCOIN  4606954.55

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
	float precioConBitCoinAerolineas;
	float precioConBitCoinLatam;
	float precioPorKilometroAerolineas;
	float precioPorKilometroLatam;
	float diferenciaDePrecio;

	kilometros = 0;
	precioAerolineas = 0;
	precioLatam = 0;
	descuento = 10;
	interes = 25;
	flagKilometros = 0;
	flagPrecios = 0;
	flagCalculos = 0;
	diferenciaDePrecio = 0;

	do
	{
		seguir = elegirOpcion(kilometros, precioAerolineas, precioLatam, precioConDebitoAerolineas, precioConDebitoLatam, precioConTarjetaAerolineas
				,precioConTarjetaLatam, diferenciaDePrecio, precioPorKilometroLatam, precioPorKilometroAerolineas);
		switch(seguir)
		{
			case 1:
				validarKilometros = utn_getInt(&kilometros,"Ingrese los kilometros:\n","Error al ingresar los kilometros(viaje minimo 100K /maximo 50000 k)\n",100,50000,REINTENTOS);
				if(validarKilometros == 0)
				{
					flagKilometros = 1;
				}
				break;
			case 2:
				validarPrecioAerolineas = utn_getFloat(&precioAerolineas,"Ingrese precio de vuelo Aerolineas:\n","Error al ingresar el precio(minimo $1000 /maximo $10 millones)\n",1000,10000000,REINTENTOS);
				validarPrecioLatam = utn_getFloat(&precioLatam,"Ingrese precio de vuelo Latam:\n","Error al ingresar el precio\n",1000,10000000,REINTENTOS);
				if(validarPrecioAerolineas == 0 && validarPrecioLatam == 0)
				{
					flagPrecios = 1;
				}
				break;
			case 3:
				if(flagPrecios == 1 && flagKilometros == 1)
				{
					calcularDescuento(precioAerolineas,descuento,&precioConDebitoAerolineas);
					calcularDescuento(precioLatam,descuento,&precioConDebitoLatam);
					calcularInteres(precioAerolineas,interes,&precioConTarjetaAerolineas);
					calcularInteres(precioLatam,interes,&precioConTarjetaLatam);
					calcularPrecioPorKilometro(precioAerolineas,kilometros,&precioPorKilometroAerolineas);
					calcularPrecioPorKilometro(precioLatam,kilometros,&precioPorKilometroLatam);
					calcularDiferencia(precioLatam,precioAerolineas,&diferenciaDePrecio);
					calcularBitcoin(precioAerolineas,BITCOIN,&precioConBitCoinAerolineas);
					calcularBitcoin(precioLatam,BITCOIN,&precioConBitCoinLatam);
					flagCalculos = 1;
					//FALta BTC / Diferencia de precios /
				}
				else
				{
					printf("No se pueden hacer los calculos sin ingresar precios y kilometros\n");
				}
				break;
			case 4:
				if(flagCalculos ==1)
				{
					printf("Kilometros Ingresados: %d\n\n",kilometros);
					printf("Precio Aerolineas: $%.2f\n",precioAerolineas);
					printf("a) Precio con tarjeta de débito: $%.2f\n",precioConDebitoAerolineas);
					printf("b) Precio con tarjeta de crédito: $%.2f\n",precioConTarjetaAerolineas);
					printf("c) Precio pagando con bitcoin :%.2f\n",precioConBitCoinAerolineas);
					printf("d) Precio unitario:$%.2f\n\n",precioPorKilometroAerolineas);
					printf("Precios Latam: %.2f\n",precioLatam);
					printf("a) Precio con tarjeta de débito:$%.2f\n",precioConDebitoLatam);
					printf("b) Precio con tarjeta de crédito:$%.2f\n",precioConTarjetaLatam);
					printf("c) Precio pagando con bitcoin :%.2f\n",precioConBitCoinLatam);
					printf("d) Precio unitario:$%.2f\n",precioPorKilometroLatam);
					printf("La diferencia de precio es:%.2f\n\n",diferenciaDePrecio);

				}
				else
				{
					printf("No se pueden mostrar los precios sin antes realizar los calculos\n");
				}
				break;
			case 5:
				break;
				// Falta case 5 Carga forzada
			case 6:
				seguir = 6;
				printf("Gracias por usar nuestro programa\n");
				break;
		}
	}while(seguir != 6);


	return EXIT_SUCCESS;
}
