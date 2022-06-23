/*
 * controller.h
 *
 *  Created on: 17 jun. 2022
 *      Author: knofl
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_



#endif /* CONTROLLER_H_ */

#include "LinkedList.h"
#include "eServicios.h"

/** \brief Carga los datos de los servicios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayServicios LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayServicios);

/** \brief muestra un servicio
 *
 * \param pServicio eServicio* puntero al servicio
 * \return int retorno=0 error, 1=correcto
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayServicios);

/** \brief muestra todos los servicios en una lista
 *
 * \param LinkedList* pArrayServicios array de servicios
 * \return int retorno=0 error, 1=correcto
 *
 */
int controller_ListServicios(LinkedList* pArrayServicios);

/** \brief calcula y carga el campo totalServicio multiplicando la cantidad de servicios * el precio unitario de cada uno
 *
 * \param pArrayServicios LinkedList* array de servicios
 * \return int -1=error,1=correcto
 *
 */
int controller_totalServicios(LinkedList* pArrayServicios);

/** \brief guarda como texto la lista recibida
 *
 * \param path char* ruta donde se guarda la lista
 * \param pArrayServicios LinkedList*   lista recibida
 * \return int retorno=0 error,1=correcto
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayServicios);

/** \brief guarda como binario la lista recibida
 *
 * \param path char* ruta donde se guarda la lista
 * \param pArrayServicios LinkedList*   lista recibida
 * \return int retorno=0 error,1=correcto
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayServicios);

/** \brief filtra la linkedlist recibida y crea una nueva filtrada
 *
 * \param pArrayServicios LinkedList* lista recibida
 * \return int 0=error, 1=correcto
 *
 */
int controller_filtroMinorista(LinkedList* pArrayServicios);

/** \brief filtra la linkedlist recibida y crea una nueva filtrada
 *
 * \param pArrayServicios LinkedList* lista recibida
 * \return int 0=error, 1=correcto
 *
 */
int controller_filtroMayorista(LinkedList* pArrayServicios);

/** \brief filtra la linkedlist recibida y crea una nueva filtrada
 *
 * \param pArrayServicios LinkedList* lista recibida
 * \return int 0=error, 1=correcto
 *
 */
int controller_filtroExportar(LinkedList* pArrayServicios);

/** \brief ordena los servicios
 *
 * \param pArrayServicios LinkedList* lista recibida
 * \return int 0=error, 1=correcto
 *
 */
int controller_sortServicios(LinkedList* pArrayServicios);

/** \brief compara los arrays de caracteres de dos elementos
 *
 * \param a void*
 * \param b void*
 * \return int el retorno es 0=son iguales, >0= A es mayor a B, <0 A es menor que B
 *
 */
int controller_compareDescripcion(void* a, void* b );
