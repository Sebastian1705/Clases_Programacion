#include "ArrayList.h"
#ifndef _ALQUILER_H
#define _ALQUILER_H
typedef struct
{
        int id;
        int idCliente;
        int equipo;
        int estado;
}Alquiler;
#endif// _ALQUILERl_H

#define ALQUILER_ESTADO_ACTIVO 1
#define ALQUILER_ESTADO_FINALIZADO 0

#define AMOLADORA 0
#define MEZCLADORA 1
#define TALADRO 2

Alquiler* alquiler_new(int id,int idCliente,int equipo,int estado);
void alquiler_delete(Alquiler* this);
int alquiler_setId(Alquiler* this,int id);
int alquiler_setIdCliente(Alquiler* this,int idCliente);
int alquiler_setEquipo(Alquiler* this,int equipo);
int alquiler_setEstado(Alquiler* this,int estado);
int alquiler_getId(Alquiler* this);
int alquiler_getIdCliente(Alquiler* this);
int alquiler_getEquipo(Alquiler* this);
int alquiler_getEstado(Alquiler* this);
Alquiler* alquiler_findById(ArrayList* pArray,int id);
Alquiler* alquiler_findByIdCliente(ArrayList* pArray,int idCliente);
Alquiler* alquiler_findByEquipo(ArrayList* pArray,int equipo);
Alquiler* alquiler_findByEstado(ArrayList* pArray,int estado);
int alquiler_compareById(void* pA ,void* pB);
int alquiler_compareByIdCliente(void* pA ,void* pB);
int alquiler_compareByIdEquipo(void* pA ,void* pB);
int alquiler_compareByEstado(void* pA ,void* pB);




/********************************************************/

void alquiler_imprimir(void* pAlquiler); //cambiar nombre entidad
