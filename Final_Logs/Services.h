
#include "ArrayList.h"

#ifndef _SERVICES_H
#define _SERVICES_H
typedef struct
{
	int id;
	char name[33];
	char email[65];
}Services;
#endif// _SERVICES_H

Services* services_new(int id,char* name,char* email);
void services_delete(Services* this);
int services_setId(Services* this,int id);
int services_setName(Services* this,char* name);
int services_setEmail(Services* this,char* email);
int services_getId(Services* this);
char* services_getName(Services* this);
char* services_getEmail(Services* this);
Services* services_findById(ArrayList* pArray,int id);
Services* services_findByName(ArrayList* pArray,char* name);
Services* services_findByEmail(ArrayList* pArray,char* email);
int services_compareById(void* pA ,void* pB);
int services_compareByName(void* pA ,void* pB);
int services_compareByEmail(void* pA ,void* pB);
