#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Entidad_1.h"

Entrega* entrega_new(int id,char* producto,char* direccion,char* localidad,char* recibe)
{
	Entrega* this = malloc(sizeof(Entrega));

	if(this != NULL)
	{

		entrega_setId(this,id);
		entrega_setProducto(this,producto);
		entrega_setDireccion(this,direccion);
		entrega_setLocalidad(this,localidad);
		entrega_setRecibe(this,recibe);
	}
	return this;
}

void entrega_delete(Entrega* this)
{
	free(this);
}

int entrega_setId(Entrega* this,int id)
{
	this->id = id;
	return 0;
}

int entrega_setProducto(Entrega* this,char* producto)
{
	strcpy(this->producto,producto);
	return 0;
}

int entrega_setDireccion(Entrega* this,char* direccion)
{
	strcpy(this->direccion,direccion);
	return 0;
}

int entrega_setLocalidad(Entrega* this,char* localidad)
{
	strcpy(this->localidad,localidad);
	return 0;
}

int entrega_setRecibe(Entrega* this,char* recibe)
{
	strcpy(this->recibe,recibe);
	return 0;
}

int entrega_getId(Entrega* this)
{
	return this->id;
}

char* entrega_getProducto(Entrega* this)
{
	return this->producto;
}

char* entrega_getDireccion(Entrega* this)
{
	return this->direccion;
}

char* entrega_getLocalidad(Entrega* this)
{
	return this->localidad;
}

char* entrega_getRecibe(Entrega* this)
{
	return this->recibe;
}

Entrega* entrega_findById(ArrayList* pArray,int id)
{

	int i;
	Entrega* aux;
	Entrega* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(id == entrega_getId(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Entrega* entrega_findByProducto(ArrayList* pArray,char* producto)
{

	int i;
	Entrega* aux;
	Entrega* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(producto,entrega_getProducto(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Entrega* entrega_findByDireccion(ArrayList* pArray,char* direccion)
{

	int i;
	Entrega* aux;
	Entrega* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(direccion,entrega_getDireccion(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Entrega* entrega_findByLocalidad(ArrayList* pArray,char* localidad)
{

	int i;
	Entrega* aux;
	Entrega* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(localidad,entrega_getLocalidad(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Entrega* entrega_findByRecibe(ArrayList* pArray,char* recibe)
{

	int i;
	Entrega* aux;
	Entrega* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(recibe,entrega_getRecibe(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

void entrega_print(void* this)
{
    if(this != NULL)
    {
        printf("%d,%s,%s,%s,%s\n",  entrega_getId(this),
                                    entrega_getProducto(this),
                                    entrega_getDireccion(this),
                                    entrega_getLocalidad(this),
                                    entrega_getRecibe(this));
    }
}

void entrega_printLocalidad(void* this)
{
    printf("%s\n",entrega_getLocalidad(this));
}

int entrega_compareByLocalidad(void* pA ,void* pB)
{

	int retorno;

	retorno = strcmp(entrega_getLocalidad(pA),entrega_getLocalidad(pB));
	if(retorno>0)
        retorno=1;
    else if(retorno<0)
        retorno= -1;

	return retorno;
}
