#include "ArrayList.h"
#ifndef _ENTREGA_H
#define _ENTREGA_H
typedef struct
{
        int id;
        char producto[50];
        char direccion[50];
        char localidad[50];
        char recibe[50];
}Entrega;
#endif// _ENTREGA_H

Entrega* entrega_new(int id,char* producto,char* direccion,char* localidad,char*
 recibe);
void entrega_delete(Entrega* this);
int entrega_setId(Entrega* this,int id);
int entrega_setProducto(Entrega* this,char* producto);
int entrega_setDireccion(Entrega* this,char* direccion);
int entrega_setLocalidad(Entrega* this,char* localidad);
int entrega_setRecibe(Entrega* this,char* recibe);
int entrega_getId(Entrega* this);
char* entrega_getProducto(Entrega* this);
char* entrega_getDireccion(Entrega* this);
char* entrega_getLocalidad(Entrega* this);
char* entrega_getRecibe(Entrega* this);
Entrega* entrega_findById(ArrayList* pArray,int id);
Entrega* entrega_findByProducto(ArrayList* pArray,char* producto);
Entrega* entrega_findByDireccion(ArrayList* pArray,char* direccion);
Entrega* entrega_findByLocalidad(ArrayList* pArray,char* localidad);
Entrega* entrega_findByRecibe(ArrayList* pArray,char* recibe);


