#include "reparto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

EReparto* reparto_new()
{
    EReparto* this;
    this=malloc(sizeof(EReparto));
    return this;
}

EReparto* reparto_newParametros(int idReparto, char producto[50], char direccion[200], char localidad[50], char recibe[20])
{
    EReparto* this;
    this=malloc(sizeof(EReparto));

    if(this != NULL)
    {
        reparto_setIdReparto(this, idReparto);
        reparto_setProducto(this, producto);
        reparto_setDireccion(this,direccion);
        reparto_setLocalidad(this,localidad);
        reparto_setRecibe(this,recibe);
    }
    return this;
}

int reparto_setIdReparto(EReparto* this,int idReparto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->idReparto=idReparto;
        retorno=0;
    }
    return retorno;
}

int reparto_getIdReparto(EReparto* this,int* idReparto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idReparto=this->idReparto;
        retorno=0;
    }
    return retorno;
}

int reparto_setProducto(EReparto* this,char* producto)
{
    int retorno=-1;
    if(this!=NULL && producto!=NULL)
    {
        strcpy(this->producto,producto);
        retorno=0;
    }
    return retorno;
}

int reparto_getProducto(EReparto* this,char* producto)
{
    int retorno=-1;
    if(this!=NULL && producto!=NULL)
    {
        strcpy(producto,this->producto);
        retorno=0;
    }
    return retorno;
}

int reparto_setLocalidad(EReparto* this,char* localidad)
{
    int retorno=-1;
    if(this!=NULL && localidad!=NULL)
    {
        strcpy(this->localidad,localidad);
        retorno=0;
    }
    return retorno;
}

int reparto_getLocalidad(EReparto* this,char* localidad)
{
    int retorno=-1;
    if(this!=NULL && localidad!=NULL)
    {
        strcpy(localidad,this->localidad);
        retorno=0;
    }
    return retorno;
}

int reparto_setDireccion(EReparto* this,char* direccion)
{
    int retorno=-1;
    if(this!=NULL && direccion!=NULL)
    {
        strcpy(this->direccion,direccion);
        retorno=0;
    }
    return retorno;
}

int reparto_getDireccion(EReparto* this,char* direccion)
{
    int retorno=-1;
    if(this!=NULL && direccion!=NULL)
    {
        strcpy(direccion,this->direccion);
        retorno=0;
    }
    return retorno;
}

int reparto_setRecibe(EReparto* this,char* recibe)
{
    int retorno=-1;
    if(this!=NULL && recibe!=NULL)
    {
        strcpy(this->recibe,recibe);
        retorno=0;
    }
    return retorno;
}

int reparto_getRecibe(EReparto* this,char* recibe)
{
    int retorno=-1;
    if(this!=NULL && recibe!=NULL)
    {
        strcpy(recibe,this->recibe);
        retorno=0;
    }
    return retorno;
}
