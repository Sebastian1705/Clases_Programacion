#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Cliente.h"

Cliente* cliente_new(char* nombre,char* apellido,char* email,char genero,char* profesion,char* nacionalidad,int id, char* usuario)
{
	Cliente* this = malloc(sizeof(Cliente));

	if(this != NULL)
	{

		cliente_setNombre(this,nombre);
		cliente_setApellido(this,apellido);
		cliente_setEmail(this,email);
		cliente_setGenero(this,genero);
		cliente_setProfesion(this,profesion);
		cliente_setNacionalidad(this,nacionalidad);
		cliente_setId(this,id);
		cliente_setUsuario(this,usuario);
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

int cliente_setEmail(Cliente* this,char* email)
{
	strcpy(this->email,email);
	return 0;
}

int cliente_setGenero(Cliente* this,char genero)
{
	this->genero = genero;
	return 0;
}

int cliente_setProfesion(Cliente* this,char* profesion)
{
	strcpy(this->profesion,profesion);
	return 0;
}

int cliente_setNacionalidad(Cliente* this,char* nacionalidad)
{
	strcpy(this->nacionalidad,nacionalidad);
	return 0;
}

int cliente_setId(Cliente* this,int id)
{
	this->id = id;
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

char* cliente_getEmail(Cliente* this)
{
	return this->email;
}

char cliente_getGenero(Cliente* this)
{
	return this->genero;
}

char* cliente_getProfesion(Cliente* this)
{
	return this->profesion;
}

char* cliente_getNacionalidad(Cliente* this)
{
	return this->nacionalidad;
}

int cliente_getId(Cliente* this)
{
	return this->id;
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

Cliente* cliente_findByEmail(ArrayList* pArray,char* email)
{

	int i;
	Cliente* aux;
	Cliente* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(email,cliente_getEmail(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Cliente* cliente_findByGenero(ArrayList* pArray,char genero)
{

	int i;
	Cliente* aux;
	Cliente* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(genero == cliente_getGenero(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Cliente* cliente_findByProfesion(ArrayList* pArray,char* profesion)
{

	int i;
	Cliente* aux;
	Cliente* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(profesion,cliente_getProfesion(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Cliente* cliente_findByNacionalidad(ArrayList* pArray,char* nacionalidad)
{

	int i;
	Cliente* aux;
	Cliente* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(nacionalidad,cliente_getNacionalidad(aux))==0)
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

	return retorno;
}

int cliente_compareByEmail(void* pA ,void* pB)
{

	int retorno;

	retorno = strcmp(cliente_getEmail(pA),cliente_getEmail(pB));

	return retorno;
}

int cliente_compareByGenero(void* pA ,void* pB)
{

	int retorno = 0;

	if(cliente_getGenero(pA) > cliente_getGenero(pB))
		retorno = 1;
	else if(cliente_getGenero(pA) < cliente_getGenero(pB))
		retorno = -1;

	return retorno;
}

int cliente_compareByProfesion(void* pA ,void* pB)
{

	int retorno;

	retorno = strcmp(cliente_getProfesion(pA),cliente_getProfesion(pB));

	return retorno;
}

int cliente_compareByNacionalidad(void* pA ,void* pB)
{

	int retorno;

	retorno = strcmp(cliente_getNacionalidad(pA),cliente_getNacionalidad(pB));

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

int cliente_setUsuario(Cliente* this,char* usuario)
{
	strcpy(this->usuario,usuario);
	return 0;
}

char* cliente_getUsuario(Cliente* this)
{
	return this->usuario;
}

void cliente_imprimir(void* pCliente) //cambiar nombre entidad
{

    if(pCliente != NULL)
        {
            printf("ID: %d - NOMBRE: %s - APELLIDO: %s- GENERO: %c - PROFESION: %s \n - EMAIL: %s - USUARIO: %s- NACIONALIDAD: %s\n",
                   cliente_getId(pCliente),cliente_getNombre(pCliente),cliente_getApellido(pCliente),cliente_getGenero(pCliente),
                   cliente_getProfesion(pCliente),cliente_getEmail(pCliente),cliente_getUsuario(pCliente),cliente_getNacionalidad(pCliente));
        }
}


