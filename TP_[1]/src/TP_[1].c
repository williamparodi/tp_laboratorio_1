/*
 ============================================================================
 Name        : TP_[1].c

 Author      : Parodi William

 Description : Trabajo Practico 1
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "Utn.h"
#include "Calculos.h"
#define REINTENTOS 5
#define BITCOIN  4797893.14
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

	do
	{
		mostrarMenu(kilometros,precioAerolineas, precioLatam);
		validarSeguir = utn_getInt(&seguir,"Ingrese opcion: \n","Error al ingresar opcion \n",1,6,REINTENTOS);

		if(validarSeguir == 0)
		{
			switch(seguir)
			{
				case 1:
					validarKilometros = utn_getInt(&kilometros,"Ingrese los kilometros:\n","Error al ingresar los kilometros(viaje minimo 100Km/maximo 50000Km)\n",100,50000,REINTENTOS);
					if(validarKilometros == 0)
					{
						flagKilometros = 1;
					}
					break;
				case 2:
					validarPrecioAerolineas = utn_getFloat(&precioAerolineas,"Ingrese precio de vuelo Aerolineas:\n","Error al ingresar el precio(minimo $1000/maximo $10 millones)\n",1000,10000000,REINTENTOS);
					validarPrecioLatam = utn_getFloat(&precioLatam,"Ingrese precio de vuelo Latam:\n","Error al ingresar el precio(minimo $1000/maximo $10 millones)\n",1000,10000000,REINTENTOS);
					if(validarPrecioAerolineas == 0 && validarPrecioLatam == 0)
					{
						flagPrecios = 1;
					}
					else
					{
						printf("Hubo un problema al cargar lo datos\n\n");
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
					}
					else
					{
						printf("No se pueden hacer los calculos sin ingresar precios y kilometros\n\n");
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
						printf("No se pueden mostrar los precios sin antes realizar los calculos\n\n");
					}
					break;
				case 5:
					if(!cargarForzado())
					{
						printf("Carga Forzada exitosa!\n");
					}
					else
					{
						printf("Error al cargar los datos\n");
					}
					break;
				case 6:
					seguir = 6;
					printf("Gracias por usar nuestro programa de viajes!\n");
					break;
			}
		}

	}while(seguir != 6);

	return EXIT_SUCCESS;
}
