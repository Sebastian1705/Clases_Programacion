#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Logs.h"

Logs* logs_new(int id,char* date,char* time,int serviceId,int gravedad,char* msg)
{
	Logs* this = malloc(sizeof(Logs));

	if(this != NULL)
	{

		logs_setId(this,id);
		logs_setDate(this,date);
		logs_setTime(this,time);
		logs_setServiceId(this,serviceId);
		logs_setGravedad(this,gravedad);
		logs_setMsg(this,msg);
	}
	return this;
}

void logs_delete(Logs* this)
{
	free(this);
}

int logs_setId(Logs* this,int id)
{
	this->id = id;
	return 0;
}

int logs_setDate(Logs* this,char* date)
{
	strcpy(this->date,date);
	return 0;
}

int logs_setTime(Logs* this,char* time)
{
	strcpy(this->time,time);
	return 0;
}

int logs_setServiceId(Logs* this,int serviceId)
{
	this->serviceId = serviceId;
	return 0;
}

int logs_setGravedad(Logs* this,int gravedad)
{
	this->gravedad = gravedad;
	return 0;
}

int logs_setMsg(Logs* this,char* msg)
{
	strcpy(this->msg,msg);
	return 0;
}

int logs_getId(Logs* this)
{
	return this->id;
}

char* logs_getDate(Logs* this)
{
	return this->date;
}

char* logs_getTime(Logs* this)
{
	return this->time;
}

int logs_getServiceId(Logs* this)
{
	return this->serviceId;
}

int logs_getGravedad(Logs* this)
{
	return this->gravedad;
}

char* logs_getMsg(Logs* this)
{
	return this->msg;
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

Logs* logs_findByDate(ArrayList* pArray,char* date)
{

	int i;
	Logs* aux;
	Logs* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(date,logs_getDate(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Logs* logs_findByTime(ArrayList* pArray,char* time)
{

	int i;
	Logs* aux;
	Logs* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(time,logs_getTime(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Logs* logs_findByServiceId(ArrayList* pArray,int serviceId)
{

	int i;
	Logs* aux;
	Logs* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(serviceId == logs_getServiceId(aux))
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

Logs* logs_findByMsg(ArrayList* pArray,char* msg)
{

	int i;
	Logs* aux;
	Logs* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(msg,logs_getMsg(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
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

int logs_compareByDate(void* pA ,void* pB)
{

	int retorno;

	retorno = strcmp(logs_getDate(pA),logs_getDate(pB));

	return retorno;
}

int logs_compareByTime(void* pA ,void* pB)
{

	int retorno;

	retorno = strcmp(logs_getTime(pA),logs_getTime(pB));

	return retorno;
}

int logs_compareByServiceId(void* pA ,void* pB)
{

	int retorno = 0;

	if(logs_getServiceId(pA) > logs_getServiceId(pB))
		retorno = 1;
	else if(logs_getServiceId(pA) < logs_getServiceId(pB))
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

int logs_compareByMsg(void* pA ,void* pB)
{

	int retorno;

	retorno = strcmp(logs_getMsg(pA),logs_getMsg(pB));

	return retorno;
}

