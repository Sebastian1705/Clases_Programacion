#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Cliente.h"
#include "Servicio.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"


static void opcionAlta();
static void opcionBaja();
static void opcionModificacion();
static void opcionListado();

static void opcionImportarClientes();

static void opcionIngresoServicioTecnico();

int vista_init (void)
{
    return 0;
}

int vista_mostrarMenu(void)
{
    char buffer[10];
    int option=0;

    while(option != 10)
    {
        val_getInt(buffer, MENU_PPAL_ES, MENU_PPAL_ERROR_ES,2,5);
        option = atoi(buffer);

        switch(option)
        {
        case 1:
            opcionAlta();
            break;
        case 2:
            opcionModificacion();
            break;
        case 3:
            opcionBaja();
            break;
        case 4:
            opcionListado();
            break;
        case 5:
        {
            opcionImportarClientes();
            break;
        }
        case 6:
        {
            opcionIngresoServicioTecnico();
            break;
        }
        case 7:
        {
            break;
        }
        case 8:
        {

            break;
        }
        case 9:
        {
            break;
        }
        //_______
        }
    }

    return 0;
}

void vista_mostrarSocios(ArrayList* pListaSocios)
{
    int i;
    Cliente* auxSocio;
    for(i=0; i<al_len(pListaSocios); i++)
    {
        auxSocio=al_get(pListaSocios,i);
        if(auxSocio->estado==CLIENTE_ESTADO_ACTIVO)
        {
            auxSocio = al_get(pListaSocios,i);
            printf("NOMBRE: %s - APELLIDO: %s- ID: %d - DNI: %s\n",cliente_getNombre(auxSocio),
                   cliente_getApellido(auxSocio),cliente_getId(auxSocio),cliente_getDni(auxSocio));
        }
    }

}


void mostrarError(char *);

static void opcionAlta()
{
    char nombre[50];
    char apellido[50];
    char dni[9];
    if(val_getString(nombre, "Nombre? ", "Error\n",2,50) == 0 &&
            val_getString(apellido, "Apellido? ", "Error\n",2,50) == 0 &&
            getDni(dni, "DNI? ", "Error\n",2,9) == 0)
    {
        cont_altaCliente(nombre,apellido,dni);
    }

}

static void opcionBaja()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        cont_bajaCliente(id);
    }

}

static void opcionModificacion()
{
    char auxId[10];
    int id;
    char nombre[50];
    char apellido[50];
    char dni[9];

    if((val_getUnsignedInt(auxId,"Id a modificar " , "Error",2,10)==0))
    {
        id = atoi(auxId);
        if(cont_existeCliente(id) == 1)
        {
            if(val_getString(nombre, "Nombre? ", "Error",2,50) == 0 &&
                    val_getString(apellido, "Apellido? ", "Error",2,50) == 0 &&
                    getDni(dni, "DNI? ", "Error",2,9) == 0)
            {
                cont_modificarCliente(id,nombre,apellido,dni);
            }
        }
        else
        {
            vista_mostrarError("El cliente no existe!!!\n");
        }
    }
}

static void opcionListado()
{
    cont_ordenarCliente();
    cont_listarClientes();

}

void vista_mostrarError(char * mensaje)
{

    printf("\n%s\n",mensaje);

}

static void opcionImportarClientes()
{
    cont_importarClientes();
}

static void opcionIngresoServicioTecnico()
{
    char idCliente[10];
    char cdProducto[10];
    char cantidad[10];
    char costo[50];
    char fecha[50];
    int id;
    if(val_getUnsignedInt(idCliente, "id Cliente? ", "Error",2,50) == 0)
    {
        id = atoi(idCliente);
        if(cont_existeCliente(id)==1)
        {
            if( val_getAlfanumerico(cdProducto, "Cod producto? ", "Error",2,50) == 0 &&
                val_getUnsignedInt(cantidad, "Cantidad? ", "Error",2,50) == 0 &&
                val_getFloat(costo, "Costo? ", "Error\n",2,50)==0 &&
                val_getEmail(fecha, "Fecha? ", "Error", 2 ,50))
                {
                    cont_servicioTecnico(id, cdProducto, atof(costo), fecha);
                }

        }
    }

}
void vista_mostrarServicios(ArrayList* pListaServicios)
{
    int i;
    Servicio* auxSocio;
    for(i=0; i<al_len(pListaServicios); i++)
    {
        auxSocio=al_get(pListaServicios,i);
        if(auxSocio->estado==1)
        {
            auxSocio = al_get(pListaServicios,i);
            printf("ID: %d - COSTO: %f - FECHA: %s\n",servicio_getId(auxSocio), servicio_getCosto(auxSocio), servicio_getFechaIngreso(auxSocio));
        }
    }

}

