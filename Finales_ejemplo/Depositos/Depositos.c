#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Depositos.h"

Depositos* depositos_new(int producto,char* descripcion,int cantidad)
{
	Depositos* this = malloc(sizeof(Depositos));

	if(this != NULL)
	{

		depositos_setProducto(this,producto);
		depositos_setDescripcion(this,descripcion);
		depositos_setCantidad(this,cantidad);
	}
	return this;
}

void depositos_delete(Depositos* this)
{
	free(this);
}

int depositos_setProducto(Depositos* this,int producto)
{
	this->producto = producto;
	return 0;
}

int depositos_setDescripcion(Depositos* this,char* descripcion)
{
	strcpy(this->descripcion,descripcion);
	return 0;
}

int depositos_setCantidad(Depositos* this,int cantidad)
{
	this->cantidad = cantidad;
	return 0;
}

int depositos_getProducto(Depositos* this)
{
	return this->producto;
}

char* depositos_getDescripcion(Depositos* this)
{
	return this->descripcion;
}

int depositos_getCantidad(Depositos* this)
{
	return this->cantidad;
}

Depositos* depositos_findByProducto(ArrayList* pArray,int producto)
{

	int i;
	Depositos* aux;
	Depositos* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(producto == depositos_getProducto(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Depositos* depositos_findByDescripcion(ArrayList* pArray,char* descripcion)
{

	int i;
	Depositos* aux;
	Depositos* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(descripcion,depositos_getDescripcion(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Depositos* depositos_findByCantidad(ArrayList* pArray,int cantidad)
{

	int i;
	Depositos* aux;
	Depositos* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(cantidad == depositos_getCantidad(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

int depositos_compareByProducto(void* pA ,void* pB)
{

	int retorno = 0;

	if(depositos_getProducto(pA) > depositos_getProducto(pB))
		retorno = 1;
	else if(depositos_getProducto(pA) < depositos_getProducto(pB))
		retorno = -1;

	return retorno;
}

int depositos_compareByDescripcion(void* pA ,void* pB)
{

	int retorno;

	retorno = strcmp(depositos_getDescripcion(pA),depositos_getDescripcion(pB));

	return retorno;
}

int depositos_compareByCantidad(void* pA ,void* pB)
{

	int retorno = 0;

	if(depositos_getCantidad(pA) > depositos_getCantidad(pB))
		retorno = 1;
	else if(depositos_getCantidad(pA) < depositos_getCantidad(pB))
		retorno = -1;

	return retorno;
}

void depositos_imprimir(void* deposito)
{
    if(deposito != NULL)
    {
        printf("PRODUCTO: %d\t\tDESCRIPCION: %s\t\tCANTIDAD: %d\n",depositos_getProducto(deposito),
                                                                    depositos_getDescripcion(deposito),
                                                                    depositos_getCantidad(deposito));
    }
}
