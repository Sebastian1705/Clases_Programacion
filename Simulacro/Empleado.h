#include "ArrayList.h"

#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED
typedef struct
{
    int id;
    char nombre[51];
    float salario;
    int estado;

}Empleado;
#endif // SOCIO_H_INCLUDED

#define SOCIO_ESTADO_ACTIVO 0
#define SOCIO_ESTADO_INACTIVO 1

Empleado* emp_new(char* nombre, int id, int estado, float salario);


int emp_delete(Empleado*);

int emp_setNombre(Empleado*,char* nombre);
char* emp_getNombre(Empleado*);

int emp_setId(Empleado* this,int id);
int emp_getId(Empleado* this);

int emp_setEstado(Empleado* this,int estado);
int emp_getEstado(Empleado* this);

float emp_getSalario(Empleado* this);
int emp_setSalario(Empleado* this,float salario);

Empleado* emp_findById(ArrayList* pArrayEmpleado, int id);


void emp_print(Empleado* this);
void emp_aumentarSalario(void* item);
