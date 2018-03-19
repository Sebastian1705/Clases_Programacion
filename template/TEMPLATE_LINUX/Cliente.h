#include "ArrayList.h"

#ifndef _CLIENTE_H
#define _CLIENTE_H
typedef struct
{
	char nombre[50];
	char apellido[50];
	char dni[9];
	int id;
}Cliente;
#endif// _CLIENTE_H

Cliente* cliente_new(char* nombre,char* apellido,char* dni,int id);
void cliente_delete(Cliente* this);
int cliente_setNombre(Cliente* this,char* nombre);
int cliente_setApellido(Cliente* this,char* apellido);
int cliente_setDni(Cliente* this,char* dni);
int cliente_setId(Cliente* this,int id);
char* cliente_getNombre(Cliente* this);
char* cliente_getApellido(Cliente* this);
char* cliente_getDni(Cliente* this);
int cliente_getId(Cliente* this);
Cliente* cliente_findByNombre(ArrayList* pArray,char* nombre);
Cliente* cliente_findByApellido(ArrayList* pArray,char* apellido);
Cliente* cliente_findByDni(ArrayList* pArray,char* dni);
Cliente* cliente_findById(ArrayList* pArray,int id);
int cliente_compareByNombre(void* pA ,void* pB);
int cliente_compareByApellido(void* pA ,void* pB);
int cliente_compareByDni(void* pA ,void* pB);
int cliente_compareById(void* pA ,void* pB);
