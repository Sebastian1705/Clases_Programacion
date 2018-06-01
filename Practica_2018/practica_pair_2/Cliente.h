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
	char usuario[64];
}Cliente;
#endif// _CLIENTE_H

Cliente* cliente_new(char* nombre,char* apellido,char* email,char genero,char* profesion,char* nacionalidad,int id,char* usuario);
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

int cliente_setUsuario(Cliente* this,char* usuario);
char* cliente_getUsuario(Cliente* this);
void cliente_imprimir(void* pCliente);
