/*
 * controller.c
 *
 *  Created on: 17 jun. 2022
 *      Author: knofl
 */

#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "parser.h"
#include "eServicios.h"
#include "LinkedList.h"
#include "string.h"

int controller_loadFromText(char* path , LinkedList* pArrayServicios)
{
	int todoOk = 0;
	FILE* pFile;

	if ( path != NULL && pArrayServicios != NULL )
	{
		printf("Cargar los datos del taller desde el archivo data.csv (modo texto).\n");

		pFile = fopen( path, "r");
		if ( pFile == NULL )
		{
			printf("No se pudo abrir el archivo\n");
		}
		else
		{
			if (parser_ServicioFromText(pFile, pArrayServicios))
			{
				printf( "Carga de archivo de texto exitosa\n" );
				todoOk = 1;
			}
		}
	}
	fclose(pFile);
	return todoOk;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayServicios)
{
	int todoOk  = 0;
		FILE* p;

		if(path != NULL && pArrayServicios != NULL)
		{
			printf("Cargar los datos del taller desde el archivo data.bin (modo bin).\n");
			p = fopen(path,"rb");
			if(p == NULL)
			{
				printf("No se pudo abrir el archivo\n");
			}
			else
			{
				if(parser_ServicioFromBinary(p,pArrayServicios))
				{
					printf("Carga de archivo de texto exitosa\n");
					todoOk = 1;
				}
			}
		}
		fclose(p);
		return todoOk;
}


int controller_show_eServicio(eServicio* pServicio)
{
	int todoOk=0;
    int id;
    char descripcion[50];
    int tipo;
    float precioUnitario;
    int cantidad;
    float totalServicio;

//	float precioUnitario2;
//	eServicio_getPrecioUnitario(pServicio,&precioUnitario2);
//	printf("precioUnitario2 en controller_show_eServicio: %.2f\n",precioUnitario2);

    if(pServicio != NULL &&
    		eServicio_getId(pServicio,&id)
    		&&
			eServicio_getDescripcionServicio(pServicio,descripcion)
			&&
		 	eServicio_getTipo(pServicio,&tipo)
			&&
			eServicio_getPrecioUnitario(pServicio,&precioUnitario)
			&&
			eServicio_getCantidad(pServicio,&cantidad)
			&&
		 	eServicio_getTotalServicio(pServicio,&totalServicio))
    {
        printf(" %d     %-25s     %d                %.2f              %-4d     %.2f\n",id,descripcion,tipo,precioUnitario,cantidad,totalServicio);
        todoOk = 1;
    }
    return todoOk;
}

int controller_ListServicios(LinkedList* pArrayServicios)
{
	eServicio* pAuxServicio = NULL;
		int todoOk = 0;
		if(pArrayServicios != NULL)
		{
			printf("                     		     ***Lista de Servicios  ***\n");
			eServicio_header();
			for(int i = 0; i<ll_len(pArrayServicios); i++)
			{
				pAuxServicio = ll_get(pArrayServicios,i);
				controller_show_eServicio(pAuxServicio);
			}
			todoOk =1;
		}
		return todoOk;
}


int controller_totalServicios(LinkedList* pArrayServicios)
{
	int retorno=-1;
	void (*pFunc)(void* element);
	if(pArrayServicios!=NULL)
	{
		pFunc= eServicio_totalServicio;
		ll_map(pArrayServicios,pFunc);
		retorno=1;
	}
	return retorno;
}


int controller_filtroMinorista(LinkedList* pArrayServicios)
{
    int todoOk = 0;
    LinkedList* listaFiltrada = NULL;
    if(pArrayServicios != NULL)
    {
        listaFiltrada = ll_filter(pArrayServicios,eServicio_filtroMinorista);
        controller_ListServicios(listaFiltrada);
        controller_saveAsText("serviciosMinoristas.csv",listaFiltrada);
        todoOk = 1;
    }
    return todoOk;
}


int controller_filtroMayorista(LinkedList* pArrayServicios)
{
    int todoOk = 0;
    LinkedList* listaFiltrada = NULL;
    if(pArrayServicios != NULL)
    {
        listaFiltrada = ll_filter(pArrayServicios,eServicio_filtroMayorista);
        controller_ListServicios(listaFiltrada);
        controller_saveAsText("serviciosMayoristas.csv",listaFiltrada);
        todoOk = 1;
    }
    return todoOk;
}


int controller_filtroExportar(LinkedList* pArrayServicios)
{
    int todoOk = 0;
    LinkedList* listaFiltrada = NULL;
    if(pArrayServicios != NULL)
    {
        listaFiltrada = ll_filter(pArrayServicios,eServicio_filtroExportar);
        controller_ListServicios(listaFiltrada);
        controller_saveAsText("serviciosExportar.csv",listaFiltrada);
        todoOk = 1;
    }
    return todoOk;
}

int controller_saveAsText(char* path , LinkedList* pArrayServicios)
{
	int todoOk = 0;
	FILE* pFile;

	int id_servicio;
	char descripcion[25];//(del servicio)
	int tipo;//o (1-MINORISTA, 2-MAYORISTA, 3-EXPORTAR)
	float precioUnitario;
	int cantidad;
	float totalServicio;//precio x cantidad

	eServicio* auxServicio;

	if ( path != NULL && pArrayServicios != NULL )
	{
		pFile = fopen(path, "w");
		if (pFile == NULL)
		{
			printf("No se pudo abrir el archivo\n");
		}

		fprintf(pFile, "id_servicio,descripcion,tipo,precioUnitario,cantidad,totalServicio\n");

		for (int i = 0; i < ll_len(pArrayServicios); i++)
		{
			auxServicio = ll_get(pArrayServicios, i);
			if ( eServicio_getId(auxServicio,&id_servicio)
		    		&&
					eServicio_getDescripcionServicio(auxServicio,descripcion)
					&&
				 	eServicio_getTipo(auxServicio,&tipo)
					&&
					eServicio_getPrecioUnitario(auxServicio,&precioUnitario)
					&&
					eServicio_getCantidad(auxServicio,&cantidad)
					&&
				 	eServicio_getTotalServicio(auxServicio,&totalServicio))
			{
				fprintf(pFile,"%d,%s,%d,%f,%d,%f\n",id_servicio,descripcion,tipo,precioUnitario,cantidad,totalServicio);
				todoOk = 1;
			}
		}
	}
	fclose(pFile);
	return todoOk;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayServicios)
{
	int todoOk = 0;
	FILE* pFile;
	eServicio* auxServicio;

	if (path != NULL && pArrayServicios != NULL)
	{
		pFile = fopen(path, "wb");
		if (pFile == NULL)
		{
			printf("No se pudo abrir el archivo\n");
		}
		for (int i = 0; i < ll_len(pArrayServicios); i++)
		{
			auxServicio = ll_get(pArrayServicios, i);
			if ((auxServicio) != NULL)
			{
				fwrite(auxServicio, sizeof(eServicio), 1, pFile);
				todoOk = 1;
			}
		}
	}
	fclose(pFile);
	return todoOk;
}

int controller_sortServicios(LinkedList* pArrayServicios)
{
	int retorno=-1;
	int opcion=1;
//		int orden;
		//1 es de menor a mayor, 0 es de mayor a menor en ll_sort
		if (pArrayServicios != NULL)
		{
			printf("***Ordenar servicios***\n");
//			printf("1)Ordenar por nombre\n2)Ordenar por apellido\n3)Ordenar por precio de vuelo\n4)Ordenar por codigo de vuelo\n5)Ordenar por tipo de pasajero\n6)Ordenar por estado de vuelo\n7)Ordenar por Id\n");
//			getInt2(&opcion, "Ingrese una opcion:", "ERROR, ingrese una opcion correcta: ", 1, 7);
//			getInt2(&orden, "0: Mayor a menor\n1: Menor a mayor", "ERROR, ingrese una opcion correcta: ", 0, 1);
			switch(opcion)
			{
				case 1:
					ll_sort(pArrayServicios,controller_compareDescripcion,1);
					controller_ListServicios(pArrayServicios);
					break;

				default:
					printf("Opcion invalida dentro del switch opcion\n");
			}
			retorno=1;
		}
    return retorno;
}

int controller_compareDescripcion(void* a, void* b )
{
	int retorno = 0;
	char A[40];
	char B[40];
	if(a != NULL && b != NULL)
	{
		strcpy(A,((eServicio*)a)->descripcion);
		strcpy(B,((eServicio*)b)->descripcion);
		retorno = strcmp(A,B);
	}
	return retorno;
}
