
#include "ArrayList.h"

#ifndef _CLIENTE_H
#define _CLIENTE_H
typedef struct
{
	char nombre[50];
	char apellido[50];
	char dni[10];
	int id;
	int estado;
}Cliente;
#endif// _CLIENTE_H
#define CLIENTE_ALTA 1
#define CLIENTE_BAJA 0

Cliente* cliente_new(char* nombre,char* apellido,char* dni,int id,int estado);
void cliente_delete(Cliente* this);
int cliente_setNombre(Cliente* this,char* nombre);
int cliente_setApellido(Cliente* this,char* apellido);
int cliente_setDni(Cliente* this,char* dni);
int cliente_setId(Cliente* this,int id);
int cliente_setEstado(Cliente* this,int estado);
char* cliente_getNombre(Cliente* this);
char* cliente_getApellido(Cliente* this);
char* cliente_getDni(Cliente* this);
int cliente_getId(Cliente* this);
int cliente_getEstado(Cliente* this);
Cliente* cliente_findByNombre(ArrayList* pArray,char* nombre);
Cliente* cliente_findByApellido(ArrayList* pArray,char* apellido);
Cliente* cliente_findByDni(ArrayList* pArray,char* dni);
Cliente* cliente_findById(ArrayList* pArray,int id);
Cliente* cliente_findByEstado(ArrayList* pArray,int estado);
int cliente_compareByNombre(void* pA ,void* pB);
int cliente_compareByApellido(void* pA ,void* pB);
int cliente_compareByDni(void* pA ,void* pB);
int cliente_compareById(void* pA ,void* pB);
int cliente_compareByEstado(void* pA ,void* pB);

void cliente_imprimir(void* pCliente);


