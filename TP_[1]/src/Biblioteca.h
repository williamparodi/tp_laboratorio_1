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
void elegirOpcion(int kilometros,float precioAerolineas,float precioLatam,float precioDebitoAerolineas,float precioDebitoLatam,
		float precioCreditoAerolineas,float precioCreditoLatam,float diferenciaPrecio,float precioUnitarioLatam,float precioUnitarioAerolineas);
int calcularPrecioPorKilometro(float precio,int kilometro,float *precioPorKilometro);
int calcularDescuento(float precio,int descuento,float *precioConDescuento);
int calcularInteres(float precio,int interes,float *precioConInteres);
int calcularDiferencia(float precio1,float precio2,float *diferencia);
int calcularBitcoin(float precio,float bitcoin,float *precioBitcoin);
void mostrarPrecios(int kilometros,float precioAerolineas,float precioLatam,float precioDebitoAerolineas,float precioDebitoLatam,
		float precioCreditoAerolineas,float precioCreditoLatam,float diferenciaPrecio,
		float precioUnitarioLatam,float precioUnitarioAerolineas,
		float precioConBitcoinAerolineas,float precioConBitcoinLatam);

#endif /* BIBLIOTECA_C_ */
