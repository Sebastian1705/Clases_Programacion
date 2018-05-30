

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Ventas.h"

Ventas* ventas_new(int id_ventas,int id_clientes,int codProducto,int cantidad,float precioUnitario,int estado)
{
	Ventas* this = malloc(sizeof(Ventas));

	if(this != NULL)
	{

		ventas_setId_ventas(this,id_ventas);
		ventas_setId_clientes(this,id_clientes);
		ventas_setCodProducto(this,codProducto);
		ventas_setCantidad(this,cantidad);
		ventas_setPrecioUnitario(this,precioUnitario);
		ventas_setEstado(this,estado);
	}
	return this;
}

void ventas_delete(Ventas* this)
{
	free(this);
}

int ventas_setId_ventas(Ventas* this,int id_ventas)
{
	this->id_ventas = id_ventas;
	return 0;
}

int ventas_setId_clientes(Ventas* this,int id_clientes)
{
	this->id_clientes = id_clientes;
	return 0;
}

int ventas_setCodProducto(Ventas* this,int codProducto)
{
	this->codProducto = codProducto;
	return 0;
}

int ventas_setCantidad(Ventas* this,int cantidad)
{
	this->cantidad = cantidad;
	return 0;
}

int ventas_setPrecioUnitario(Ventas* this,float precioUnitario)
{
	this->precioUnitario = precioUnitario;
	return 0;
}

int ventas_setEstado(Ventas* this,int estado)
{
	this->estado = estado;
	return 0;
}

int ventas_getId_ventas(Ventas* this)
{
	return this->id_ventas;
}

int ventas_getId_clientes(Ventas* this)
{
	return this->id_clientes;
}

int ventas_getCodProducto(Ventas* this)
{
	return this->codProducto;
}

int ventas_getCantidad(Ventas* this)
{
	return this->cantidad;
}

float ventas_getPrecioUnitario(Ventas* this)
{
	return this->precioUnitario;
}

int ventas_getEstado(Ventas* this)
{
	return this->estado;
}

Ventas* ventas_findById_ventas(ArrayList* pArray,int id_ventas)
{

	int i;
	Ventas* aux;
	Ventas* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(id_ventas == ventas_getId_ventas(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Ventas* ventas_findById_clientes(ArrayList* pArray,int id_clientes)
{

	int i;
	Ventas* aux;
	Ventas* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(id_clientes == ventas_getId_clientes(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Ventas* ventas_findByCodProducto(ArrayList* pArray,int codProducto)
{

	int i;
	Ventas* aux;
	Ventas* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(codProducto == ventas_getCodProducto(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Ventas* ventas_findByCantidad(ArrayList* pArray,int cantidad)
{

	int i;
	Ventas* aux;
	Ventas* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(cantidad == ventas_getCantidad(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Ventas* ventas_findByPrecioUnitario(ArrayList* pArray,float precioUnitario)
{

	int i;
	Ventas* aux;
	Ventas* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(precioUnitario == ventas_getPrecioUnitario(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Ventas* ventas_findByEstado(ArrayList* pArray,int estado)
{

	int i;
	Ventas* aux;
	Ventas* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(estado == ventas_getEstado(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

int ventas_compareById_ventas(void* pA ,void* pB)
{

	int retorno = 0;

	if(ventas_getId_ventas(pA) > ventas_getId_ventas(pB))
		retorno = 1;
	else if(ventas_getId_ventas(pA) < ventas_getId_ventas(pB))
		retorno = -1;

	return retorno;
}

int ventas_compareById_clientes(void* pA ,void* pB)
{

	int retorno = 0;

	if(ventas_getId_clientes(pA) > ventas_getId_clientes(pB))
		retorno = 1;
	else if(ventas_getId_clientes(pA) < ventas_getId_clientes(pB))
		retorno = -1;

	return retorno;
}

int ventas_compareByCodProducto(void* pA ,void* pB)
{

	int retorno = 0;

	if(ventas_getCodProducto(pA) > ventas_getCodProducto(pB))
		retorno = 1;
	else if(ventas_getCodProducto(pA) < ventas_getCodProducto(pB))
		retorno = -1;

	return retorno;
}

int ventas_compareByCantidad(void* pA ,void* pB)
{

	int retorno = 0;

	if(ventas_getCantidad(pA) > ventas_getCantidad(pB))
		retorno = 1;
	else if(ventas_getCantidad(pA) < ventas_getCantidad(pB))
		retorno = -1;

	return retorno;
}

int ventas_compareByPrecioUnitario(void* pA ,void* pB)
{

	int retorno = 0;

	if(ventas_getPrecioUnitario(pA) > ventas_getPrecioUnitario(pB))
		retorno = 1;
	else if(ventas_getPrecioUnitario(pA) < ventas_getPrecioUnitario(pB))
		retorno = -1;

	return retorno;
}

int ventas_compareByEstado(void* pA ,void* pB)
{

	int retorno = 0;

	if(ventas_getEstado(pA) > ventas_getEstado(pB))
		retorno = 1;
	else if(ventas_getEstado(pA) < ventas_getEstado(pB))
		retorno = -1;

	return retorno;
}




