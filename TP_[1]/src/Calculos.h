/*
 * Calculos.h
 *
 *      Author: Parodi William
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

/// @param precio
/// @param kilometro
/// @param precioPorKilometro
/// @return retorna -1 en caso de error y 0 en caso exitoso
/// @brief  Calula el precio dividiendolo por la cantidad de kilometros ingresados,valida el manejo del puntero y datos nulos
int calcularPrecioPorKilometro(float precio,int kilometro,float *precioPorKilometro);

/// @param precio
/// @param descuento
/// @param precioConDescuento
/// @return retorna -1 en caso de error y 0 en caso exitoso
/// @brief Calcula el descuento del precio total y lo resta,valida el manejo del puntero y datos nulos
int calcularDescuento(float precio,int descuento,float *precioConDescuento);

/// @param precio
/// @param interes
/// @param precioConInteres
/// @return retorna -1 en caso de error y 0 en caso exitoso
/// @brief Calcula el interes del precio y se lo suma,valida el manejo del puntero y datos nulos
int calcularInteres(float precio,int interes,float *precioConInteres);

/// @param precio1
/// @param precio2
/// @param diferencia
/// @return retorna -1 en caso de error y 0 en caso exitoso
/// @brief Calcula la direfencia entre dos precios,si el resultado es negativo lo multiplica por -1 para dar un resultado positivo,
///  valida el manejo del puntero y datos nulos.
int calcularDiferencia(float precio1,float precio2,float *diferencia);

/// @param precio
/// @param bitcoin
/// @param precioBitcoin
/// @return retorna -1 en caso de error y 0 en caso exitoso
/// @brief Calcula el precio del bitcoin y valida el manejo del puntero y datos nulos.
int calcularBitcoin(float precio,float bitcoin,float *precioBitcoin);


#endif /* CALCULOS_H_ */
