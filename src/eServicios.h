/*
 * eServicios.h
 *
 *  Created on: 17 jun. 2022
 *      Author: knofl
 */

#ifndef ESERVICIOS_H_
#define ESERVICIOS_H_

typedef struct
{
	int id_servicio;
	char descripcion[25];//(del servicio)
	int tipo;//o (1-MINORISTA, 2-MAYORISTA, 3-EXPORTAR)
	float precioUnitario;
	int cantidad;
	float totalServicio;//precio x cantidad
}eServicio;

#endif /* ESERVICIOS_H_ */

int eServicio_setTotalServicio(eServicio* this,float total);
int eServicio_setCantidad(eServicio* this,int cantidad);
int eServicio_setPrecioUnitario(eServicio* this,float precio);
int eServicio_setTipo(eServicio* this,int tipo);
int eServicio_setDescripcionServicio(eServicio* this,char* descripcionServicio);
int eServicio_setId(eServicio* this,int id);
eServicio* eServicio_new();
eServicio* eServicio_newParametros(char* id_servicioStr,char* descripcionStr,char* tipoStr,char* precioUnitarioStr,char* cantidadStr,char* totalServicioStr);
int eServicio_getId(eServicio* this,int* id);
int eServicio_getDescripcionServicio(eServicio* this,char* descripcion);
int eServicio_getTipo(eServicio* this,int* tipo);
int eServicio_getPrecioUnitario(eServicio* this,float* precio);
int eServicio_getCantidad(eServicio* this,int* cantidad);
int eServicio_getTotalServicio(eServicio* this,float* total);
void eServicio_header(void);
void eServicio_totalServicio(void* this);
int eServicio_filtroMinorista(void* elemento);
int eServicio_filtroMayorista(void* elemento);
int eServicio_filtroExportar(void* elemento);
