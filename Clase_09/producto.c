#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producto.h"
#include "validar.h"

int prod_cargarProducto (sProducto* arrayProducto, int index)
{
    int retorno = -1;
    char bNombre[51];
    char bPrecio[51];
    char bDesc[201];
    int id;

    if(arrayProducto != NULL && index >= 0)
    {
        if(val_getNombre(bNombre,"Ingrese el nombre del producto: \n","\nError!\n",3,51)==0)
        {
            if(val_getDesc(bDesc,"\nIngrese la descripcion del producto: \n","\nError!\n",3,201)==0)
            {
                //printf("NOMBRE ok");
                if(val_getFloat(bPrecio,"\nIngrese el precio: \n","\nError!\n",3,51)==0)
                {
                    id = prod_obtenerId(arrayProducto,CANTIDAD_PRODUCTOS);
                    if(id != -1)
                    {
                        strncpy(arrayProducto[index].nombre,bNombre,51);
                        strncpy(arrayProducto[index].desc,bDesc,201);
                        arrayProducto[index].precio = atof(bPrecio);
                        arrayProducto[index].estado = PRODUCTO_OCUPADO;
                        arrayProducto[index].Id = id;
                        retorno = 0;
                    }
                }
            }
        }

    }
    return retorno;
}

int prod_initProducto (sProducto* arrayProducto, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayProducto != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayProducto[i].estado = PRODUCTO_LIBRE;
        }
    }
    return retorno;
}

int prod_printProducto (sProducto* arrayProducto, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayProducto != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayProducto[i].estado == PRODUCTO_OCUPADO)
            {
                printf("\nID: %d  \nNombre: %s\nDescripcion: %s \nPrecio: %.2f\n",arrayProducto[i].Id,arrayProducto[i].nombre,arrayProducto[i].desc,arrayProducto[i].precio);
            }
        }
    }
    return retorno;
}

int prod_IndiceLibre(sProducto* arrayProducto, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayProducto != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayProducto[i].estado == PRODUCTO_LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int prod_obtenerId(sProducto* arrayProducto, int longitud)
{
    int i, bId = -1;
    int retorno = -1;
    if(arrayProducto != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if((arrayProducto[i].estado == PRODUCTO_OCUPADO)&&(arrayProducto[i].Id > bId))
            {
                bId = arrayProducto[i].Id;
            }
        }
        retorno = bId + 1;
    }
    return retorno;
}

int prod_buscarPorId(sProducto* arrayProducto, int longitud, int id)
{
    int i;
    int retorno = -1;
    if(arrayProducto != NULL && longitud > 0 && id >0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayProducto[i].estado == PRODUCTO_OCUPADO)
            {
                if(arrayProducto[i].Id==id);
                {
                    retorno = i;
                    break;
                }
            }
        }
    }
    return retorno;
}

int prod_modificarProducto(sProducto* arrayProducto, int index)
{
    int retorno = -1;
    char bNombre[51];
    char bPrecio[51];

    if(arrayProducto != NULL && index >= 0)
    {
        if(val_getNombre(bNombre,"Ingrese el nombre del producto: \n","\nError!\n",INTENTOS,51)==0)
        {
            if(val_getFloat(bPrecio,"\nIngrese el precio: \n","\nError!\n",INTENTOS,51)==0)
            {
                strncpy(arrayProducto[index].nombre,bNombre,51);
                arrayProducto[index].precio = atof(bPrecio);

                retorno = 0;
            }
        }
    }

    return retorno;
}

int prog_recibirYmodificarProductos(sProducto* arrayProducto)
{
    char id[20];
    int ind;
    int retorno = -1;

    if(arrayProducto != NULL)
    {
        if(val_getUnsignedInt(id,"Ingrese el Id: \n","Error",INTENTOS,20)==0)
        {
            ind = atoi(id);

            if(prod_buscarPorId(arrayProducto,CANTIDAD_PRODUCTOS,ind)!=-1);
            {
                prod_modificarProducto(arrayProducto,ind);
                retorno = 0;
            }
        }
    }
    return retorno;
}

