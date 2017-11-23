#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Empleado.h"


Empleado* emp_new(char* nombre, int id, int estado, float salario)
{
    Empleado* nuevoEmpleado = malloc(sizeof(Empleado));
    emp_setNombre(nuevoEmpleado,nombre);
    emp_setId(nuevoEmpleado,id);
    emp_setEstado(nuevoEmpleado,estado);
    emp_setSalario(nuevoEmpleado,salario);

    return nuevoEmpleado;
}

int emp_delete(Empleado* this)
{
    free(this);
    return 0;
}


int emp_setNombre(Empleado* this,char* nombre)
{
    strcpy(this->nombre,nombre);
    return 0;
}

char* emp_getNombre(Empleado* this)
{
    return this->nombre;
}


int emp_setId(Empleado* this,int id)
{

    this->id = id;
    return 0;
}

int emp_getId(Empleado* this)
{
    return this->id;
}

int emp_setEstado(Empleado* this,int estado)
{

    this->estado = estado;
    return 0;
}

int emp_getEstado(Empleado* this)
{
    return this->estado;
}

int emp_setSalario(Empleado* this,float salario)
{

    this->salario = salario;
    return 0;
}

float emp_getSalario(Empleado* this)
{
    return this->salario;
}



Empleado* emp_findById(ArrayList* pArrayEmpleado, int id)
{
    int i;
    Empleado *auxEmpleado;
    void* retorno=NULL;

    for(i=0; i<al_len(pArrayEmpleado); i++)
    {
        auxEmpleado = al_get(pArrayEmpleado,i);
        if(id == auxEmpleado->id)
        {
            retorno = auxEmpleado;
        }
    }

    return retorno;
}

void emp_print(Empleado* this)
{
    printf("%d, %s, %f", this->id, this->nombre, this->salario);
}

void emp_aumentarSalario(void* item)
{
    Empleado* auxiliar = (Empleado*)item;
    emp_setSalario(auxiliar, emp_getSalario(auxiliar)*1.2);
}
