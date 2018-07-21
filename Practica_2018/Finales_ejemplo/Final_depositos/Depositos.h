#include "ArrayList.h"

#ifndef _DEPOSITOS_H
#define _DEPOSITOS_H
typedef struct
{
	int producto;
	char descripcion[256];
	int cantidad;
}Depositos;
#endif// _DEPOSITOS_H

Depositos* depositos_new(int producto,char* descripcion,int cantidad);
void depositos_delete(Depositos* this);
int depositos_setProducto(Depositos* this,int producto);
int depositos_setDescripcion(Depositos* this,char* descripcion);
int depositos_setCantidad(Depositos* this,int cantidad);
int depositos_getProducto(Depositos* this);
char* depositos_getDescripcion(Depositos* this);
int depositos_getCantidad(Depositos* this);
Depositos* depositos_findByProducto(ArrayList* pArray,int producto);
Depositos* depositos_findByDescripcion(ArrayList* pArray,char* descripcion);
Depositos* depositos_findByCantidad(ArrayList* pArray,int cantidad);
int depositos_compareByProducto(void* pA ,void* pB);
int depositos_compareByDescripcion(void* pA ,void* pB);
int depositos_compareByCantidad(void* pA ,void* pB);

void depositos_imprimir(void* deposito);
