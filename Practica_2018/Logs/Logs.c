
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Logs.h"

Logs* logs_new(char* fecha,char* hora,int id_servicio,int gravedad,char* msj_error,int id)
{
	Logs* this = malloc(sizeof(Logs));

	if(this != NULL)
	{

		logs_setFecha(this,fecha);
		logs_setHora(this,hora);
		logs_setId_servicio(this,id_servicio);
		logs_setGravedad(this,gravedad);
		logs_setMsj_error(this,msj_error);
		logs_setId(this,id);
	}
	return this;
}

void logs_delete(Logs* this)
{
	free(this);
}

int logs_setFecha(Logs* this,char* fecha)
{
	strcpy(this->fecha,fecha);
	return 0;
}

int logs_setHora(Logs* this,char* hora)
{
	strcpy(this->hora,hora);
	return 0;
}

int logs_setId_servicio(Logs* this,int id_servicio)
{
	this->id_servicio = id_servicio;
	return 0;
}

int logs_setGravedad(Logs* this,int gravedad)
{
	this->gravedad = gravedad;
	return 0;
}

int logs_setMsj_error(Logs* this,char* msj_error)
{
	strcpy(this->msj_error,msj_error);
	return 0;
}

int logs_setId(Logs* this,int id)
{
	this->id = id;
	return 0;
}

char* logs_getFecha(Logs* this)
{
	return this->fecha;
}

char* logs_getHora(Logs* this)
{
	return this->hora;
}

int logs_getId_servicio(Logs* this)
{
	return this->id_servicio;
}

int logs_getGravedad(Logs* this)
{
	return this->gravedad;
}

char* logs_getMsj_error(Logs* this)
{
	return this->msj_error;
}

int logs_getId(Logs* this)
{
	return this->id;
}

Logs* logs_findByFecha(ArrayList* pArray,char* fecha)
{

	int i;
	Logs* aux;
	Logs* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(fecha,logs_getFecha(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Logs* logs_findByHora(ArrayList* pArray,char* hora)
{

	int i;
	Logs* aux;
	Logs* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(hora,logs_getHora(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Logs* logs_findById_servicio(ArrayList* pArray,int id_servicio)
{

	int i;
	Logs* aux;
	Logs* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(id_servicio == logs_getId_servicio(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Logs* logs_findByGravedad(ArrayList* pArray,int gravedad)
{

	int i;
	Logs* aux;
	Logs* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(gravedad == logs_getGravedad(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Logs* logs_findByMsj_error(ArrayList* pArray,char* msj_error)
{

	int i;
	Logs* aux;
	Logs* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(msj_error,logs_getMsj_error(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Logs* logs_findById(ArrayList* pArray,int id)
{

	int i;
	Logs* aux;
	Logs* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(id == logs_getId(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

int logs_compareByFecha(void* pA ,void* pB)
{

	int retorno;

	retorno = strcmp(logs_getFecha(pA),logs_getFecha(pB));

	return retorno;
}

int logs_compareByHora(void* pA ,void* pB)
{

	int retorno;

	retorno = strcmp(logs_getHora(pA),logs_getHora(pB));

	return retorno;
}

int logs_compareById_servicio(void* pA ,void* pB)
{

	int retorno = 0;

	if(logs_getId_servicio(pA) > logs_getId_servicio(pB))
		retorno = 1;
	else if(logs_getId_servicio(pA) < logs_getId_servicio(pB))
		retorno = -1;

	return retorno;
}

int logs_compareByGravedad(void* pA ,void* pB)
{

	int retorno = 0;

	if(logs_getGravedad(pA) > logs_getGravedad(pB))
		retorno = 1;
	else if(logs_getGravedad(pA) < logs_getGravedad(pB))
		retorno = -1;

	return retorno;
}

int logs_compareByMsj_error(void* pA ,void* pB)
{

	int retorno;

	retorno = strcmp(logs_getMsj_error(pA),logs_getMsj_error(pB));

	return retorno;
}

int logs_compareById(void* pA ,void* pB)
{

	int retorno = 0;

	if(logs_getId(pA) > logs_getId(pB))
		retorno = 1;
	else if(logs_getId(pA) < logs_getId(pB))
		retorno = -1;

	return retorno;
}


char* logs_getMsj_error(Logs* this);
int logs_getId(Logs* this);
Logs* logs_findByFecha(ArrayList* pArray,char* fecha);
Logs* logs_findByHora(ArrayList* pArray,char* hora);
Logs* logs_findById_servicio(ArrayList* pArray,int id_servicio);
Logs* logs_findByGravedad(ArrayList* pArray,int gravedad);
Logs* logs_findByMsj_error(ArrayList* pArray,char* msj_error);
Logs* logs_findById(ArrayList* pArray,int id);
int logs_compareByFecha(void* pA ,void* pB);
int logs_compareByHora(void* pA ,void* pB);
int logs_compareById_servicio(void* pA ,void* pB);
int logs_compareByGravedad(void* pA ,void* pB);
int logs_compareByMsj_error(void* pA ,void* pB);
int logs_compareById(void* pA ,void* pB);

