#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"
#include "Cliente.h"

static void opcionAltaCliente();
static void opcionBajaCliente();
static void opcionModificacionCliente();
static void opcionListadoCliente();
static void opcionOrdenarCliente();

static void opcionAltaVenta();
static void opcionListadoVenta();

static int idiomaVista;

int vista_init (int idioma)
{
    idiomaVista = idioma;
    return 0;
}

int vista_mostrarMenu()
{
    char buffer[10];
    int option=0;

    while(option != 11)
    {
        val_getUnsignedInt(buffer, MENU_PPAL_ES, MENU_PPAL_ERROR_ES,2,5);
        option = atoi(buffer);

        switch(option)
        {
            case 1:
                opcionAltaCliente();
                break;
            case 2:
                opcionModificacionCliente();
                break;
            case 3:
                opcionBajaCliente();
                break;
            case 4:
                opcionOrdenarCliente();
                opcionListadoCliente();
                break;
            case 5:
                opcionAltaVenta();
                break;
            case 6:

                break;
            case 7:
                opcionListadoVenta();
                break;
            case 8:

                break;
            case 9:

                break;
            case 10:

                break;
        }
    }

    return 0;
}

void vista_mostrarCliente(ArrayList* nominaCliente)
{
    al_map(nominaCliente,cliente_imprimir);
}

void vista_mostrarVentas(ArrayList* nominaVenta)
{
    al_map(nominaVenta,cont_imprimir_ventas);
}


void mostrarError(char * mensaje)
{

    printf("%s", mensaje);

}

static void opcionAltaCliente()
{
    char nombre[50];
    char apellido[50];
    char dni[50];
    if(val_getString(nombre, "\nIngrese el nombre: ", "Error\n",2,50) == 0 &&
       val_getString(apellido, "Ingrese el apellido: ", "Error\n",2,50) == 0 &&
       val_getDni(dni, "Ingrese el dni: ", "Error\n",2,50) == 0)
    {
        cont_altaCliente(nombre,apellido,dni);
    }
}

static void opcionBajaCliente()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id a dar de baja " , "Error\n",2,10)==0))
    {
        id = atoi(auxId);
        if(cont_existeCliente(id)!=0)
        {
            printf("El id es invalido\n");
        }
        else
        {
            cont_bajaCliente(id);
        }
    }

}

static void opcionModificacionCliente()
{
    char auxId[10];
    int id;
    char nombre[50];
    char apellido[50];
    char dni[50];

    if((val_getUnsignedInt(auxId,"Ingrese el id a modificar: " , "Error\n",2,10)==0))
    {
        id = atoi(auxId);
        if(cont_existeCliente(id)!=0)
        {
            printf("El id es invalido\n");
        }
        else if(!val_getDni(dni, "\nIngrese el dni: ", "Error\n",2,50) &&
                !val_getString(nombre, "\nIngrese el nombre: ", "Error\n",2,50) &&
                !val_getString(apellido, "\nIngrese el apellido: ", "Error\n",2,50))
        {
            cont_modificarCliente(id,nombre,apellido,dni);
        }
    }


}

static void opcionListadoCliente()
{
    cont_listarCliente();
}

static void opcionListadoVenta()
{
    cont_listarVentas();
}


static void opcionOrdenarCliente()
{
    cont_ordenarCliente();
}


static void opcionAltaVenta()
{
    char producto[50];
    char cantidad[50];
    char idCliente[50];
    if(!val_getUnsignedInt(idCliente, "\nIngrese el Id del cliente: ", "Error\n",2,50) &&
       !val_getInt(producto, "Ingrese el codigo del producto: ", "Error\n",2,50)  &&
       !val_getInt(cantidad, "Ingrese la cantidad: ", "Error\n",2,50))
    {
        if(atoi(producto) > 999 && atoi(producto) < 1003)
        {
            cont_altaVenta(atoi(idCliente),atoi(producto),atoi(cantidad));
        }
    }

}


