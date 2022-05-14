#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "ArrayPassenger.h"
#include "menu.h"
#include "informes.h"
#define ACTIVO 1

int sortByLastNameAndTypeDown(Passenger list[],int len)
{
	int retorno;
	int ordenOk;
	retorno=-1;
	Passenger aux;

	if (list != NULL && len > 0)
	{
		do
		{
			ordenOk = 1;
			len--;
			for (int i=0;i<len;i++)
			{
				if(strcmp(list[i].lastName,list[i + 1].lastName)< 0)
				{
					aux = list[i];
					list[i] = list[i + 1];
					list[i + 1] = aux;
					ordenOk = 0;
				}
				else
				{
					if(strcmp(list[i].lastName,list[i + 1].lastName)==0
							&& (list[i].typePassenger
									< list[i + 1].typePassenger))
					{
						aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = aux;
						ordenOk = 0;
					}
				}
			}
		}while(ordenOk== 0);
		retorno = 0;
	}
	return retorno;
}

int sortByLastNameAndTypeUp(Passenger list[],int len)
{
	int retorno;
	int ordenOk;
	retorno=-1;
	Passenger aux;

	if (list != NULL && len > 0)
	{
		do
		{
			ordenOk = 1;
			len--;
			for (int i=0;i<len;i++)
			{
				if(strcmp(list[i].lastName,list[i + 1].lastName)> 0)
				{
					aux = list[i];
					list[i] = list[i + 1];
					list[i + 1] = aux;
					ordenOk = 0;
				}
				else
				{
					if(strcmp(list[i].lastName,list[i + 1].lastName)==0
							&& (list[i].typePassenger
									< list[i + 1].typePassenger))
					{
						aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = aux;
						ordenOk = 0;
					}
				}
			}
		}while(ordenOk== 0);
		retorno = 0;
	}
	return retorno;
}

int accumulatePrice(Passenger list[],int len,float* pAccumulator)
{
    int itsOk;
	itsOk= 0;
    float accumulator = 0;

    if(list != NULL && pAccumulator != NULL && len >0)
    {
        for(int i = 0;i < len;i++)
        {
            if(list[i].isEmpty == 0)
            {
                accumulator+=list[i].price;
            }
        }
        *pAccumulator = accumulator;
        itsOk = 1;
    }
    return itsOk;
}

float calculateAveragePrice(float accumulator,int count,float *pAverage)
{
    int itsOk;
    itsOk=0;

    if(pAverage != NULL && count != 0)
    {
        *pAverage = accumulator / (float) count;
        itsOk = 1;
    }

    return itsOk;
}

float calculateAboveAveragePrice(Passenger list[],int len,float average,int* pCountAbovePrice)
{
    int itsOk;
    int count;
    itsOk=0;
    count=0;

    if(list != NULL && len >0)
    {
        for(int i = 0;i < len;i++)
        {
            if(list[i].isEmpty == 0)
            {
               if(list[i].price > average)
                {
                    count++;
                }
            }
        }
        *pCountAbovePrice = count;
        itsOk = 1;
    }
    return itsOk;
}

int countPassengers(Passenger list[],int len)
{
	int count;
	count=0;
	if(list != NULL && len >0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				count++;
			}
		}
	}
	return count;
}

void printPriceAverageTotal(float totalPrice, float averagePrice, int countAboveAverage)
{
	printf("\nPrecio Total de vuelos : %.2f\n",totalPrice);
	printf("Precio de vuelo promedio : %.2f\n",averagePrice);
	printf("Cantidad de vuelos por arriba del precio promedio : %d\n",countAboveAverage);
}


