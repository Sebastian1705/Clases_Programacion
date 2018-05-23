#include <stdio.h>
#include <stdlib.h>
#include "Entidad1.h"
#include "validar.h"
#include "string.h"


int ent1_init(Entidad1* array, int len)
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

static int ent1_generarProx_Id(Entidad1* array, int len)
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

int ent1_buscarPosicionLibre(Entidad1* array, int len)
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

int ent1_buscarIncicePorId(Entidad1* array, int len, int id)
{
    int i;
    int retorno = -1;
    if(array != NULL && len > 0 && id >0)
    {
        for(i=0; i<len ; i++)
        {
            if(array[i].flagEstadoOcupado == ESTADO_OCUPADO)
            {
                if(array[i].id == id);
                {
                    retorno = i;
                    break;
                }
            }
        }
    }
    return retorno;
}

int ent1_alta(Entidad1* array, int len)
{
    int retorno = -1;
    char bNombre[CANTIDAD_CARACTERES];

    //1. BUSCAR POSICION LIBRE
    int indexVacio = ent1_buscarPosicionLibre(array, len);
    //2. GENERAR ID
    int idNuevo = ent1_generarProx_Id(array, len);
    //3. PEDIR DATOS AL USUARIO (DEPENDE DEL PROBLEMA)
    if(val_getNombre(bNombre,"Ingrese el nombre: \n","\nError!\n",INTENTOS,CANTIDAD_CARACTERES)==0)
    {
        array[indexVacio].id = idNuevo;

    }
    //4. CARGAR DATOS EN ITEM VACIO


    return retorno;
}

int ent1_baja(Entidad1* array, int id, int len)
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

