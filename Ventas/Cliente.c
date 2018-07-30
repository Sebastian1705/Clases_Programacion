#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Cliente.h"

Cliente* cliente_new(char* nombre,char* apellido,char* dni,int id,int estado)
{
	Cliente* this = malloc(sizeof(Cliente));

	if(this != NULL)
	{

		cliente_setNombre(this,nombre);
		cliente_setApellido(this,apellido);
		cliente_setDni(this,dni);
		cliente_setId(this,id);
		cliente_setEstado(this,estado);
	}
	return this;
}

void cliente_delete(Cliente* this)
{
	free(this);
}

int cliente_setNombre(Cliente* this,char* nombre)
{
	strcpy(this->nombre,nombre);
	return 0;
}

int cliente_setApellido(Cliente* this,char* apellido)
{
	strcpy(this->apellido,apellido);
	return 0;
}

int cliente_setDni(Cliente* this,char* dni)
{
	strcpy(this->dni,dni);
	return 0;
}

int cliente_setId(Cliente* this,int id)
{
	this->id = id;
	return 0;
}

int cliente_setEstado(Cliente* this,int estado)
{
	this->estado = estado;
	return 0;
}

char* cliente_getNombre(Cliente* this)
{
	return this->nombre;
}

char* cliente_getApellido(Cliente* this)
{
	return this->apellido;
}

char* cliente_getDni(Cliente* this)
{
	return this->dni;
}

int cliente_getId(Cliente* this)
{
	return this->id;
}

int cliente_getEstado(Cliente* this)
{
	return this->estado;
}

Cliente* cliente_findByNombre(ArrayList* pArray,char* nombre)
{

	int i;
	Cliente* aux;
	Cliente* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(nombre,cliente_getNombre(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Cliente* cliente_findByApellido(ArrayList* pArray,char* apellido)
{

	int i;
	Cliente* aux;
	Cliente* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(apellido,cliente_getApellido(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Cliente* cliente_findByDni(ArrayList* pArray,char* dni)
{

	int i;
	Cliente* aux;
	Cliente* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(dni,cliente_getDni(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Cliente* cliente_findById(ArrayList* pArray,int id)
{

	int i;
	Cliente* aux;
	Cliente* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(id == cliente_getId(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Cliente* cliente_findByEstado(ArrayList* pArray,int estado)
{

	int i;
	Cliente* aux;
	Cliente* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(estado == cliente_getEstado(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

int cliente_compareByNombre(void* pA ,void* pB)
{

	int retorno;

	retorno = strcmp(cliente_getNombre(pA),cliente_getNombre(pB));

	return retorno;
}

int cliente_compareByApellido(void* pA ,void* pB)
{

	int retorno;

	retorno = strcmp(cliente_getApellido(pA),cliente_getApellido(pB));
	if(retorno>0)
        retorno=1;
    else if(retorno<0)
        retorno= -1;

	return retorno;
}

int cliente_compareByDni(void* pA ,void* pB)
{

	int retorno;

	retorno = strcmp(cliente_getDni(pA),cliente_getDni(pB));

	return retorno;
}

int cliente_compareById(void* pA ,void* pB)
{

	int retorno = 0;

	if(cliente_getId(pA) > cliente_getId(pB))
		retorno = 1;
	else if(cliente_getId(pA) < cliente_getId(pB))
		retorno = -1;

	return retorno;
}

int cliente_compareByEstado(void* pA ,void* pB)
{

	int retorno = 0;

	if(cliente_getEstado(pA) > cliente_getEstado(pB))
		retorno = 1;
	else if(cliente_getEstado(pA) < cliente_getEstado(pB))
		retorno = -1;

	return retorno;
}

void cliente_imprimir(void* pCliente)
{

    if(cliente_getEstado(pCliente) == CLIENTE_ALTA)
        {
            printf("ID: %d - NOMBRE: %s - APELLIDO: %s - DNI: %s\n",cliente_getId(pCliente),cliente_getNombre(pCliente),
                                                                    cliente_getApellido(pCliente),cliente_getDni(pCliente));
        }
}


