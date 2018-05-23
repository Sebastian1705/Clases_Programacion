#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Socio.h"

Socio* soc_new()
{
    return malloc(sizeof(Socio));
}

/*************************************/

void soc_delete(Socio* pSocio)
{
    if(pSocio != NULL)
    {
        free(pSocio);
    }
}

/*************************************/

int soc_setNombre(Socio* pSocio, char *nombre)
{
    int retorno = -1;
    if(pSocio != NULL)
    {
        strncpy(pSocio->nombre,nombre, NAME_SIZE);
        retorno = 0;
    }
    return retorno;
}

/*************************************/

char* soc_getNombre(Socio* pSocio)
{
    char* retorno = NULL;
    if(pSocio != NULL)
    {
        retorno = pSocio->nombre;
    }
    return retorno;
}

/*************************************/

int soc_setApellido(Socio* pSocio, char *apellido)
{
    int retorno = -1;
    if(pSocio != NULL)
    {
        strncpy(pSocio->apellido, apellido,LAST_NAME_SIZE);
        retorno = 0;
    }
    return retorno;
}

/*************************************/

char* soc_getApellido(Socio* pSocio)
{
    char* retorno = NULL;
    if(pSocio != NULL)
    {
        retorno = pSocio->apellido;
    }
    return retorno;
}

/*************************************/

int soc_setId(Socio* pSocio, int id)
{
    int retorno = -1;
    if(pSocio != NULL)
    {
        pSocio->id = id;
        retorno = 0;
    }
    return retorno;
}

/*************************************/

int soc_getId(Socio* pSocio, int id)
{
    int retorno = -1;
    if(pSocio != NULL)
    {
        retorno = pSocio->id;
    }
    return retorno;
}

/*************************************/

Socio* soc_newConstructor(char* nombre, char* apellido, int id)
{
    Socio* pSocio = malloc(sizeof(Socio));
    if(pSocio != NULL)
    {

    }
    return pSocio;
}

/*************************************/

