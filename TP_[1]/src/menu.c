
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void mostrarMenu(int kilometros,float precioAerolineas,float precioLatam)
{
	printf("1. Ingresar Kilometros : ( km= %d)\n\n",kilometros);
	printf("2. Ingresar precio de vuelos: (Aerolineas = $%.2f , Latam = $%.2f)\n\n",precioAerolineas,precioLatam);
	printf("3. Calcular todos los costos:\n");
	printf("a) Tarjeta de débito (descuento 10%%)\n");
	printf("b) Tarjeta de credito (interes 25%%)\n");
	printf("c) Bitcoin (1BTC -> 4797893.14 Pesos Argentinos)\n");
	printf("d) Mostrar precio por km (precio unitario)\n");
	printf("e) Mostrar diferencia de precio ingresada(Latam - Aerolineas)\n\n");
	printf("4. Informar resultados\n");
	printf("5. Carga forzada de datos\n");
	printf("6. Salir\n\n");
}

void mostrarPrecios(int kilometros,float precioAerolineas,float precioLatam,float precioDebitoAerolineas,float precioDebitoLatam,
		float precioCreditoAerolineas,float precioCreditoLatam,float diferenciaPrecio,float precioUnitarioLatam,float precioUnitarioAerolineas,
		float precioConBitcoinAerolineas,float precioConBitcoinLatam)
{
	printf("Kilometros Ingresados: %d km\n\n",kilometros);
	printf("Precio Aerolineas: $%.2f\n",precioAerolineas);
	printf("a) Precio con tarjeta de débito: $ %.2f\n",precioDebitoAerolineas);
	printf("b) Precio con tarjeta de crédito: $ %.2f\n",precioCreditoAerolineas);
	printf("c) Precio pagando con bitcoin :%f BTC\n",precioConBitcoinAerolineas);
	printf("d) Precio unitario:$ %.2f\n\n",precioUnitarioAerolineas);
	printf("Precios Latam: $%.2f\n",precioLatam);
	printf("a) Precio con tarjeta de débito:$ %.2f\n",precioDebitoLatam);
	printf("b) Precio con tarjeta de crédito:$ %.2f\n",precioCreditoLatam);
	printf("c) Precio pagando con bitcoin:%f BTC\n",precioConBitcoinLatam);
	printf("d) Precio unitario:$ %.2f\n\n",precioUnitarioLatam);
	printf("La diferencia de precio es: $ %.2f\n\n",diferenciaPrecio);
}




