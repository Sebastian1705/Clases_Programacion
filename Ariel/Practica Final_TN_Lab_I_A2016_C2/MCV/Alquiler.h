#include "ArrayList.h"
#ifndef _ALQUILER_H
#define _ALQUILER_H
typedef struct
{
        int id;
        int idCliente;
        int equipo;
        int estado;
        int tiempoEstimado;
        int tiempoReal;
}Alquiler;
#endif// _ALQUILERl_H

#define ESTADO_ALQUILADO 0
#define ESTADO_FINALIZADO 1

#define AMOLADORA 0
#define MEZCLADORA 1
#define TALADRO 2

Alquiler* alquiler_new(int id,int idCliente,int equipo,int estado,int tiempoEstimado, int tiempoReal);
void alquiler_delete(Alquiler* this);
int alquiler_setId(Alquiler* this,int id);
int alquiler_setIdCliente(Alquiler* this,int idCliente);
int alquiler_setEquipo(Alquiler* this,int equipo);
int alquiler_setEstado(Alquiler* this,int estado);
int alquiler_setTiempoEstimado(Alquiler* this,int tiempoEstimado);
int alquiler_setTiempoReal(Alquiler* this,int tiempoReal);
int alquiler_getId(Alquiler* this);
int alquiler_getIdCliente(Alquiler* this);
int alquiler_getEquipo(Alquiler* this);
int alquiler_getEstado(Alquiler* this);
int alquiler_getTiempoEstimado(Alquiler* this);
int alquiler_getTiempoReal(Alquiler* this);
Alquiler* alquiler_findById(ArrayList* pArray,int id);
Alquiler* alquiler_findByIdCliente(ArrayList* pArray,int idCliente);
Alquiler* alquiler_findByEquipo(ArrayList* pArray,int equipo);
Alquiler* alquiler_findByEstado(ArrayList* pArray,int estado);
Alquiler* alquiler_findByTiempoEstimado(ArrayList* pArray,int tiempoEstimado);
Alquiler* alquiler_findByTiempoReal(ArrayList* pArray,int tiempoReal);

int alquiler_calcularCantidadAlquileres(int id);
