#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Servicio.h"

Servicio* servicio_new(int id,int idCliente,char* cdProducto,float costo,char* fechaIngreso,int estado)
{
	Servicio* this = malloc(sizeof(Servicio));

	if(this != NULL)
	{

		servicio_setId(this,id);
		servicio_setIdCliente(this,idCliente);
		servicio_setCdProducto(this,cdProducto);
		servicio_setCosto(this,costo);
		servicio_setFechaIngreso(this,fechaIngreso);
		servicio_setEstado(this,estado);
	}
	return this;
}

void servicio_delete(Servicio* this)
{
	free(this);
}

int servicio_setId(Servicio* this,int id)
{
	this->id = id;
	return 0;
}

int servicio_setIdCliente(Servicio* this,int idCliente)
{
	this->idCliente = idCliente;
	return 0;
}

int servicio_setCdProducto(Servicio* this,char* cdProducto)
{
	strcpy(this->cdProducto,cdProducto);
	return 0;
}

int servicio_setCosto(Servicio* this,float costo)
{
	this->costo = costo;
	return 0;
}

int servicio_setFechaIngreso(Servicio* this,char* fechaIngreso)
{
	strcpy(this->fechaIngreso,fechaIngreso);
	return 0;
}

int servicio_setEstado(Servicio* this,int estado)
{
	this->estado = estado;
	return 0;
}

int servicio_getId(Servicio* this)
{
	return this->id;
}

int servicio_getIdCliente(Servicio* this)
{
	return this->idCliente;
}

char* servicio_getCdProducto(Servicio* this)
{
	return this->cdProducto;
}

float servicio_getCosto(Servicio* this)
{
	return this->costo;
}

char* servicio_getFechaIngreso(Servicio* this)
{
	return this->fechaIngreso;
}

int servicio_getEstado(Servicio* this)
{
	return this->estado;
}

Servicio* servicio_findById(ArrayList* pArray,int id)
{

	int i;
	Servicio* aux;
	Servicio* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(id == servicio_getId(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Servicio* servicio_findByIdCliente(ArrayList* pArray,int idCliente)
{

	int i;
	Servicio* aux;
	Servicio* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(idCliente == servicio_getIdCliente(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Servicio* servicio_findByCdProducto(ArrayList* pArray,char* cdProducto)
{

	int i;
	Servicio* aux;
	Servicio* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(cdProducto,servicio_getCdProducto(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Servicio* servicio_findByCosto(ArrayList* pArray,float costo)
{

	int i;
	Servicio* aux;
	Servicio* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(costo == servicio_getCosto(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Servicio* servicio_findByFechaIngreso(ArrayList* pArray,char* fechaIngreso)
{

	int i;
	Servicio* aux;
	Servicio* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(fechaIngreso,servicio_getFechaIngreso(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Servicio* servicio_findByEstado(ArrayList* pArray,int estado)
{

	int i;
	Servicio* aux;
	Servicio* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(estado == servicio_getEstado(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

int servicio_compareById(void* pA ,void* pB)
{

	int retorno = 0;

	if(servicio_getId(pA) > servicio_getId(pB))
		retorno = 1;
	else if(servicio_getId(pA) < servicio_getId(pB))
		retorno = -1;

	return retorno;
}

int servicio_compareByIdCliente(void* pA ,void* pB)
{

	int retorno = 0;

	if(servicio_getIdCliente(pA) > servicio_getIdCliente(pB))
		retorno = 1;
	else if(servicio_getIdCliente(pA) < servicio_getIdCliente(pB))
		retorno = -1;

	return retorno;
}

int servicio_compareByCdProducto(void* pA ,void* pB)
{

	int retorno;

	retorno = strcmp(servicio_getCdProducto(pA),servicio_getCdProducto(pB));

	return retorno;
}

int servicio_compareByCosto(void* pA ,void* pB)
{

	int retorno = 0;

	if(servicio_getCosto(pA) > servicio_getCosto(pB))
		retorno = 1;
	else if(servicio_getCosto(pA) < servicio_getCosto(pB))
		retorno = -1;

	return retorno;
}

int servicio_compareByFechaIngreso(void* pA ,void* pB)
{

	int retorno;

	retorno = strcmp(servicio_getFechaIngreso(pA),servicio_getFechaIngreso(pB));

	return retorno;
}

int servicio_compareByEstado(void* pA ,void* pB)
{

	int retorno = 0;

	if(servicio_getEstado(pA) > servicio_getEstado(pB))
		retorno = 1;
	else if(servicio_getEstado(pA) < servicio_getEstado(pB))
		retorno = -1;

	return retorno;
}
