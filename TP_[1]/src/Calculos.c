#include <stdio.h>
#include <stdlib.h>
#include "Calculos.h"
#include "Utn.h"

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


