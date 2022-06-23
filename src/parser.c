#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eServicios.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

//

int parser_ServicioFromText(FILE* pFile , LinkedList* pArrayServicios)
{
	int todoOk=-1;
	eServicio* pAuxServicio = NULL;
	int r=0;
	char var1[50],var2[50],var3[50],var4[50],var5[50],var6[50];
	if(pFile == NULL)
	{
		printf("Archivo nulo");
	}
	else
	{
//	lectura fantasma
	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6);
//	printf("%s	%s	%s	%s	%s	%s\n\n",var1,var2,var3,var4,var5,var6);

	while(!feof(pFile))
		{

			r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6);
			if(r<6)
			{
				break;
			}
			pAuxServicio = eServicio_newParametros(var1,var2,var3,var4,var5,var6);

			if(pAuxServicio!=NULL)
			{
				ll_add(pArrayServicios,pAuxServicio);
				todoOk=1;
			}
		}
	}
	  return todoOk;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_ServicioFromBinary(FILE* pFile , LinkedList* pArrayServicios)
{
	int todoOk = 0;
	int cantidad; //Cantidad leida
	eServicio* pServicio;

	if(pFile != NULL)
	{
		do
		{
			pServicio = eServicio_new();
			cantidad = fread(pServicio,sizeof(pServicio),1,pFile);
			if(pServicio != NULL && cantidad == 1)
			{
				ll_add(pArrayServicios,pServicio);
				todoOk = 1;
			}
		}
		while(!feof(pFile));
	}
	return todoOk;
}
