#include "Empleado.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ArrayList.h"

static int isValidNombre(char* nombre){
    return 1;
}

static int isValidHorasTrabajadas(int horasTrabajadas){
    return 1;
}
static int isValidSueldo(int sueldo){
return 1;
}
int em_setId(Empleado* this, int id);

void em_calcularSueldo(void* p)
{
    int auxHorasTrabajadas;
    int sueldoAux=-1;
    Empleado* auxEmpleado;
    auxEmpleado=(Empleado*)p;
    emp_getHorasTrabajadas(auxEmpleado, &auxHorasTrabajadas);
    if(auxHorasTrabajadas <= 120)
    {
        sueldoAux=(180*auxHorasTrabajadas);
    }
    else if(auxHorasTrabajadas <= 160)
    {
       sueldoAux=(((auxHorasTrabajadas-120)*240)+(120*180));
    }
    else if(auxHorasTrabajadas <= 240)
    {
       sueldoAux=((auxHorasTrabajadas-160)*350)+(120*180)+(40*240);
    }
    emp_setSueldo(auxEmpleado, sueldoAux);

}

Empleado* emp_new(void)
{

    Empleado* returnAux = (Empleado*) malloc(sizeof(Empleado));

    return returnAux;

}

Empleado* emp_newParametros(char* nombre, char* STRhorasTrabajadas, char* STRid)
{
    //validar que todos los punteros no sean null
    int id;
    int horasTrabajadas;
    Empleado* this = NULL;
    this = emp_new();
    horasTrabajadas=atoi(STRhorasTrabajadas);
    id=atoi(STRid);
    //resto de los setters (nombre, email, isempty)
    if(!emp_setNombre(this, nombre) &&
       !emp_setHorasTrabajadas(this, horasTrabajadas)
       && !emp_setId(this, id)){
        return this;
    }
    emp_delete(this);
    return NULL;
}


void emp_delete(Empleado* this)
{
    if(this != NULL) free(this);
}
//////////////////////////////////////////////////////////////////////




int emp_setNombre(Empleado* this, char* nombre){
    int retorno = -1;
    if(this != NULL && nombre != NULL && isValidNombre(nombre)){
        retorno = 0;
        strcpy(this->nombre, nombre);

    }
    return retorno;
}

int emp_getNombre(Empleado* this, char* nombre){
    int retorno = -1;
    if(this != NULL && nombre != NULL){
        retorno = 0;
        strcpy(nombre, this->nombre);

    }
    return retorno;
}


int emp_setHorasTrabajadas(Empleado* this, int horasTrabajadas){
    int retorno = -1;
    if(this != NULL && isValidHorasTrabajadas(horasTrabajadas)){
        retorno = 0;
        this->horasTrabajadas = horasTrabajadas;

    }
    return retorno;
}


int emp_getHorasTrabajadas(Empleado* this, int* horasTrabajadas){
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL){
        retorno = 0;
        *horasTrabajadas = this->horasTrabajadas;
    }
    return retorno;
}

int emp_getId(Empleado* this, int* id){
    int retorno = -1;
    if(this != NULL && id != NULL){
        retorno = 0;
        *id= this->id;
    }
    return retorno;
}

int emp_setId(Empleado* this, int id)
{
    int retorno = -1;
    static int ultimoId = -1;
    if(this != NULL)
    {
        if(id == -1)
        {
            ultimoId++;
            this->id = ultimoId;
            retorno = 0;
        }
        if(id > ultimoId)
        {
            this->id = id;
            ultimoId = id;
            retorno = 0;
        }
    }
    return retorno;
}

int emp_setSueldo(Empleado* this, int sueldo)
{
    int retorno = -1;
    if(this != NULL && isValidSueldo(sueldo))
    {
        retorno=0;
        this->sueldo=sueldo;
    }
    return retorno;

}
int emp_getSueldo(Empleado* this, int* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        retorno=0;
        *sueldo=this->sueldo;
    }
    return retorno;
}

