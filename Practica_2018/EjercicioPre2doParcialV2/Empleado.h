#include "ArrayList.h"

#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Empleado;

void em_calcularSueldo(void* p);

#endif // EMPLEADO_H_INCLUDED

Empleado* empleado_new(int id,char* nombre,int horasTrabajadas,int sueldo);
void empleado_delete(Empleado* this);
int empleado_setId(Empleado* this,int id);
int empleado_setNombre(Empleado* this,char* nombre);
int empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas);
int empleado_setSueldo(Empleado* this,int sueldo);
int empleado_getId(Empleado* this);
char* empleado_getNombre(Empleado* this);
int empleado_getHorasTrabajadas(Empleado* this);
int empleado_getSueldo(Empleado* this);
Empleado* empleado_findById(ArrayList* pArray,int id);
Empleado* empleado_findByNombre(ArrayList* pArray,char* nombre);
Empleado* empleado_findByHorasTrabajadas(ArrayList* pArray,int horasTrabajadas);
Empleado* empleado_findBySueldo(ArrayList* pArray,int sueldo);
int empleado_compareById(void* pA ,void* pB);
int empleado_compareByNombre(void* pA ,void* pB);
int empleado_compareByHorasTrabajadas(void* pA ,void* pB);
int empleado_compareBySueldo(void* pA ,void* pB);
