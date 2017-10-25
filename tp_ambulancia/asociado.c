#include <stdio.h>
#include <stdlib.h>
#include "llamada.h"
#include "validar.h"
#include "asociado.h"


int cargarAsociado(sAsociado* arrayAsociado, int index)
{
    int retorno = -1;
    char bNombre[CANTIDAD_CARACTERES];
    char bApellido[CANTIDAD_CARACTERES];
    char bDni[CANTIDAD_CARACTERES];

    if(arrayAsociado != NULL && index >= 0)
    {
        if(val_getNombre(bNombre,"Ingrese el nombre: \n","\nError!\n",INTENTOS,CANTIDAD_CARACTERES)==0)
        {
            if(val_getNombre(bApellido,"Ingrese el apellido: \n","\nError!\n",INTENTOS,CANTIDAD_CARACTERES)==0)
            {
                if(getDni(bDni, "Ingrese el Dni:\n", "Error! Dni invalido\n", INTENTOS, CANTIDAD_ASOCIADOS)==0)
                {
                    retorno = 0;
                }

            }
        }

    }
    return retorno;
}

int asoc_IndiceLibre(sAsociado* arrayAsociado, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayAsociado != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayAsociado[i].flagEstado == ASOCIADO_LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int asoc_obtenerId(sAsociado* arrayAsociado, int longitud)
{
    int i, bId = -1;
    int retorno = -1;
    if(arrayAsociado != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if((arrayAsociado[i].flagEstado == ASOCIADO_OCUPADO)&&(arrayAsociado[i].idAsociado > bId))
            {
                bId = arrayAsociado[i].idAsociado;
            }
        }
        retorno = bId + 1;
    }
    return retorno;
}

int asoc_buscarPorId(sAsociado* arrayAsociado, int longitud, int id)
{
    int i;
    int retorno = -1;
    if(arrayAsociado != NULL && longitud > 0 && id >0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayAsociado[i].flagEstado == ASOCIADO_OCUPADO)
            {
                if(arrayAsociado[i].idAsociado == id);
                {
                    retorno = i;
                    break;
                }
            }
        }
    }
    return retorno;
}

int asoc_initAsociado(sAsociado* arrayAsociado, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayAsociado != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayAsociado[i].flagEstado = ASOCIADO_LIBRE;
        }
    }
    return retorno;
}

int asoc_modificarAsociado(sAsociado* arrayAsociado, int index)
{
    int retorno = -1;
    char bNombre[CANTIDAD_CARACTERES];
    char bApellido[CANTIDAD_CARACTERES];

    if(arrayAsociado != NULL && index >= 0)
    {
        if(val_getNombre(bNombre,"Ingrese el nombre: \n","\nError!\n",INTENTOS,CANTIDAD_CARACTERES)==0)
        {
            if(val_getNombre(bApellido,"Ingrese el apellido: \n","\nError!\n",INTENTOS,CANTIDAD_CARACTERES)==0)
            {
                strncpy(arrayAsociado[index].nombre,bNombre,CANTIDAD_CARACTERES);
                strncpy(arrayAsociado[index].nombre,bApellido,CANTIDAD_CARACTERES);

                retorno = 0;
            }
        }
    }

    return retorno;
}

int asoc_recibirYmodificarAsociados(sAsociado* arrayAsociado)
{
    char id[CANTIDAD_CARACTERES];
    int ind;
    int retorno = -1;

    if(arrayAsociado != NULL)
    {
        if(val_getUnsignedInt(id,"Ingrese el Id: \n","Error",INTENTOS,CANTIDAD_ASOCIADOS)==0)
        {
            ind = atoi(id);

            if(asoc_buscarPorId(arrayAsociado,CANTIDAD_ASOCIADOS,ind)!=-1)
            {
                asoc_modificarAsociado(arrayAsociado, ind);
                retorno = 0;
            }
        }
    }
    return retorno;
}

