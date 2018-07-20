#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "deposito.h"
#include "utn.h"
#include "ArrayList.h"
#include "parser.h"

EProducto* crearProducto(void)
{
    int auxCodProducto;
    char auxDescripcion[256];
    int auxCantidad;

    EProducto* auxProducto;
    if(!getValidInt("\nIngrese el producto\n","\nEso no es un producto\n", &auxCodProducto, 0, 999999,2))
        if(!getValidString("\nIngrese la descripcion\n","\nEso no es una descripcion\n", "\nEl maximo es 50\n", auxDescripcion, 50,2))
            if(!getValidInt("\nIngrese la cantidad\n", "\nEso no es una cantidad\n", &auxCantidad, 0, 999999, 2))
                {
                    auxProducto = deposito_newP(auxCodProducto, auxDescripcion, auxCantidad);
                    return auxProducto;
                }
    return NULL;
}

int agregarProducto(ArrayList* pArrayDepositos, EProducto* producto)
{
    if(producto != NULL)
    {
        al_add(pArrayDepositos, producto);
        if(!guardarProductos(pArrayDepositos))
        {
            printf("\nProducto guardado exitosamente\n\n");
            return 0;
        }
    }
    return -1;
}


int borrarProducto(ArrayList* pArrayDepositos)
{
    int retorno = -1;
    int i;
    int codProducto;
    int auxProd;

    EProducto* auxProducto;

    if(!getValidInt("\nIngrese el codigo del producto a borrar\n", "\nEso no es un codigo\n","\nEl maximo es 999999\n", codProducto, 9999,2))
    {
        for(i=0; i<al_len(pArrayDepositos);i++)
        {
            producto_getCodProducto(al_get(pArrayDepositos, i), &auxProd);

            if(codProducto==auxProd)
            {
                retorno = 0;
                auxProducto = al_pop(pArrayDepositos, i);
                deposito_delete(auxProducto);
                guardarDepositos(pArrayDepositos,"dep0.csv");
                printf("\nDeposito removida exitosamente\n\n");
                break;
            }
        }
    }
    return retorno;
}

int modificarProducto(ArrayList* pArrayDepositos)
{
    int retorno = -1;
    int i;

    EProducto* auxProducto;
    if(!getValidString("\nIngrese el titulo a modificar\n", "\nNo es un titulo valido\n","\nEl maximo es 50 caracteres\n", tituloAModificar, 50,2))
    {
        for(i=0; i<al_len(pArrayDepositos);i++)
        {
            deposito_getTitulo(al_get(pArrayDepositos, i), titulo);
            if(!strcmp(tituloAModificar, titulo))
            {
                auxProducto = al_get(pArrayDepositos, i);
                if(!getValidInt("\nIngrese la duracion\n","\nNo es una duracion valida\n", &duracion, 0, 1440,2))
                    if(!getValidString("\nIngrese la descripcion\n","\nNo es una descripcion valida\n", "El maximo es 256 caracteres\n", descripcion, 256,2))
                        if(!getValidInt("\nIngrese el puntaje[0-10]\n", "\nCantidad invalido\n", &puntaje, 0, 10, 2))
                            retorno = 0;
                            deposito_setProducto(auxProducto, duracion);
                            deposito_setDescripcion(auxProducto, descripcion);
                            deposito_setCantidad(auxProducto, puntaje);

                            printf("\nDeposito removida exitosamente\n\n");
            }
                guardarDepositos(pArrayDepositos);
                break;
        }
    }
    return retorno;
}

