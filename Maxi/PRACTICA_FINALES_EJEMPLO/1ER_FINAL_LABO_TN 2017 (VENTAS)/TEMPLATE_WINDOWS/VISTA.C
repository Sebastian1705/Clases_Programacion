#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inputs.h"
#include "Validaciones.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"

static void opcionAltaX();
static void opcionBajaX();
static void opcionModificacionX();

static void opcionListadoX();
static void opcionOrdenarX();


static void opcionAltaCliente();
static void opcionBajaCliente();
static void opcionModificacionCliente();

static void opcionListadoCliente();
static void opcionOrdenarCliente();

int vista_mostrarMenu()
{
    int option=0;

    while(option != 6)
    {
        input_getInt(MENU_PPAL_ES, MENU_PPAL_ERROR_ES, 3, 1, 5, &option);
        switch(option)
        {
            case 1:
                opcionListadoCliente();
                break;
            case 2:
                opcionAltaCliente();
                break;
            case 3:
                opcionBajaCliente();
                break;
            case 4:
                opcionModificacionCliente();
                break;
            case 5:
                opcionOrdenarCliente();
                break;
///////////////////////////////////////////
//            case 6:
//                opcionListadoX();
//                break;
//            case 7:
//                opcionAltaX();
//                break;
//            case 8:
//                opcionBajaX();
//                break;
//            case 9:
//                opcionModificacionX();
//                break;
//            case 10:
//                opcionOrdenarX();
//                break;
        }
    }

    return 0;
}

static void opcionAltaX()
{
    char a[50];
    char b[50];
    char c[50];
    if(val_getString(a, "A? ", "Error",2,50) == 0 &&
       val_getString(b, "B? ", "Error",2,50) == 0 &&
       val_getInt(c, "C? ", "Error",2,50) == 0)
    {
        cont_altaX(a,b,atoi(c));
    }
}
static void opcionBajaX()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        cont_bajaX(id);
    }
}
static void opcionModificacionX()
{
    char auxId[10];
    int id;
    char a[50];
    char b[50];
    char c[50];

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        if(val_getString(a, "A? ", "Error",2,50) == 0 &&
           val_getString(b, "B? ", "Error",2,50) == 0 &&
           val_getInt(c, "C? ", "Error",2,50) == 0)
        {
            cont_modificarX(id,a,b,atoi(c));
        }
    }
}


static void opcionListadoX()
{
    cont_listarX();
}
static void opcionOrdenarX()
{
    cont_ordenarX();
}
void vista_mostrarX(ArrayList* pListaX)
{
    printf("\nIMPRIMO LISTA DE ENTIDAD X\n");
}


//////////////////////////////////////////////
static void opcionAltaCliente()
{
    char nombre[50];
    char apellido[50];
    char dni[50];
    if(input_getString("nombre: ", "\t** el nombre debe estar compuesto de 3 a 20 caracteres. **\n\n", 3, 2, 50, nombre) == 0 &&
       input_getString("apellido: ", "\t** el apellido debe estar compuesto de 3 a 20 caracteres. **\n\n", 3, 2, 50, nombre) == 0 &&
       input_getNumericStr("dni?", "error", 3, 6500000, 50500000, dni) == 0)
    {
        cont_altaCliente(nombre,apellido,dni);
    }
}
static void opcionBajaCliente()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        cont_bajaCliente(id);
    }
}
static void opcionModificacionCliente()
{
    char auxId[10];
    int id;
    char a[50];
    char b[50];
    char c[50];

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        if(val_getString(a, "A? ", "Error",2,50) == 0 &&
           val_getString(b, "B? ", "Error",2,50) == 0 &&
           val_getInt(c, "C? ", "Error",2,50) == 0)
        {
            cont_modificarCliente(id,a,b,c);
        }
    }
}


static void opcionListadoCliente()
{
    cont_listarX();
}
static void opcionOrdenarCliente()
{
    cont_ordenarX();
}
void vista_mostrarCliente(ArrayList* pListaCliente)
{
    printf("\nIMPRIMO LISTA DE ENTIDAD X\n");
}



