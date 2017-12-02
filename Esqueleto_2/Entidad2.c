#include <stdio.h>
#include <stdlib.h>
#include "Entidad2.h"


/**
* \brief Inicializa el array
* \param array Corresponde a la posicion de memoria del array
* \param len Es la cantidad de elementos que contiene el array
* \return 0 si la inicializacion es correcta y -1 en caso de error
*
*/
int ent2_init(Entidad2* array, int len)
{
    int retorno = -1;
    int i;

    if(array != NULL && len > 0)
    {
        for(i=0; i<len ; i++)
        {
            array[i].flagEstadoOcupado = ESTADO_LIBRE;
        }
    }
    return retorno;
}


/**
* \brief Genera un id unico e irrepetible
* \param array Corresponde a la posicion de memoria del array
* \param len Es la cantidad de elementos que contiene el array
* \return Retorna el id en el caso posible o -1 en caso de error
*
*/
int ent2_generarProx_Id(Entidad2* array, int len)
{
    int i, bufferId = -1;
    int retorno = -1;
    if(array != NULL && len > 0)
    {
        for(i=0; i<len ; i++)
        {
            if((array[i].flagEstadoOcupado == ESTADO_OCUPADO)&&(array[i].id > bufferId))
            {
                bufferId = array[i].id;
            }
        }
        retorno = bufferId + 1;
    }
    return retorno;
}

/**
* \brief Busca un indice libre
* \param array Corresponde a la posicion de memoria del array
* \param len Es la cantidad de elementos que contiene el array
* \return Retorna el indice libre o -1 en caso de error
*
*/
int ent2_buscarPosicionLibre(Entidad2* array, int len)
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0; i<len ; i++)
        {
            if(array[i].flagEstadoOcupado == ESTADO_LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/**
* \brief Busca el indice correspondiente al id ingresado
* \param array Corresponde a la posicion de memoria del array
* \param len Es la cantidad de elementos que contiene el array
* \param id Es el id ingersado por el ususario
* \return Retorna el indice del id ingresado o -1 en caso de error
*
*/
int ent2_buscarIncicePorId(Entidad2* array, int len, int id)
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
