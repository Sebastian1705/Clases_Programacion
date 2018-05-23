#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Servicios.h"


Servicio* ser_new(char* descripcion, int id, int estado)
{
    Servicio* nuevoServicio = malloc(sizeof(Servicio));
    ser_setDescripcion(nuevoServicio,descripcion);
    ser_setId(nuevoServicio,id);
    ser_setEstado(nuevoServicio,estado);

    return nuevoServicio;
}


int ser_delete(Servicio* this)
{
    free(this);
    return 0;
}


int ser_setDescripcion(Servicio* this,char* descripcion)
{
    strcpy(this->descripcion,descripcion);
    return 0;
}


char* ser_getDescripcion(Servicio* this)
{
    return this->descripcion;
}


int ser_setId(Servicio* this,int id)
{

    this->id = id;
    return 0;
}

int ser_getId(Servicio* this)
{
    return this->id;
}

int ser_setEstado(Servicio* this,int estado)
{

    this->estado = estado;
    return 0;
}

int ser_getEstado(Servicio* this)
{
    return this->estado;
}


Servicio* ser_findById(ArrayList* pArrayServicio, int id)
{
    int i;
    Servicio *auxServicio;
    void* retorno=NULL;

    for(i=0;i<al_len(pArrayServicio);i++)
    {
        auxServicio = al_get(pArrayServicio,i);
        if(id == auxServicio->id)
        {
            retorno = auxServicio;
        }
    }

    return retorno;
}




