#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Alquiler.h"

Alquiler* alquiler_new(int id,int idCliente,int equipo,int estado,int tiempoEstimado, int tiempoReal)
{
    Alquiler* this = malloc(sizeof(Alquiler));

    if(this != NULL)
    {

        alquiler_setId(this,id);
        alquiler_setIdCliente(this,idCliente);
        alquiler_setEquipo(this,equipo);
        alquiler_setEstado(this,estado);
        alquiler_setTiempoEstimado(this,tiempoEstimado);
        alquiler_setTiempoReal(this,tiempoReal);
    }
    return this;
}

void alquiler_delete(Alquiler* this)
{
    free(this);
}

int alquiler_setId(Alquiler* this,int id)
{
    this->id = id;
    return 0;
}

int alquiler_setIdCliente(Alquiler* this,int idCliente)
{
    this->idCliente = idCliente;
    return 0;
}

int alquiler_setEquipo(Alquiler* this,int equipo)
{
    this->equipo = equipo;
    return 0;
}

int alquiler_setEstado(Alquiler* this,int estado)
{
    this->estado = estado;
    return 0;
}

int alquiler_setTiempoEstimado(Alquiler* this,int tiempoEstimado)
{
    this->tiempoEstimado = tiempoEstimado;
    return 0;
}

int alquiler_setTiempoReal(Alquiler* this,int tiempoReal)
{
    this->tiempoReal = tiempoReal;
    return 0;
}

int alquiler_getId(Alquiler* this)
{
    return this->id;
}

int alquiler_getIdCliente(Alquiler* this)
{
    return this->idCliente;
}

int alquiler_getEquipo(Alquiler* this)
{
    return this->equipo;
}

int alquiler_getEstado(Alquiler* this)
{
    return this->estado;
}

int alquiler_getTiempoEstimado(Alquiler* this)
{
    return this->tiempoEstimado;
}

int alquiler_getTiempoReal(Alquiler* this)
{
    return this->tiempoReal;
}

Alquiler* alquiler_findById(ArrayList* pArray,int id)
{

    int i;
    Alquiler* aux;
    Alquiler* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(id == alquiler_getId(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Alquiler* alquiler_findByIdCliente(ArrayList* pArray,int idCliente)
{

    int i;
    Alquiler* aux;
    Alquiler* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(idCliente == alquiler_getIdCliente(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Alquiler* alquiler_findByEquipo(ArrayList* pArray,int equipo)
{

    int i;
    Alquiler* aux;
    Alquiler* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(equipo == alquiler_getEquipo(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Alquiler* alquiler_findByEstado(ArrayList* pArray,int estado)
{

    int i;
    Alquiler* aux;
    Alquiler* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(estado == alquiler_getEstado(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Alquiler* alquiler_findByTiempoEstimado(ArrayList* pArray,int tiempoEstimado)
{

    int i;
    Alquiler* aux;
    Alquiler* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(tiempoEstimado == alquiler_getTiempoEstimado(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Alquiler* alquiler_findByTiempoReal(ArrayList* pArray,int tiempoReal)
{

    int i;
    Alquiler* aux;
    Alquiler* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(tiempoReal == alquiler_getTiempoReal(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}





