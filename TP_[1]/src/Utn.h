/*
 * Inputs.h
 *
 *  Created on: 7 abr. 2022
 *      Author: Willy
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getInt(int *pNumeroIngresado,char * mensaje,char * mensajeError,int minimo,int maximo,int reintentos);
int utn_getFloat(float *pNumeroIngresado,char * mensaje,char * mensajeError,int minimo,int maximo,int reintentos);

#endif /* UTN_H_ */
