#include "ArrayList.h"

#ifndef _VENTAS_H
#define _VENTAS_H
typedef struct
{
	int id_ventas;
	int id_clientes;
	int codProducto;
	int cantidad;
	float precioUnitario;
	int estado;
}Ventas;
#endif// _VENTAS_H
#define PRECIO_IPHONE7 19498.99
#define PRECIO_PS4 12999.99
#define PRECIO_TV_LG_32 8999.99
#define IPHONE7 1002
#define PS4 1001
#define TV_LG_32 1000
#define VENTA_ACTIVA 1
#define VENTA_BAJA 0

Ventas* ventas_new(int id_ventas,int id_clientes,int codProducto,int cantidad,float precioUnitario,int estado);
void ventas_delete(Ventas* this);
int ventas_setId_ventas(Ventas* this,int id_ventas);
int ventas_setId_clientes(Ventas* this,int id_clientes);
int ventas_setCodProducto(Ventas* this,int codProducto);
int ventas_setCantidad(Ventas* this,int cantidad);
int ventas_setPrecioUnitario(Ventas* this,float precioUnitario);
int ventas_setEstado(Ventas* this,int estado);
int ventas_getId_ventas(Ventas* this);
int ventas_getId_clientes(Ventas* this);
int ventas_getCodProducto(Ventas* this);
int ventas_getCantidad(Ventas* this);
float ventas_getPrecioUnitario(Ventas* this);
int ventas_getEstado(Ventas* this);
Ventas* ventas_findById_ventas(ArrayList* pArray,int id_ventas);
Ventas* ventas_findById_clientes(ArrayList* pArray,int id_clientes);
Ventas* ventas_findByCodProducto(ArrayList* pArray,int codProducto);
Ventas* ventas_findByCantidad(ArrayList* pArray,int cantidad);
Ventas* ventas_findByPrecioUnitario(ArrayList* pArray,float precioUnitario);
Ventas* ventas_findByEstado(ArrayList* pArray,int estado);
int ventas_compareById_ventas(void* pA ,void* pB);
int ventas_compareById_clientes(void* pA ,void* pB);
int ventas_compareByCodProducto(void* pA ,void* pB);
int ventas_compareByCantidad(void* pA ,void* pB);
int ventas_compareByPrecioUnitario(void* pA ,void* pB);
int ventas_compareByEstado(void* pA ,void* pB);

void ventas_imprimir(void* pVentas);
