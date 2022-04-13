/*
 * Utn.h
 *
 *      Author: Parodi William
 */

#ifndef UTN_H_
#define UTN_H_

/// @param pNumeroIngresado
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return retorna -1 en caso de error o 0 en caso de exito.
/// @brief Valida el ingreso de un numero entero entre minimo y un maximo ,con mensaje de ingreso y error,
/// descuenta intentos cada vez que el usuario se equivoca.
int utn_getInt(int *pNumeroIngresado,char * mensaje,char * mensajeError,int minimo,int maximo,int reintentos);

/// @param pNumeroIngresado
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return retorna -1 en caso de error o 0 en caso de exito.
/// @brief  Valida el ingreso de un numero decimal entre minimo y un maximo ,con mensaje de ingreso y error,
/// descuenta intentos cada vez que el usuario se equivoca.
int utn_getFloat(float *pNumeroIngresado,char * mensaje,char * mensajeError,int minimo,int maximo,int reintentos);

/// @param numero1
/// @param numero2
/// @return retorno un int con el resultado
/// @brief Resta dos enteros y retorna el resultado
int utn_restarDosInt(int numero1,int numero2);

/// @param numero1
/// @param numero2
/// @return retorno un float con el resultado
/// @brief Resta dos enteros y retorna el resultado
float utn_restarDosFloat(float numero1,float numero2);

#endif /* UTN_H_ */
