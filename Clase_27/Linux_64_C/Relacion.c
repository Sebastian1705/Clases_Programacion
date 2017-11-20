#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Relacion.h"

Relacion* rel_new(int idServicio, int idSocio, int id, int estado)
{
    Relacion* nuevaRelacion = malloc(sizeof(Relacion));
    rel_setId(nuevaRelacion,id);
    rel_setIdSocio(nuevaRelacion,idSocio);
    rel_setIdServicio(nuevaRelacion,idServicio);
    rel_setEstado(nuevaRelacion, estado);
    return nuevaRelacion;
}

int rel_delete(Relacion* this)
{
    free(this);
    return 0;
}

int rel_setId(Relacion* this,int id)
{

    this->id = id;
    return 0;
}

int rel_getId(Relacion* this)
{
    return this->id;
}

int rel_setEstado(Relacion* this,int estado)
{

    this->estado = estado;
    return 0;
}

int rel_getEstado(Relacion* this)
{
    return this->estado;
}


int rel_setIdSocio(Relacion* this,int id)
{

    this->idSocio = id;
    return 0;
}

int rel_getIdSocio(Relacion* this)
{
    return this->idSocio;
}

int rel_setIdServicio(Relacion* this,int id)
{

    this->idServicio = id;
    return 0;
}

int rel_getIdServicio(Relacion* this)
{
    return this->idServicio;
}

Relacion* rel_findById(ArrayList* pArrayRelaciones, int id)
{
    int i;
    Relacion *auxRelacion;
    void* retorno=NULL;

    for(i=0;i<al_len(pArrayRelaciones);i++)
    {
        auxRelacion = al_get(pArrayRelaciones,i);
        if(id == auxRelacion->id)
        {
            retorno = auxRelacion;
        }
    }

    return retorno;
}




