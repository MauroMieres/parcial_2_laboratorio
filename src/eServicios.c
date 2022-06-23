/*
 * eServicios.c
 *
 *  Created on: 17 jun. 2022
 *      Author: knofl
 */

#include <stdio.h>
#include <stdlib.h>
#include "eServicios.h"
#include "string.h"

eServicio* eServicio_newParametros(char* id_servicioStr,char* descripcionStr,char* tipoStr,char* precioUnitarioStr,char* cantidadStr,char* totalServicioStr)
{

	eServicio* pServicio = eServicio_new();
	if(pServicio != NULL)
	{
		if(!( eServicio_setId(pServicio, atoi(id_servicioStr) )
		   && eServicio_setDescripcionServicio(pServicio,descripcionStr)
		   && eServicio_setTipo(pServicio,atoi(tipoStr))
		   && eServicio_setPrecioUnitario(pServicio,atof(precioUnitarioStr))
		   && eServicio_setCantidad(pServicio,atoi(cantidadStr))
		   && eServicio_setTotalServicio(pServicio,atof(totalServicioStr))))
			{
				printf("pServicio null en newparam\n");
				free(pServicio);
				pServicio = NULL;
			}
	}
	return pServicio;
}

eServicio* eServicio_new()
{
	eServicio* newServicio =  (eServicio*)malloc(sizeof(eServicio));

	    if(newServicio != NULL )
	    {
	    	newServicio->id_servicio = 0;
	        strcpy(newServicio->descripcion," ");
	        newServicio->tipo = 0;
	        newServicio->precioUnitario = 0;
	        newServicio->cantidad = 0;
	        newServicio->totalServicio = 0;
	    }
	    //esto anda bien
	    return newServicio;
}

int eServicio_setId(eServicio* this,int id)
{
	int todoOk = 0;
	if(this != NULL && id > 0)
	{
		this->id_servicio = id;
		todoOk = 1;
	}
	return todoOk;
}

int eServicio_setDescripcionServicio(eServicio* this,char* descripcionServicio)
{
	int todoOk = 0;
//	printf("%s\n",descripcionServicio);
	if(this != NULL && this != NULL && strlen(descripcionServicio) > 1 && strlen(descripcionServicio) < 25)
	{
		strcpy(this->descripcion,descripcionServicio);
		todoOk = 1;
	}
	return todoOk;
}

int eServicio_setTipo(eServicio* this,int tipo)
{
	int todoOk = 0;
	if(this != NULL && tipo > 0)
	{
		this->tipo = tipo;
		todoOk = 1;
	}
	return todoOk;
}

int eServicio_setPrecioUnitario(eServicio* this,float precio)
{
	//el precio llega bien hasta aca
//	printf("precio: %.2f\n",precio);
	int todoOk = 0;
	if(this != NULL && precio > 0)
	{
		this->precioUnitario = precio;
		//hasta aca llega bien
		todoOk = 1;
	}
	return todoOk;
}

int eServicio_setCantidad(eServicio* this,int cantidad)
{
	int todoOk = 0;
	if(this != NULL && cantidad > -1)
	{
		this->cantidad = cantidad;
		todoOk = 1;
	}
	return todoOk;
}

int eServicio_setTotalServicio(eServicio* this,float total)
{
	int todoOk = 0;
	if(this != NULL && total >= 0 && total < 1000000)
	{
		this->totalServicio = total;
		todoOk = 1;
	}
	return todoOk;
}

int eServicio_getId(eServicio* this,int* id)
{
	int todoOk = 0;
	if(this != NULL && id != NULL)
	{
		*id = this->id_servicio;
		todoOk = 1;
	}
	return todoOk;
}

int eServicio_getDescripcionServicio(eServicio* this,char* descripcion)
{
	int todoOk = 0;
	if(this != NULL && descripcion != NULL)
	{
		strcpy(descripcion,this->descripcion);
		todoOk = 1;
	}
	return todoOk;
}

int eServicio_getTipo(eServicio* this,int* tipo)
{
	int todoOk = 0;
	if(this != NULL && tipo != NULL)
	{
		*tipo = this->tipo;
		todoOk = 1;
	}
	return todoOk;
}

int eServicio_getPrecioUnitario(eServicio* this,float* precio)
{
	int todoOk = 0;
//	printf("float* precio: %.2f\n",*precio);
		if(this != NULL && precio != NULL)
		{
			*precio = this->precioUnitario;
			todoOk = 1;
		}
		return todoOk;
}

int eServicio_getCantidad(eServicio* this,int* cantidad)
{
	int todoOk = 0;
	if(this != NULL && cantidad != NULL)
	{
		*cantidad = this->cantidad;
		todoOk = 1;
	}
	return todoOk;
}

int eServicio_getTotalServicio(eServicio* this,float* total)
{
	int todoOk = 0;
	if(this != NULL && total != NULL)
	{
		*total = this->totalServicio;
		todoOk = 1;
	}
	return todoOk;
}

void eServicio_header(void)
{
	printf("-----------------------------------------------------------------------------------------------\n");
	printf(" ID     DESCRIPCION                 TIPO      PRECIO UNITARIO         CANTIDAD   TOTAL SERVICIO\n");
	printf("-----------------------------------------------------------------------------------------------\n");
}

void eServicio_totalServicio(void* this)
{
	int auxCantidad;
	float auxPrecioUnitario;
	eServicio_getCantidad(this,&auxCantidad);
	eServicio_getPrecioUnitario(this, &auxPrecioUnitario);
	eServicio_setTotalServicio(this,(auxCantidad*auxPrecioUnitario));
}

int eServicio_filtroTipo(void*this,int tipo)
{
	int retorno=-1;
	int auxTipo;
	if(eServicio_getTipo(this,&auxTipo)&&auxTipo==tipo)
	{
		retorno=1;
	}
	return retorno;
}

int eServicio_filtroMinorista(void* elemento)
{
	eServicio* aux = NULL;
	int todoOk = 0;
	aux = (eServicio*)elemento;
	if(aux != NULL)
	{
		if (aux->tipo==1)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int eServicio_filtroMayorista(void* elemento)
{
	eServicio* aux = NULL;
	int todoOk = 0;
	aux = (eServicio*)elemento;
	if(aux != NULL)
	{
		if (aux->tipo==2)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int eServicio_filtroExportar(void* elemento)
{
	eServicio* aux = NULL;
	int todoOk = 0;
	aux = (eServicio*)elemento;
	if(aux != NULL)
	{
		if (aux->tipo==3)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

