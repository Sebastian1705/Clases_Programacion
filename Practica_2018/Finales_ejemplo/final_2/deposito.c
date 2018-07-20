#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deposito.h"


/** \brief Set this employee the values recived as parameters
 *
 * \param pDeposito employee*
 * \param producto int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
eDeposito* deposito_newProducto()
{
    eDeposito* returnAux = NULL;
    eDeposito* pDeposito = malloc(sizeof(eDeposito));

    if(pDeposito != NULL)
    {
        returnAux = pDeposito;
    }

    return returnAux;

}


/** \brief Set this eDeposito the values recived as parameters
 *
 * \param pDeposito eDeposito*
 * \param producto int
 * \param name[] char
 * \param sector int
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
eDeposito* deposito_newProductoParam(int producto, char descripcion[],int cantidad)
{
    eDeposito* returnAux = NULL;
    eDeposito* pDeposito = malloc(sizeof(eDeposito));

    if(pDeposito != NULL)
    {
        deposito_setProducto(pDeposito, producto);
        deposito_setDescripcion(pDeposito, descripcion);
        deposito_setCantidad( pDeposito, cantidad);
        returnAux = pDeposito;
    }

    return returnAux;

}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int deposito_setDescripcion(eDeposito* this,char* descripcion)
{
    strcpy(this->descripcion,descripcion);
    return 0;
}

char* deposito_getDescripcion(eDeposito* this)
{
    return this->descripcion;
}


int deposito_setProducto(eDeposito* this,int producto)
{
    this->producto = producto;
    return 0;
}

int deposito_getProducto(eDeposito* this)
{
    return this->producto;
}



int deposito_setCantidad(eDeposito* this,int cantidad)
{
    this->cantidad= cantidad;
    return 0;
}

int deposito_getCantidad(eDeposito* this)
{
    return this->cantidad;
}

void deposito_printProducto(eDeposito*this)
{
    printf("Producto Nro: %d\tDescripcion:%s\t Cantidad:%d\n",deposito_getProducto(this), deposito_getDescripcion(this), deposito_getCantidad(this));
}



