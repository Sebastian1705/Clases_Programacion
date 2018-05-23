#include <stdio.h>
#include <stdlib.h>
#include "producto.h"
#include "validar.h"

int main()
{
    sProducto arrayProductos[CANTIDAD_PRODUCTOS];
    char bufferInt[40];

    prod_initProducto(arrayProductos,CANTIDAD_PRODUCTOS);

    do
    {
        val_getUnsignedInt(bufferInt,"\n\tMenu de productos\n1. Cargar un producto\n2. Imprimir lista productos \n3. Editar producto \n4. Borrar producto \n5. Salir\n","\nError! \n",2,40);
        switch(atoi(bufferInt))
        {
            case 1:
                system("cls");
                prod_cargarProducto(arrayProductos, prod_IndiceLibre(arrayProductos,CANTIDAD_PRODUCTOS));
                system("cls");
                break;
            case 2:
                system("cls");
                prod_printProducto(arrayProductos,CANTIDAD_PRODUCTOS);
                break;
            case 3:
                system("cls");
                prog_recibirYmodificarProductos(arrayProductos);
                break;
            case 4:
                system("cls");
                break;
        }

    }while( atoi(bufferInt) != 5);

    return 0;
}
