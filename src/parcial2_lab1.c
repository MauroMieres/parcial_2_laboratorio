/*
 ============================================================================
 Name        : parcial2_lab1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "menus.h"
#include "controller.h"

int main(void) {
	setbuf(stdout,NULL);
	char seguir='s';
	LinkedList* listaServicios = ll_newLinkedList();

	do{
	        switch(menuOpcion())
	        {
	        case 1:
	        	switch(menuOpcionCargaArchivo())
				{
	        	case 1:
	        		controller_loadFromText("data.csv",listaServicios);
	        		break;
	        	case 2:
	        		controller_loadFromBinary("data.bin",listaServicios);
	        		break;
	        	case 3:
	        		printf("Volver al menu\n");
	        		break;
	        	default:
	        		printf("Opcion ingresada invalida switch carga archivos\n");
				}

	        	break;
			case 2:
				if(ll_isEmpty(listaServicios))
				{
					printf("Tiene que cargar el archivo primero\n");
				}
				else
				{
					controller_ListServicios(listaServicios);
				}
				break;

			case 3:
				if(ll_isEmpty(listaServicios))
				{
					printf("Tiene que cargar el archivo primero\n");
				}
				else
				{
					if(!controller_totalServicios(listaServicios))
					{
						printf("Error en controller_totalServicios\n");
					}
					controller_ListServicios(listaServicios);
				}
				break;
			case 4:
				if(ll_isEmpty(listaServicios))
				{
					printf("Tiene que cargar el archivo primero\n");
				}
				else
				{
					switch(menuOpcionFiltros())
					{
					case 1:
						controller_filtroMinorista(listaServicios);
						break;
					case 2:
						controller_filtroMayorista(listaServicios);
						break;
					case 3:
						controller_filtroExportar(listaServicios);
						break;
					case 4:
						printf("Volver al menu\n");
						break;
					}
				}
				break;

				case 5:
					if(ll_isEmpty(listaServicios))
					{
						printf("Tiene que cargar el archivo primero\n");
					}
					else
					{
						controller_sortServicios(listaServicios);
						controller_ListServicios(listaServicios);
					}
					break;
				case 6:
					if(ll_isEmpty(listaServicios))
					{
						printf("Tiene que cargar el archivo primero\n");
					}
					else
					{
						controller_sortServicios(listaServicios);
						controller_saveAsText("serviciosOrdenanosDescripcionAscendente.csv",listaServicios);
					}
					break;
				case 7:
					printf("Salir\n");
					seguir='n';
					break;
				default:
					break;
	        }
	    }while(seguir=='s');
	   ll_deleteLinkedList(listaServicios);
	return EXIT_SUCCESS;
}
