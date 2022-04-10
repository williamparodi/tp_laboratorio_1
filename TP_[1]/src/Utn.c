
#include <stdio.h>
#include <stdlib.h>
#include "Utn.h"

int utn_getInt(int *pNumeroIngresado,char * mensaje,char * mensajeError,int minimo,int maximo,int reintentos)
{
	int auxNumeroIngresado;
	int retorno;
	retorno = -1;

    if(pNumeroIngresado != NULL && maximo >= minimo && reintentos >=0)
    {
        do
		{
			printf("%s",mensaje);
			scanf("%d",&auxNumeroIngresado);
			reintentos--;

			if(auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo)
			{
				*pNumeroIngresado = auxNumeroIngresado;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
			}

		}while(reintentos > 0);
    }

	return retorno;
}

int utn_getFloat(float *pNumeroIngresado,char * mensaje,char * mensajeError,int minimo,int maximo,int reintentos)
{
	float auxNumeroIngresado;
	int retorno;
	retorno = -1;

	if(pNumeroIngresado != NULL && maximo >= minimo && reintentos >=0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%f",&auxNumeroIngresado);
			reintentos--;

			if(auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo)
			{
				*pNumeroIngresado = auxNumeroIngresado;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
			}

		}while(reintentos > 0);
	}

	return retorno;
}

int utn_restarDosInt(int numero1,int numero2)
{
	int resta;

	resta = numero1 - numero2;

	return resta;
}

float utn_restarDosFloat(float numero1,float numero2)
{
	float resta;

	resta = numero1 - numero2;

	return resta;
}
