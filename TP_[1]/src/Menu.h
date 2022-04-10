/*
 * Biblioteca.c
 *
 *      Author: Parodi William
 */

#ifndef MENU_C_
#define MENU_C_

/// @param kilometros
/// @param precioAerolineas
/// @param precioLatam
/// @brief Muestra por pantalla el menu de opciones con la carga actual de kilometros y precios
void mostrarMenu(int kilometros,float precioAerolineas,float precioLatam);


/// @param kilometros
/// @param precioAerolineas
/// @param precioLatam
/// @param precioDebitoAerolineas
/// @param precioDebitoLatam
/// @param precioCreditoAerolineas
/// @param precioCreditoLatam
/// @param diferenciaPrecio
/// @param precioUnitarioLatam
/// @param precioUnitarioAerolineas
/// @param precioConBitcoinAerolineas
/// @param precioConBitcoinLatam
/// @brief  Muestra por pantalla todo el reultado de los precios calculados.
void mostrarPrecios(int kilometros,float precioAerolineas,float precioLatam,float precioDebitoAerolineas,float precioDebitoLatam,
		float precioCreditoAerolineas,float precioCreditoLatam,float diferenciaPrecio,
		float precioUnitarioLatam,float precioUnitarioAerolineas,
		float precioConBitcoinAerolineas,float precioConBitcoinLatam);

#endif /* MENU_C_ */
