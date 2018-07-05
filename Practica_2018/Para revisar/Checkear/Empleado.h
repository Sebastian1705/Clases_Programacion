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
Empleado* emp_newParametros(char* nombre, char* STRhorasTrabajadas, char* STRid);
Empleado* emp_new(void);
void emp_delete(Empleado* this);
int emp_setNombre(Empleado* this, char* nombre);
int emp_getNombre(Empleado* this, char* nombre);
int emp_setHorasTrabajadas(Empleado* this, int horasTrabajadas);
int emp_getHorasTrabajadas(Empleado* this, int* horasTrabajadas);
int emp_getId(Empleado* this, int* id);
int emp_setId(Empleado* this, int id);
int emp_setSueldo(Empleado* this, int sueldo);
int emp_getSueldo(Empleado* this, int* sueldo);

#endif // EMPLEADO_H_INCLUDED
