#include "ArrayList.h"

#ifndef _CLIENTE_H
#define _CLIENTE_H
typedef struct
{
        int id;
        char nombre[51];
        char apellido[51];
        char dni[10];
        int estado;
}Cliente;
#endif// _CLIENTE_H
#define CLIENTE_ESTADO_ACTIVO 1
#define CLIENTE_ESTADO_INACTIVO 0

Cliente* cliente_new(int id,char* nombre,char* apellido,char* dni,int estado);
void cliente_delete(Cliente* this);
int cliente_setId(Cliente* this,int id);
int cliente_setNombre(Cliente* this,char* nombre);
int cliente_setApellido(Cliente* this,char* apellido);
int cliente_setDni(Cliente* this,char* dni);
int cliente_setEstado(Cliente* this,int estado);
int cliente_getId(Cliente* this);
char* cliente_getNombre(Cliente* this);
char* cliente_getApellido(Cliente* this);
char* cliente_getDni(Cliente* this);
int cliente_getEstado(Cliente* this);
Cliente* cliente_findById(ArrayList* pArray,int id);
Cliente* cliente_findByNombre(ArrayList* pArray,char* nombre);
Cliente* cliente_findByApellido(ArrayList* pArray,char* apellido);
Cliente* cliente_findByDni(ArrayList* pArray,char* dni);
Cliente* cliente_findByEstado(ArrayList* pArray,int estado);



