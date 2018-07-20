#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personas.h"


int persona_compareName(void* pEmployeeA,void* pEmployeeB)
{
    int retorno=0;
    if (strcmp(((eEmpleado*)pEmployeeA)->name,((eEmpleado*)pEmployeeB)->name)==1 )
    {
        retorno=1;
    }
    if (strcmp(((eEmpleado*)pEmployeeA)->name,((eEmpleado*)pEmployeeB)->name)==-1)
    {
        retorno=-1;
    }

    return retorno;
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int persona_calcularSueldo(void* pEmployeeA)
{
    int retorno=0;
    int valor120=(120*180);
    int valor160=((40)*240)+valor120;
    int aux;

    if (((eEmpleado*)pEmployeeA)->horas >=80 && ((eEmpleado*)pEmployeeA)->horas <=120)
    {
        aux=((((eEmpleado*)pEmployeeA)->horas)*180);
        retorno =1;
    }

    else if (((eEmpleado*)pEmployeeA)->horas >120 && ((eEmpleado*)pEmployeeA)->horas  <=160)
    {
        aux=valor120+(((((eEmpleado*)pEmployeeA)->horas)-120)*240);
        retorno =1;
    }

    else if (((eEmpleado*)pEmployeeA)->horas  >160 && ((eEmpleado*)pEmployeeA)->horas <=240)
    {
        aux=valor160+(((((eEmpleado*)pEmployeeA)->horas)-160)*350);
        retorno =1;
    }
    else
    {
        aux=0;
    }

    persona_setSueldo((eEmpleado*)pEmployeeA, aux);

    return retorno;
}



/** \brief Set this employee the values recived as parameters
 *
 * \param pEmployee employee*
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
eEmpleado* persona_newUnaPersona()
{
    eEmpleado* returnAux = NULL;
    eEmpleado* pEmployee = malloc(sizeof(eEmpleado));

    if(pEmployee != NULL)
    {
        returnAux = pEmployee;
    }

    return returnAux;

}


/** \brief Set this eEmpleado the values recived as parameters
 *
 * \param pEmployee eEmpleado*
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
eEmpleado* persona_newPersona(int id, char name[],char direccion[],int hora)
{
    eEmpleado* returnAux = NULL;
    eEmpleado* pEmployee = malloc(sizeof(eEmpleado));

    if(pEmployee != NULL)
    {
        pEmployee->id = id;
        strcpy(pEmployee->name,name);
        strcpy(pEmployee->direccion,direccion);
        pEmployee->horas =hora;
        pEmployee->sueldo=0;
        returnAux = pEmployee;
    }

    return returnAux;

}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int persona_setNombre(eEmpleado* this,char* nombre)
{
    strcpy(this->name,nombre);
    return 0;
}

char* persona_getNombre(eEmpleado* this)
{
    return this->name;
}

char* persona_getDireccion(eEmpleado* this)
{
    return this->direccion;
}


int persona_setDireccion(eEmpleado* this,char* direccion)
{
    strcpy(this->direccion,direccion);
    return 0;
}


int persona_setId(eEmpleado* this,int id)
{
    this->id = id;
    return 0;
}

int persona_getId(eEmpleado* this)
{
    return this->id;
}

int persona_setSueldo(eEmpleado* this,int sueldo)
{
    this->sueldo= sueldo;
    return 0;
}

int persona_getSueldo(eEmpleado* this)
{
    return this->sueldo;
}

int persona_setHoras(eEmpleado* this,int horas)
{
    this->horas =horas;
    return 0;
}

int persona_getHoras(eEmpleado* this)
{
    return this->horas;
}


void persona_printPersona(eEmpleado*this)
{
    printf("ID %d\tNombre:%s\tDireccion:%s\t Horas Trabajadas:%d\t Sueldo:%d\n",persona_getId(this), persona_getNombre(this), persona_getDireccion(this), persona_getHoras(this), persona_getSueldo(this));
}


