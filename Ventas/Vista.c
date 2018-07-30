#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"
#include "Cliente.h"
#include "Ventas.h"

static void opcionAltaCliente();
static void opcionBajaCliente();
static void opcionModificacionCliente();
static void opcionListadoCliente();
static void opcionOrdenarCliente();

static void opcionAltaVenta();
static void opcionListadoVenta();
static void opcionBajaVenta();
static void opcionListadoVentaProducto();
static void opcioGenerarInforme();
static void opcioInformarVentasCliente();

static int idiomaVista;

int vista_init (int idioma)
{
    idiomaVista = idioma;
    return 0;
}

int vista_mostrarMenu()
{
    char buffer[10];
    int option=11;

    while(option != 0)
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
            opcionBajaVenta();
            break;
        case 7:
            opcionListadoVenta();
            break;
        case 8:
            opcionListadoVentaProducto();
            break;
        case 9:
            opcioGenerarInforme();
            break;
        case 10:
            opcioInformarVentasCliente();
            break;
        }
    }

    return 0;
}


void vista_mostrarCliente(ArrayList* nominaCliente)
{
    al_map(nominaCliente,cliente_imprimir);
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

    if((val_getUnsignedInt(auxId,"Id a dar de baja ", "Error\n",2,10)==0))
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

    if((val_getUnsignedInt(auxId,"Ingrese el id a modificar: ", "Error\n",2,10)==0))
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

static void opcionOrdenarCliente()
{
    cont_ordenarCliente();
}

static void opcionAltaVenta()
{
    char producto[50];
    char cantidad[50];
    char idCliente[50];
    if(!val_getUnsignedInt(idCliente, "\nIngrese el Id del cliente: ", "Error\n",2,50))
    {
        if(cont_existeCliente(atoi(idCliente))==-1)
        {
            printf("El cliente no existe!\n\n");
        }
        else
        {
            if( !val_getInt(producto, "Ingrese el codigo del producto: ", "Error\n",2,50))
            {
                if(atoi(producto) > 999 && atoi(producto) < 1003)
                {
                    if(!val_getInt(cantidad, "Ingrese la cantidad: ", "Error\n",2,50))
                       {
                           cont_altaVenta(atoi(idCliente),atoi(producto),atoi(cantidad));
                       }
                }
                else
                {
                    mostrarError("El codigo es incorrecto!\n\n");
                }
            }
        }
    }

}

static void opcionBajaVenta()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id a dar de baja ", "Error\n",2,10)==0))
    {
        id = atoi(auxId);
        if(cont_existeVenta(id)!=0)
        {
           mostrarError("\nLa venta no existe!\n");
        }
        else
        {
            cont_bajaVenta(id);
        }
    }

}

static void opcionListadoVenta()
{
    cont_listarVentas();
}

static void opcionListadoVentaProducto()
{
    char codProducto[4096];
    int cod;
    if(!val_getUnsignedInt(codProducto,"IPHONE7 1002\tPS4 1001\tTV_LG_32 1000\nIngrese el codigo del producto: ","Error!",2,50))
    {
        cod = atoi(codProducto);
        if(cod == TV_LG_32)
        {
            cont_listarVentasProducto(cod);
        }
        else if(cod == IPHONE7)
        {
            cont_listarVentasProducto(cod);
        }
        else if(cod == PS4)
        {
            cont_listarVentasProducto(cod);
        }
        else
        {
            printf("\nCodigo incorrecto!\n");
        }
    }
}

static void opcioGenerarInforme()
{
    cont_generarInforme();
}

static void opcioInformarVentasCliente()
{
    cont_informarVentasCliente();
}

void vista_mostrarVentas(ArrayList* nominaVenta)
{
    al_map(nominaVenta,cont_imprimir_ventas);
}



