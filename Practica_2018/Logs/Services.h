#include "ArrayList.h"

#ifndef _SERVICES0_H
#define _SERVICES0_H
typedef struct
{
	int id;
	char nombre[50];
	char email[50];
}Services;
#endif// _SERVICES0_H

Services* services_new(int id,char* nombre,char* email);
void services_delete(Services* this);
int services_setId(Services* this,int id);
int services_setNombre(Services* this,char* nombre);
int services_setEmail(Services* this,char* email);
int services_getId(Services* this);
char* services_getNombre(Services* this);
char* services_getEmail(Services* this);
Services* services_findById(ArrayList* pArray,int id);
Services* services_findByNombre(ArrayList* pArray,char* nombre);
Services* services_findByEmail(ArrayList* pArray,char* email);
int services_compareById(void* pA ,void* pB);
int services_compareByNombre(void* pA ,void* pB);
int services_compareByEmail(void* pA ,void* pB);
