/*
 * Inputs.c
 *
 *  Created on: 7 abr. 2022
 *      Author: Willy
 */
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

