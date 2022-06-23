/*
 * menus.c
 *
 *  Created on: 17 jun. 2022
 *      Author: knofl
 */
#include <stdio.h>
#include <stdlib.h>
#include "menus.h"

int menuOpcion()
{
	printf("  				 *** Taller de costura ***\n\n");
	int opcion;
	printf("1) Cargar archivo\n");
	printf("2) Imprimir lista\n");
	printf("3) Asignar totales\n");
	printf("4) Filtrar por tipo\n");
	printf("5) Mostrar servicios\n");
	printf("6) Guardar servicios\n");
	printf("7) Salir.\n");
	scanf("%d",&opcion);
	return opcion;
}

int menuOpcionCargaArchivo()
{
	printf("  				 *** Cargar archivo ***\n\n");
	int opcion;
	printf("1) Cargar archivo de texto\n");
	printf("2) Cargar archivo binario\n");
	printf("3) Volver al menu\n");
	scanf("%d",&opcion);
	return opcion;
}

int menuOpcionFiltrarPorTipo()
{
	printf("  				 *** Filtrar por tipo ***\n\n");
	int opcion;
	printf("1) Minorista\n");
	printf("2) Mayorista\n");
	printf("3) Exportar\n");
	printf("4) Volver al menu\n");
	scanf("%d",&opcion);
	return opcion;
}

int menuOpcionGuardar()
{
	printf("  				 *** Guardar ***\n\n");
	int opcion;
	printf("1) Guardar .csv\n");
	printf("2) Guardar .bin\n");
	printf("3) Volver al menu\n");
	scanf("%d",&opcion);
	return opcion;
}

int menuOpcionFiltros()
{
	printf("  				 *** Filtrar por tipo ***\n\n");
	int opcion;
	printf("1) Minorista\n");
	printf("2) Mayorista\n");
	printf("3) Exportar\n");
	printf("4) Volver al menu\n");
	scanf("%d",&opcion);
	return opcion;
}

