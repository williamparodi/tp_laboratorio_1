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
<<<<<<< HEAD


float calcularPrecioPorKilometro(float precio,int kilometro,float *precioPorKilometro);
float sacarDescuento(float precio,int descuento,float *precioConDescuento);
float sacarInteres(float precio,int interes,float *precioConInteres);
=======
int ingresarInt(char mensaje[]);
float calcularPrecioPorKilometro(float precio,int kilometro);
float sacarDescuento(float precio,int descuento);
float sacarInteres(float precio,int interes);
>>>>>>> 4189bf2ce79e20d7cf139df223fc673832b89383

#endif /* BIBLIOTECA_C_ */
