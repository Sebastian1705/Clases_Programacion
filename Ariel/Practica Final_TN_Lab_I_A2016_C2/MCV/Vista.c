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

static void opcionAlta();
static void opcionBaja();
static void opcionModificacion();
static void opcionListado();

static void opcionAltaAlquiler();
static void opcionBajaAlquiler();
static void opcionListadoAlquiler();

static void opcionInformes();


int vista_init (int idioma)
{
    idiomaVista = idioma;
    return 0;
}

int vista_mostrarMenu()
{
    int buffer;
    int option=0;

    while(option != 9)
    {
        val_getUnsignedInt(&buffer, MENU_PPAL_ES, MENU_PPAL_ERROR_ES,2,1,11);
        option = buffer;

        switch(option)
        {
        case 1:
            opcionListado();
            break;
        case 2:
            opcionAlta();
            break;
        case 3:
            opcionBaja();
            break;
        case 4:
            opcionModificacion();
            break;
        case 5:
            opcionListadoAlquiler();
            break;
        case 6:
            opcionAltaAlquiler();
            break;
        case 7:
            opcionBajaAlquiler();
            break;
        case 8:
            opcionInformes();
            break;
        }
    }

    return 0;
}

void vista_mostrarCliente(ArrayList* pListaClientes)
{
    int i;
    Cliente* auxCliente;
    for(i=0;i<al_len(pListaClientes);i++)
        {
            auxCliente=al_get(pListaClientes,i);
            if(auxCliente->estado==CLIENTE_ESTADO_ACTIVO)
            {
                printf("NOMBRE: %s - APELLIDO: %s- ID: %d - DNI: %s\n",cliente_getNombre(auxCliente),
                            cliente_getApellido(auxCliente),cliente_getId(auxCliente),cliente_getDni(auxCliente));
            }
        }
}

void vista_mostrarError(char* mensaje)
{

}



static void opcionAlta()
{
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];

    if(val_getString(auxNombre, "Nombre?\n", "Error\n",2,50)==0)
    {
        if(val_getString(auxApellido, "Apellido?\n", "Error\n",2,50)==0)
        {
            if(val_getDni(auxDni, "DNI?\n", "Error\n",2,50)==0)
            {
                cont_altaCliente(auxNombre,auxApellido,auxDni);
            }
        }
    }
}

static void opcionBaja()
{
    int auxId;

    if((val_getUnsignedInt(&auxId,"Id a dar de baja\n", "Error\n",2,0,99999)==0))
    {
        if(cont_existeCliente(auxId)!=0)
        {
            printf("El ID no existe\n");
        }
        else
        {
            cont_bajaCliente(auxId);
        }
    }

}

static void opcionModificacion()
{
    int auxId;
    int auxEstado;
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];

    if((val_getUnsignedInt(&auxId,"Id a modificar\n", "Error\n",2,0,99999)==0))
    {
        if(cont_existeCliente(auxId)!=0)
        {
            printf("El ID no existe");
        }
        else
        {
            if(val_getString(auxNombre, "Nombre\n?", "Error\n",2,50)==0)
            {
                if(val_getString(auxApellido, "Apellido?\n", "Error\n",2,50)==0)
                {
                    if(val_getDni(auxDni, "DNI?\n", "Error\n",2,50)==0)
                    {
                        if(val_getUnsignedInt(&auxEstado,"Estado?\nACTIVO= 0\nINACTIVO= 1", "Error",2,0,1)==0)
                        {
                            if(auxEstado == 0 || auxEstado == 1)
                            {
                                cont_modificarCliente(auxNombre,auxApellido,auxDni,auxId,auxEstado);
                            }
                        }
                    }
                }
            }
        }
    }
}

static void opcionListado()
{
    cont_listarCliente();
}



//**************************************Alquiler


static void opcionAltaAlquiler()
{
    int idCliente,equipo,tiempoEstimado;

    if (val_getUnsignedInt(&idCliente, "idCliente?\n", "Error",2,0,99999)==0)
    {
        if (val_getUnsignedInt(&equipo, "equipo?\n", "Error",2,0,99999)==0)
        {
                if (val_getUnsignedInt(&tiempoEstimado, "Tiempo estimado?\n", "Error",2,0,99999)==0)
                {
                    cont_altaAlquiler(idCliente,equipo,tiempoEstimado);
                }
        }
    }
}

static void opcionBajaAlquiler()
{
    int auxId,auxTiempoReal;

    if((val_getUnsignedInt(&auxId,"Id a dar de baja", "Error",2,0,99999)==0))
    {
        if(cont_existeAlquiler(auxId)!=0)
        {
            printf("El ID de Alquiler no existe\n");
        }
        else
        {
            if(val_getUnsignedInt(&auxTiempoReal,"Tiempo Real?", "Error",2,0,9999)==0)
            {
                cont_bajaAlquiler(auxId,auxTiempoReal);
            }
        }
    }
}

void vista_mostrarAlquiler(ArrayList* pListaAlquiler)
{
    int i;
    Alquiler* auxAlquiler;
    for(i=0;i<al_len(pListaAlquiler);i++)
        {
            auxAlquiler=al_get(pListaAlquiler,i);
            if(auxAlquiler->estado==ESTADO_ALQUILADO)
            {
                printf("ID: %d - ID Cliente: %d - Equipo: %d\n",alquiler_getId(auxAlquiler),alquiler_getIdCliente(auxAlquiler)
                                                               ,alquiler_getEquipo(auxAlquiler));
            }
        }
}

static void opcionListadoAlquiler()
{
    cont_listarAlquiler();
}

/****************************************************************/

static void opcionInformes()
{
    cont_informe1();
    cont_informe2();
    cont_informe3();
}

void vista_mostrarInformes(Cliente* auxCliente)
{
    printf("El cliente con mas alquileres es: %s %s\n",cliente_getNombre(auxCliente),cliente_getApellido(auxCliente));
}


