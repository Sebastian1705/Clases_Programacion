#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deposito.h"
#include "utn.h"

int validarDescripcion(char* titulo);
int validarCodProducto(int codProducto);
int validarCantidad(int cantidad);

EProducto* producto_new(void)
{
    EProducto* auxProducto = malloc(sizeof(EProducto));
    return auxProducto;
}

EProducto* producto_newP(int codProducto, char* descripcion, int cantidad)
{
    EProducto* auxProducto = malloc(sizeof(EProducto));
    if(auxProducto != NULL)
    {
        producto_setCodProducto(auxProducto, codProducto);
        producto_setDescripcion(auxProducto, descripcion);
        producto_setCantidad(auxProducto, cantidad);
    }
    return auxProducto;
}

void producto_delete(EProducto* this)
{
    free(this);
}

int producto_setCodProducto(EProducto* this,int codProducto)
{
    int retorno = -1;
    if(this != NULL && !validarCodProducto(codProducto))
    {
        this->codProducto = codProducto;
        retorno = 0;
    }
    return retorno;
}

int producto_setDescripcion(EProducto* this,char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL && validarDescripcion(descripcion))
    {
        strcpy(this->descripcion, descripcion);
        retorno = 0;
    }
    return retorno;
}

int producto_setCantidad(EProducto* this,int cantidad)
{
    int retorno = -1;
    if(this != NULL && !validarCantidad(cantidad))
    {
        this->cantidad = cantidad;
        retorno = 0;
    }
    return retorno;
}


int producto_getCodProducto(EProducto* this,int* codProducto)
{
    int retorno = -1;
    if(this != NULL && codProducto != NULL)
    {
        *codProducto = this->codProducto;
        retorno = 0;
    }
    return retorno;
}

int producto_getDescripcion(EProducto* this,char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        strcpy(descripcion ,this->descripcion);
        retorno = 0;
    }
    return retorno;
}

int producto_getCantidad(EProducto* this,int* cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad != NULL)
    {
        *cantidad = this->cantidad;
        retorno = 0;
    }
    return retorno;
}


int validarDescripcion(char* descripcion)
{
    return esAlfaNumerico(descripcion);
}


int validarCodProducto(int codProducto)
{
    if(codProducto > 0)
        return 0;
    return -1;
}

int validarCantidad(int cantidad)
{
    if(cantidad >=0 && cantidad < 999999)
        return 0;
    return -1;
}
