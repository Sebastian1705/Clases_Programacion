#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "RelSocioServicio.h"


RelSocioServicio* relSyS_new(int id, int idSocio, int idServicio, int estado)
{
    RelSocioServicio* nuevoRelSocioServicio = malloc(sizeof(RelSocioServicio));
    relSyS_setId(nuevoRelSocioServicio,id);
    relSyS_setIdSocio(nuevoRelSocioServicio,idSocio);
    relSyS_setIdServicio(nuevoRelSocioServicio,idServicio);
    relSyS_setEstado(nuevoRelSocioServicio,estado);

    return nuevoRelSocioServicio;
}


int relSyS_delete(RelSocioServicio* this)
{
    free(this);
    return 0;
}


int relSyS_setId(RelSocioServicio* this,int id)
{

    this->id = id;
    return 0;
}

int relSyS_getId(RelSocioServicio* this)
{
    return this->id;
}

int relSyS_setIdSocio(RelSocioServicio* this,int idSocio)
{

    this->idSocio = idSocio;
    return 0;
}

int relSyS_getIdSocio(RelSocioServicio* this)
{
    return this->idSocio;
}

int relSyS_setIdServicio(RelSocioServicio* this,int idServicio)
{

    this->idServicio = idServicio;
    return 0;
}

int relSyS_getIdServicio(RelSocioServicio* this)
{
    return this->idServicio;
}



int relSyS_setEstado(RelSocioServicio* this,int estado)
{

    this->estado = estado;
    return 0;
}

int relSyS_getEstado(RelSocioServicio* this)
{
    return this->estado;
}


RelSocioServicio* relSyS_findById(ArrayList* pArrayRelSocioServicio, int id)
{
    int i;
    RelSocioServicio *auxRelSocioServicio;
    void* retorno=NULL;

    for(i=0;i<al_len(pArrayRelSocioServicio);i++)
    {
        auxRelSocioServicio = al_get(pArrayRelSocioServicio,i);
        if(id == auxRelSocioServicio->id)
        {
            retorno = auxRelSocioServicio;
        }
    }

    return retorno;
}

RelSocioServicio* relSyS_findByIdSocioAndIdServicio(ArrayList* pArrayRelSocioServicio, int idSocio,int idServicio)
{
    int i;
    RelSocioServicio* auxRelSocioServicio;
    void* retorno = NULL;

    for(i=0;i < al_len(pArrayRelSocioServicio);i++)
    {
        auxRelSocioServicio = al_get(pArrayRelSocioServicio,i);

        if(idSocio == relSyS_getIdSocio(auxRelSocioServicio) && idServicio == relSyS_getIdServicio(auxRelSocioServicio) && relSyS_getEstado(auxRelSocioServicio) == REL_SOCIO_SERVICIO_ESTADO_ACTIVO)
        {
            retorno = auxRelSocioServicio;
            break;
        }
    }
    return retorno;
}



