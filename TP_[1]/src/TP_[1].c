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
#define KM 7090
#define PRECIOAERO 162965
#define PRECIOLATAM  159339

int main(void)
{
	setbuf(stdout,NULL);
    int seguir;
	int validarKilometros;
	int validarPrecioAerolineas;
	int validarPrecioLatam;
	int validarSeguir;
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
	{   //modificar el menu y validar entrada de seguir.
		elegirOpcion(kilometros, precioAerolineas, precioLatam, precioConDebitoAerolineas, precioConDebitoLatam, precioConTarjetaAerolineas
				,precioConTarjetaLatam, diferenciaDePrecio, precioPorKilometroLatam, precioPorKilometroAerolineas);

		validarSeguir = utn_getInt(&seguir,"Ingrese opcion: \n","Error al ingresar opcion \n",1,6,REINTENTOS);

		if(validarSeguir == 0)
		{
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
						//FALta BTC
					}
					else
					{
						printf("No se pueden hacer los calculos sin ingresar precios y kilometros\n");
					}
					break;
				case 4:
					if(flagCalculos ==1)
					{
						mostrarPrecios(kilometros,precioAerolineas,precioLatam,precioConDebitoAerolineas,
								precioConDebitoLatam,precioConTarjetaAerolineas,
								precioConTarjetaLatam,diferenciaDePrecio, precioPorKilometroLatam, precioPorKilometroAerolineas,
								precioConBitCoinAerolineas, precioConBitCoinLatam);
					}
					else
					{
						printf("No se pueden mostrar los precios sin antes realizar los calculos\n");
					}
					break;
				case 5:
					calcularDescuento(PRECIOAERO,descuento,&precioConDebitoAerolineas);
					calcularDescuento(PRECIOLATAM,descuento,&precioConDebitoLatam);
					calcularInteres(PRECIOAERO,interes,&precioConTarjetaAerolineas);
					calcularInteres(PRECIOLATAM,interes,&precioConTarjetaLatam);
					calcularPrecioPorKilometro(PRECIOAERO,KM,&precioPorKilometroAerolineas);
					calcularPrecioPorKilometro(PRECIOLATAM,KM,&precioPorKilometroLatam);
					calcularDiferencia(PRECIOLATAM,PRECIOAERO,&diferenciaDePrecio);
					calcularBitcoin(PRECIOAERO,BITCOIN,&precioConBitCoinAerolineas);
					calcularBitcoin(PRECIOLATAM,BITCOIN,&precioConBitCoinLatam);
					mostrarPrecios(KM,PRECIOAERO,PRECIOLATAM,precioConDebitoAerolineas,
							precioConDebitoLatam,precioConTarjetaAerolineas,precioConTarjetaLatam,diferenciaDePrecio,
							precioPorKilometroLatam,precioPorKilometroAerolineas,precioConBitCoinAerolineas,precioConBitCoinLatam);
					break;
				case 6:
					seguir = 6;
					printf("Gracias por usar nuestro programa\n");
					break;
			}
		}

	}while(seguir != 6);




	return EXIT_SUCCESS;
}
