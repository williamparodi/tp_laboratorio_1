
#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

int elegirOpcion(int kilometros,float precioAerolineas,float precioLatam)
{
	int opcion;

	printf("1. Ingresar Kilometros : ( km= %d)\n\n",kilometros);
	printf("2. Ingresar precio de vuelos: (Aerolineas = %.2f , Latam = %.2f)\n\n",precioAerolineas,precioLatam);
	printf("3. Calcular todos los costos:\n");
	printf("a) Tarjeta de débito (descuento 10%%)\n");
	printf("b) Tarjeta de credito (interes 25%%)\n");
	printf("c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n");
	printf("d) Mostrar precio por km (precio unitario)\n\n");
	printf("4. Informar resultados\n");
	printf("Latam:\n");
	printf("a) Precio con tarjeta de débito:\n");
	printf("b) Precio con tarjeta de crédito:\n");
	printf("c) Precio pagando con bitcoin :\n");
	printf("d) Precio unitario:\n");
	printf("Aerolineas:\n");
	printf("a) Precio con tarjeta de débito:\n");
	printf("b) Precio con tarjeta de crédito:\n");
	printf("c) Precio pagando con bitcoin :\n");
	printf("d) Precio unitario:\n");
	printf("La diferencia de precio es:\n\n");
	printf("5. Carga forzada de datos\n");
	printf("6. Salir\n");
	scanf("%d",&opcion);

	return opcion;
}


float calcularPrecioPorKilometro(float precio,int kilometro)
{
<<<<<<< HEAD
<<<<<<< HEAD
	float auxPrecioPorKilometro;
    int retorno;
=======
	float precioPorKilometro;
>>>>>>> 4189bf2ce79e20d7cf139df223fc673832b89383
=======
	float precioPorKilometro;
>>>>>>> 4189bf2ce79e20d7cf139df223fc673832b89383

    retorno = -1;

	if(precioPorKilometro != NULL && kilometro > 0 )
	{
<<<<<<< HEAD
<<<<<<< HEAD
		auxPrecioPorKilometro = ((float)precio / kilometro);
		*precioPorKilometro = auxPrecioPorKilometro;
		retorno = 0;
	}

	return retorno;
=======
=======
>>>>>>> 4189bf2ce79e20d7cf139df223fc673832b89383
		precioPorKilometro = ((float)precio / kilometro);
	}

	return precioPorKilometro;
<<<<<<< HEAD
>>>>>>> 4189bf2ce79e20d7cf139df223fc673832b89383
=======
>>>>>>> 4189bf2ce79e20d7cf139df223fc673832b89383
}

float sacarDescuento(float precio,int descuento)
{
<<<<<<< HEAD
<<<<<<< HEAD
	 float auxPrecioConDescuento;
     int retorno;

     retorno = -1;

	 if(precioConDescuento != NULL && descuento > 0)
	 {
		 descuento = ((float) precio * descuento) / 100;
		 auxPrecioConDescuento = precio - descuento;
		 *precioConDescuento = auxPrecioConDescuento;
		 retorno = 0;
	 }

	 return retorno;
=======
	 float precioConDescuento;

	 descuento = ((float) precio * descuento) / 100;
	 precioConDescuento = precio - descuento;
>>>>>>> 4189bf2ce79e20d7cf139df223fc673832b89383
=======
	 float precioConDescuento;

	 descuento = ((float) precio * descuento) / 100;
	 precioConDescuento = precio - descuento;
>>>>>>> 4189bf2ce79e20d7cf139df223fc673832b89383

	 return precioConDescuento;
}

float sacarInteres(float precio,int interes)
{
<<<<<<< HEAD
<<<<<<< HEAD
	float auxPrecioConInteres;
    int retorno;

    retorno = -1;

    if(precioConInteres != NULL && interes >0)
    {
    	interes = ((float) precio * interes) / 100;
    	auxPrecioConInteres = precio + interes;
    	*precioConInteres = auxPrecioConInteres;
    	retorno = 0;
    }

	return retorno;
=======
=======
>>>>>>> 4189bf2ce79e20d7cf139df223fc673832b89383
	float precioConInteres;
	interes = ((float) precio * interes) / 100;
	precioConInteres = precio + interes;

	return precioConInteres;
<<<<<<< HEAD
>>>>>>> 4189bf2ce79e20d7cf139df223fc673832b89383
=======
>>>>>>> 4189bf2ce79e20d7cf139df223fc673832b89383
}
