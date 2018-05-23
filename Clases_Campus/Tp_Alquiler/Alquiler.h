#include "ArrayList.h"

#ifndef _ALQUILER_H
#define _ALQUILER_H
typedef struct
{
	int id;
	int idCliente;
	int estado;
	int idEquipo;
	int idOperador;
	int tiempoEstimado;
	int tiempoReal;
}Alquiler;
#endif// _ALQUILER_H

Alquiler* alquiler_new(int id,int idCliente,int estado,int idEquipo,int idOperador,int tiempoEstimado,int tiempoReal);
void alquiler_delete(Alquiler* this);
int alquiler_setId(Alquiler* this,int id);
int alquiler_setIdCliente(Alquiler* this,int idCliente);
int alquiler_setEstado(Alquiler* this,int estado);
int alquiler_setIdEquipo(Alquiler* this,int idEquipo);
int alquiler_setIdOperador(Alquiler* this,int idOperador);
int alquiler_setTiempoEstimado(Alquiler* this,int tiempoEstimado);
int alquiler_setTiempoReal(Alquiler* this,int tiempoReal);
int alquiler_getId(Alquiler* this);
int alquiler_getIdCliente(Alquiler* this);
int alquiler_getEstado(Alquiler* this);
int alquiler_getIdEquipo(Alquiler* this);
int alquiler_getIdOperador(Alquiler* this);
int alquiler_getTiempoEstimado(Alquiler* this);
int alquiler_getTiempoReal(Alquiler* this);
Alquiler* alquiler_findById(ArrayList* pArray,int id);
Alquiler* alquiler_findByIdCliente(ArrayList* pArray,int idCliente);
Alquiler* alquiler_findByEstado(ArrayList* pArray,int estado);
Alquiler* alquiler_findByIdEquipo(ArrayList* pArray,int idEquipo);
Alquiler* alquiler_findByIdOperador(ArrayList* pArray,int idOperador);
Alquiler* alquiler_findByTiempoEstimado(ArrayList* pArray,int tiempoEstimado);
Alquiler* alquiler_findByTiempoReal(ArrayList* pArray,int tiempoReal);
