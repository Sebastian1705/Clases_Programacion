#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Cliente.h"
#include "Alquiler.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"

static int idiomaVista = VISTA_IDIOMA_ES;

static void opcionAltaCliente();
static void opcionBajaCliente();
static void opcionModificacionCliente();
static void opcionListadoCliente();
static void opcionOrdenarCliente();

static void opcionAltaAlquiler();
static void opcionBajaAlquiler();
static void opcionModificacionAlquiler();
static void opcionListadoAlquiler();
static void opcionOrdenarAlquiler();


int vista_init (int idioma)
{
    idiomaVista = idioma;
    return 0;
}

int vista_mostrarMenu()
{
    int buffer;
    int option=0;

    while(option != 10)
    {
        val_getUnsignedInt(&buffer, MENU_PPAL_ES, MENU_PPAL_ERROR_ES,2,1,11);
        option = buffer;

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
        case 6:/************************************/
            opcionListadoAlquiler();
            break;
        case 7:
            opcionAltaAlquiler();
            break;
        case 8:
            opcionBajaAlquiler();
            break;
        case 9:
            opcionOrdenarAlquiler();
            break;

        }
    }

    return 0;
}


static void opcionListadoCliente()
{
    cont_listarCliente();
}

void vista_mostrarCliente(ArrayList* pListaCliente)
{
    al_map(pListaCliente,cliente_imprimir);
}

static void opcionAltaCliente()
{
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];

    if(val_getString(auxNombre, "Nombre?\n", "Error\n",2,50) == 0 &&
       val_getString(auxApellido, "Apellido?\n", "Error\n",2,50) == 0 &&
       val_getDni(auxDni, "DNI?\n", "Error\n",2,50) == 0)
    {
        cont_altaCliente(auxNombre,auxApellido,auxDni);
    }
}

static void opcionBajaCliente()
{
    int auxId;

    if(val_getUnsignedInt(&auxId,"Id a dar de baja\n", "Error\n",2,0,99999)==0)
        cont_bajaCliente(auxId);
}

static void opcionModificacionCliente()
{
    int auxId;
    int auxEstado;
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];

    if(val_getUnsignedInt(&auxId,"Id a modificar\n", "Error\n",2,0,99999) == 0)
    {
        if(cont_existeCliente(auxId) == 0)
        {
            if(val_getString(auxNombre, "Nombre\n?", "Error\n",2,50) == 0 &&
            val_getString(auxApellido, "Apellido?\n", "Error\n",2,50) == 0 &&
            val_getDni(auxDni, "DNI?\n", "Error\n",2,50) == 0 &&
            val_getUnsignedInt(&auxEstado,"Estado?\nACTIVO= 0\nINACTIVO= 1", "Error",2,0,1) == 0)
            {
                cont_modificarCliente(auxNombre,auxApellido,auxDni,auxId,auxEstado);
            }
        }
        else
        {
            vista_mostrarError("El ID de cliente no existe");
        }
    }
}

static void opcionOrdenarCliente()
{
    cont_ordenarCliente();
}

void vista_mostrarError(char* mensaje)
{
    printf("%s",mensaje);
}



/*********************************************************///Alquiler

static void opcionListadoAlquiler()
{
    cont_listarAlquiler();
}

void vista_mostrarAlquiler(ArrayList* pListaAlquiler)
{
    al_map(pListaAlquiler,alquiler_imprimir);

    /*int i;
    Alquiler* auxAlquiler;
    for(i=0;i<al_len(pListaAlquiler);i++)
        {
            auxAlquiler=al_get(pListaAlquiler,i);
            if(auxAlquiler->estado==ESTADO_ALQUILADO)
            {
                auxAlquiler = al_get(pListaAlquiler,i);
                printf("ID: %d - ID Cliente: %d\n",alquiler_getId(auxAlquiler),alquiler_getIdCliente(auxAlquiler));
            }
        }*/
}


static void opcionAltaAlquiler()
{
    int idCliente,equipo;

    if (val_getUnsignedInt(&idCliente, "idCliente?\n", "Error",2,0,99999) == 0 &&
        val_getUnsignedInt(&equipo, "equipo?\n", "Error",2,0,99999) == 0)
    {
        cont_altaAlquiler(idCliente,equipo);
    }
}

static void opcionBajaAlquiler()
{
    int auxId;

    if(val_getUnsignedInt(&auxId,"Id a dar de baja\n", "Error\n",2,0,99999) == 0)
        cont_bajaAlquiler(auxId);
}

static void opcionModificacionAlquiler()
{
    /*int auxId;
    int auxEstado;
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];

    if(val_getUnsignedInt(&auxId,"Id a modificar\n", "Error\n",2,0,99999) == 0)
    {
        if(cont_existeCliente(auxId) == 0)
        {
            if(val_getString(auxNombre, "Nombre\n?", "Error\n",2,50) == 0 &&
            val_getString(auxApellido, "Apellido?\n", "Error\n",2,50) == 0 &&
            val_getDni(auxDni, "DNI?\n", "Error\n",2,50) == 0 &&
            val_getUnsignedInt(&auxEstado,"Estado?\nACTIVO= 0\nINACTIVO= 1", "Error",2,0,1) == 0)
            {
                cont_modificarCliente(auxNombre,auxApellido,auxDni,auxId,auxEstado);
            }
        }
        else
        {
            vista_mostrarError("El ID de cliente no existe");
        }
    }*/
}


static void opcionOrdenarAlquiler()
{
    cont_ordenarAlquiler();
}



