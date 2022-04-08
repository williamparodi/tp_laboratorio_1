/*
 * Biblioteca.c
 *
 *  Created on: 2 abr. 2022
 *      Author: Willy
 */

#ifndef BIBLIOTECA_C_
#define BIBLIOTECA_C_

/// @param kilometros
/// @param precioAerolineas
/// @param precioLatam
/// @return
int elegirOpcion(int kilometros,float precioAerolineas,float precioLatam);


float calcularPrecioPorKilometro(float precio,int kilometro,float *precioPorKilometro);
float sacarDescuento(float precio,int descuento,float *precioConDescuento);
float sacarInteres(float precio,int interes,float *precioConInteres);
float calcularPrecioPorKilometro(float precio,int kilometro);


#endif /* BIBLIOTECA_C_ */
