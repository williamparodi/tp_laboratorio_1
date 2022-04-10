
#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#include "Utn.h"
#define KM 7090
#define PRECIOAERO 162965
#define PRECIOLATAM  159339

void elegirOpcion(int kilometros,float precioAerolineas,float precioLatam,float precioDebitoAerolineas,float precioDebitoLatam,
		float precioCreditoAerolineas,float precioCreditoLatam,float diferenciaPrecio,float precioUnitarioLatam,float precioUnitarioAerolineas)
{
	printf("1. Ingresar Kilometros : ( km= %d)\n\n",kilometros);
	printf("2. Ingresar precio de vuelos: (Aerolineas = $%.2f , Latam = $%.2f)\n\n",precioAerolineas,precioLatam);
	printf("3. Calcular todos los costos:\n");
	printf("a) Tarjeta de débito (descuento 10%%)\n");
	printf("b) Tarjeta de credito (interes 25%%)\n");
	printf("c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n");
	printf("d) Mostrar precio por km (precio unitario)\n");
	printf("e) Mostrar diferencia de precio ingresada(Latam - Aerolineas)\n\n");
	printf("4. Informar resultados\n");
	printf("Latam:\n");
	printf("a) Precio con tarjeta de débito:$%.2f\n",precioDebitoLatam);
	printf("b) Precio con tarjeta de crédito:$%.2f\n",precioCreditoLatam);
	printf("c) Precio pagando con bitcoin :\n");
	printf("d) Precio unitario:$%.2f\n",precioUnitarioLatam);
	printf("Aerolineas:\n");
	printf("a) Precio con tarjeta de débito:$%.2f\n",precioDebitoAerolineas);
	printf("b) Precio con tarjeta de crédito:$%.2f\n",precioCreditoAerolineas);
	printf("c) Precio pagando con bitcoin :\n");
	printf("d) Precio unitario:$%.2f\n\n",precioUnitarioAerolineas);
	printf("La diferencia de precio es:%.2f\n\n",diferenciaPrecio);
	printf("5. Carga forzada de datos\n");
	printf("6. Salir\n");

}


int calcularPrecioPorKilometro(float precio,int kilometro,float *precioPorKilometro)
{

	float auxPrecioPorKilometro;
    int retorno;
    retorno = -1;

	if(precioPorKilometro != NULL && kilometro > 0 && precio >0)
	{
		auxPrecioPorKilometro = (float)precio / kilometro;
		*precioPorKilometro = auxPrecioPorKilometro;
		retorno = 0;
	}

	return retorno;
}

int calcularDescuento(float precio,int descuento,float *precioConDescuento)
{
	 float auxPrecioConDescuento;
     int retorno;
     retorno = -1;

	 if(precioConDescuento != NULL && descuento > 0 && precio >0)
	 {
		 descuento = ((float) precio * descuento) / 100;
		 auxPrecioConDescuento = precio - descuento;
		 *precioConDescuento = auxPrecioConDescuento;
		 retorno = 0;
	 }

	 return retorno;
}

int calcularInteres(float precio,int interes, float *precioConInteres)
{
	float auxPrecioConInteres;
    int retorno;
    retorno = -1;

    if(precioConInteres != NULL && interes >0 && precio > 0)
    {
    	interes = ((float) precio * interes) / 100;
    	auxPrecioConInteres = precio + interes;
    	*precioConInteres = auxPrecioConInteres;
    	retorno = 0;
    }

	return retorno;
}

int calcularDiferencia(float precio1,float precio2,float *diferencia)
{
    float auxdiferencia;
    int retorno;
    retorno = -1;

    if(diferencia != NULL && precio1 > 0 && precio2 > 0)
    {
    	auxdiferencia = utn_restarDosFloat(precio1, precio2);

        if(auxdiferencia <0)
        {
    	   auxdiferencia = auxdiferencia * (float)-1;

    	}

        *diferencia = auxdiferencia;
        retorno = 0;
    }

    return retorno;
}

int calcularBitcoin(float precio,float bitcoin,float *precioBitcoin)
{
	float auxPrecioBitCoin;
    int retorno;
    retorno = -1;

    if(precioBitcoin != NULL && precio > 0 && bitcoin > 0)
    {
    	auxPrecioBitCoin = precio / bitcoin;
    	*precioBitcoin = auxPrecioBitCoin;
    	retorno = 0;
    }

    return retorno;
}

void mostrarPrecios(int kilometros,float precioAerolineas,float precioLatam,float precioDebitoAerolineas,float precioDebitoLatam,
		float precioCreditoAerolineas,float precioCreditoLatam,float diferenciaPrecio,float precioUnitarioLatam,float precioUnitarioAerolineas,
		float precioConBitcoinAerolineas,float precioConBitcoinLatam)
{
	printf("Kilometros Ingresados: %d km\n\n",kilometros);
	printf("Precio Aerolineas: $%.2f\n",precioAerolineas);
	printf("a) Precio con tarjeta de débito: $ %.2f\n",precioDebitoAerolineas);
	printf("b) Precio con tarjeta de crédito: $ %.2f\n",precioCreditoAerolineas);
	printf("c) Precio pagando con bitcoin :%f BTC\n",precioConBitcoinAerolineas);
	printf("d) Precio unitario:$ %.2f\n\n",precioUnitarioAerolineas);
	printf("Precios Latam: $%.2f\n",precioLatam);
	printf("a) Precio con tarjeta de débito:$%.2f\n",precioDebitoLatam);
	printf("b) Precio con tarjeta de crédito:$%.2f\n",precioCreditoLatam);
	printf("c) Precio pagando con bitcoin :%f BTC\n",precioConBitcoinLatam);
	printf("d) Precio unitario:$%.2f\n",precioUnitarioLatam);
	printf("La diferencia de precio es:%.2f\n\n",diferenciaPrecio);
}


