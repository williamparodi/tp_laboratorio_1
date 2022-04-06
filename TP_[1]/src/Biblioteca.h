/*
 * Biblioteca.c
 *
 *  Created on: 2 abr. 2022
 *      Author: Willy
 */

#ifndef BIBLIOTECA_C_
#define BIBLIOTECA_C_

int elegirOpcion(int kilometros,float precioAerolineas,float precioLatam);
int ingresarInt(char mensaje[]);
float calcularPrecioPorKilometro(float precio,int kilometro);
float sacarDescuento(float precio,int descuento);
float sacarInteres(float precio,int interes);

#endif /* BIBLIOTECA_C_ */
