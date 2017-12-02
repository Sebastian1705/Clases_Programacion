#include <stdio.h>
#include <stdlib.h>
#include "Entidad1.h"
#include "Entidad2.h"

int ent2_init(Entidad2* array, int len)
{
    int retorno = -1;
    int i;

    if(array != NULL && len > 0)
    {
        for(i=0; i<len ; i++)
        {
            array[i].flagEstadoOcupado = ESTADO_lIBRE;
        }
    }
    return retorno;
}

int ent2_generarProx_Id(Entidad2* array, int len)
{
    int i, bId = -1;
    int retorno = -1;
    if(array != NULL && len > 0)
    {
        for(i=0; i<len ; i++)
        {
            if((array[i].flagEstadoOcupado == ESTADO_OCUPADO)&&(array[i].id > bId))
            {
                bId = array[i].id;
            }
        }
        retorno = bId + 1;
    }
    return retorno;
}

int ent2_buscarPosicionLibre(Entidad2* array, int len)
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0; i<len ; i++)
        {
            if(array[i].flagEstadoOcupado == ESTADO_lIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int ent2_baja(Entidad2* array, int id, int len)
{
    int retorno = -1;
    int i = 0;

    if(array != NULL && len > 0)
    {
        for(i=0; i<len ; i++)
        {
            if(array[i].flagEstadoOcupado == ESTADO_OCUPADO && array[i].id == id)
            {
              array[i].flagEstadoOcupado = ESTADO_lIBRE;
              printf("\nEliminado!\n");
              retorno=0;
            }
        }
    }
    return retorno;
}
