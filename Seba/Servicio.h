#include "ArrayList.h"

#ifndef _SERVICIO_H
#define _SERVICIO_H
typedef struct
{
	int id;
	int idCliente;
	char cdProducto[10];
	float costo;
	char fechaIngreso[51];
	int estado;
}Servicio;
#endif// _SERVICIO_H

#define TV_LG_32 "t1"
#define PS4 1001 "p4"
#define IPHONE7 "i7"

Servicio* servicio_new(int id,int idCliente,char* cdProducto,float costo,char* fechaIngreso,int estado);
void servicio_delete(Servicio* this);
int servicio_setId(Servicio* this,int id);
int servicio_setIdCliente(Servicio* this,int idCliente);
int servicio_setCdProducto(Servicio* this,char* cdProducto);
int servicio_setCosto(Servicio* this,float costo);
int servicio_setFechaIngreso(Servicio* this,char* fechaIngreso);
int servicio_setEstado(Servicio* this,int estado);
int servicio_getId(Servicio* this);
int servicio_getIdCliente(Servicio* this);
char* servicio_getCdProducto(Servicio* this);
float servicio_getCosto(Servicio* this);
char* servicio_getFechaIngreso(Servicio* this);
int servicio_getEstado(Servicio* this);
Servicio* servicio_findById(ArrayList* pArray,int id);
Servicio* servicio_findByIdCliente(ArrayList* pArray,int idCliente);
Servicio* servicio_findByCdProducto(ArrayList* pArray,char* cdProducto);
Servicio* servicio_findByCosto(ArrayList* pArray,float costo);
Servicio* servicio_findByFechaIngreso(ArrayList* pArray,char* fechaIngreso);
Servicio* servicio_findByEstado(ArrayList* pArray,int estado);
int servicio_compareById(void* pA ,void* pB);
int servicio_compareByIdCliente(void* pA ,void* pB);
int servicio_compareByCdProducto(void* pA ,void* pB);
int servicio_compareByCosto(void* pA ,void* pB);
int servicio_compareByFechaIngreso(void* pA ,void* pB);
int servicio_compareByEstado(void* pA ,void* pB);
