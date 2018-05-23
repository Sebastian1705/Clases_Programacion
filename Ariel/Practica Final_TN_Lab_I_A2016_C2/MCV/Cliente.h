#include "ArrayList.h"

#ifndef _CLIENTE_H
#define _CLIENTE_H
typedef struct
{
        int id;
        char nombre[50];
        char apellido[50];
        int estado;
        char dni[50];
}Cliente;
#define CLIENTE_ESTADO_ACTIVO 1
#define CLIENTE_ESTADO_INACTIVO 0
#endif// _CLIENTE_H

Cliente* cliente_new(int id,char* nombre,char* apellido,int estado,char* dni);
void cliente_delete(Cliente* this);
int cliente_setId(Cliente* this,int id);
int cliente_setNombre(Cliente* this,char* nombre);
int cliente_setApellido(Cliente* this,char* apellido);
int cliente_setEstado(Cliente* this,int estado);
int cliente_setDni(Cliente* this,char* dni);
int cliente_getId(Cliente* this);
char* cliente_getNombre(Cliente* this);
char* cliente_getApellido(Cliente* this);
int cliente_getEstado(Cliente* this);
char* cliente_getDni(Cliente* this);
Cliente* cliente_findById(ArrayList* pArray,int id);
Cliente* cliente_findByNombre(ArrayList* pArray,char* nombre);
Cliente* cliente_findByApellido(ArrayList* pArray,char* apellido);
Cliente* cliente_findByEstado(ArrayList* pArray,int estado);
Cliente* cliente_findByDni(ArrayList* pArray,char* dni);
int cliente_compareByIdCliente(void* pA ,void* pB);
int cliente_compareByNombre(void* pA ,void* pB);
int cliente_compareByApellido(void* pA ,void* pB);
int cliente_compareByDni(void* pA ,void* pB);
int cliente_compareByEstado(void* pA ,void* pB);
