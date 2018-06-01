16

********************* Cliente.h ************************

#include "ArrayList.h"

#ifndef _CLIENTE_H
#define _CLIENTE_H
typedef struct
{
	char nombre[64];
	char apellido[64];
	char email[256];
	char genero;
	char profesion[256];
	char nacionalidad[256];
	int id;
}Cliente;
#endif// _CLIENTE_H

Cliente* cliente_new(char* nombre,char* apellido,char* email,char genero,char* profesion,char* nacionalidad,int id);
void cliente_delete(Cliente* this);
int cliente_setNombre(Cliente* this,char* nombre);
int cliente_setApellido(Cliente* this,char* apellido);
int cliente_setEmail(Cliente* this,char* email);
int cliente_setGenero(Cliente* this,char genero);
int cliente_setProfesion(Cliente* this,char* profesion);
int cliente_setNacionalidad(Cliente* this,char* nacionalidad);
int cliente_setId(Cliente* this,int id);
char* cliente_getNombre(Cliente* this);
char* cliente_getApellido(Cliente* this);
char* cliente_getEmail(Cliente* this);
char cliente_getGenero(Cliente* this);
char* cliente_getProfesion(Cliente* this);
char* cliente_getNacionalidad(Cliente* this);
int cliente_getId(Cliente* this);
Cliente* cliente_findByNombre(ArrayList* pArray,char* nombre);
Cliente* cliente_findByApellido(ArrayList* pArray,char* apellido);
Cliente* cliente_findByEmail(ArrayList* pArray,char* email);
Cliente* cliente_findByGenero(ArrayList* pArray,char genero);
Cliente* cliente_findByProfesion(ArrayList* pArray,char* profesion);
Cliente* cliente_findByNacionalidad(ArrayList* pArray,char* nacionalidad);
Cliente* cliente_findById(ArrayList* pArray,int id);
int cliente_compareByNombre(void* pA ,void* pB);
int cliente_compareByApellido(void* pA ,void* pB);
int cliente_compareByEmail(void* pA ,void* pB);
int cliente_compareByGenero(void* pA ,void* pB);
int cliente_compareByProfesion(void* pA ,void* pB);
int cliente_compareByNacionalidad(void* pA ,void* pB);
int cliente_compareById(void* pA ,void* pB);


********************* Cliente.h ************************



********************* Cliente.c ************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Cliente.h"

Cliente* cliente_new(char* nombre,char* apellido,char* email,char genero,char* profesion,char* nacionalidad,int id)
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



********************* Cliente.c ************************

