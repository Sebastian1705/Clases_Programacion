#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Services.h"

Services* services_new(int id,char* nombre,char* email)
{
	Services* this = malloc(sizeof(Services));

	if(this != NULL)
	{

		services_setId(this,id);
		services_setNombre(this,nombre);
		services_setEmail(this,email);
	}
	return this;
}

void services_delete(Services* this)
{
	free(this);
}

int services_setId(Services* this,int id)
{
	this->id = id;
	return 0;
}

int services_setNombre(Services* this,char* nombre)
{
	strcpy(this->nombre,nombre);
	return 0;
}

int services_setEmail(Services* this,char* email)
{
	strcpy(this->email,email);
	return 0;
}

int services_getId(Services* this)
{
	return this->id;
}

char* services_getNombre(Services* this)
{
	return this->nombre;
}

char* services_getEmail(Services* this)
{
	return this->email;
}

Services* services_findById(ArrayList* pArray,int id)
{

	int i;
	Services* aux;
	Services* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(id == services_getId(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Services* services_findByNombre(ArrayList* pArray,char* nombre)
{

	int i;
	Services* aux;
	Services* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(nombre,services_getNombre(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Services* services_findByEmail(ArrayList* pArray,char* email)
{

	int i;
	Services* aux;
	Services* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(email,services_getEmail(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

int services_compareById(void* pA ,void* pB)
{

	int retorno = 0;

	if(services_getId(pA) > services_getId(pB))
		retorno = 1;
	else if(services_getId(pA) < services_getId(pB))
		retorno = -1;

	return retorno;
}

int services_compareByNombre(void* pA ,void* pB)
{

	int retorno;

	retorno = strcmp(services_getNombre(pA),services_getNombre(pB));

	return retorno;
}

int services_compareByEmail(void* pA ,void* pB)
{

	int retorno;

	retorno = strcmp(services_getEmail(pA),services_getEmail(pB));

	return retorno;
}

