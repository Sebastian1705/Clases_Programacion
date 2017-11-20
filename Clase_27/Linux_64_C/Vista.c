#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Socio.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"
#include "Servicios.h"
#include "Relacion.h"

static int idiomaVista = VISTA_IDIOMA_ES;

static void opcionAlta();
static void opcionBaja();
static void opcionModificacion();

static void opcionAltaServicio();
static void opcionBajaServicio();

static void opcionListado();

int vista_init (int idioma)
{
    idiomaVista = idioma;
    return 0;
}

int vista_mostrarMenu()
{
    char buffer[10];
    int option=0;

    while(option != 8)
    {
        val_getInt(buffer, MENU_PPAL_ES, MENU_PPAL_ERROR_ES,2,5);
        option = atoi(buffer);

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
                opcionAltaServicio();
                break;
            case 6:
                opcionBajaServicio();
                break;
            case 7:

                break;


        }
    }

    return 0;
}

void vista_mostrarSocios(ArrayList* pListaSocios)
{
    int i;
    Socio* auxSocio;
    for(i=0;i<al_len(pListaSocios);i++)
        {
            auxSocio=al_get(pListaSocios,i);
            if(auxSocio->estado==SOCIO_ESTADO_ACTIVO)
            {
            auxSocio = al_get(pListaSocios,i);
            printf("NOMBRE: %s - APELLIDO: %s- ID: %d - DNI: %s\n",soc_getNombre(auxSocio),
                            soc_getApellido(auxSocio),soc_getId(auxSocio),soc_getDni(auxSocio));
            }
        }

}


void mostrarError(char *);

static void opcionAlta()
{
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];
    val_getString(auxNombre, "Nombre? ", "Error",2,50);
    val_getString(auxApellido, "Apellido? ", "Error",2,50);
    val_getInt(auxDni, "DNI? ", "Error",2,50);
    cont_altaSocio(auxNombre,auxApellido,auxDni);
}

static void opcionBaja()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        cont_bajaSocio(id);
    }

}

static void opcionModificacion()
{
    char auxId[10];
    int id;
    int estado;
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];
    char auxEstado[5];

    if((val_getUnsignedInt(auxId,"Id a modificar" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        if(val_getString(auxNombre, "Nombre? ", "Error",2,50)==0)
        {
            if(val_getString(auxApellido, "Apellido? ", "Error",2,50)==0)
            {
                if(val_getInt(auxDni, "DNI? ", "Error",2,50)==0)
                {
                    if(val_getUnsignedInt(auxEstado,"Estado?\nACTIVO= 0\nINACTIVO= 1", "Error",2,5)==0)
                    {
                        estado=atoi(auxEstado);
                        if(estado == 0 || estado == 1)
                        {
                            cont_modificarSocio(auxNombre,auxApellido,auxDni,id,estado);
                        }

                    }

                }
            }

        }

    }

}

static void opcionListado()
{
    cont_listarSocios();
    cont_listarServicios();
}


/**************************************************************************************/

static void opcionAltaServicio()
{
    char auxDescripcion[50];
    val_getString(auxDescripcion, "Descripcion del servicio: \n", "Error\n",2,50);
    cont_altaServicio(auxDescripcion);
}


static void opcionBajaServicio()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id de servicio a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        cont_bajaServicio(id);
    }

}

void vista_mostrarServicios(ArrayList* pListaServicios)
{
    int i;
    Servicio* auxServicio;
    for(i=0;i<al_len(pListaServicios);i++)
        {
            auxServicio = al_get(pListaServicios,i);
            if(auxServicio->estado==SERVICIO_ESTADO_ACTIVO)
            {
                auxServicio = al_get(pListaServicios,i);
                printf("Descripcion: %s - ID: %d\n",ser_getDescripcion(auxServicio),ser_getId(auxServicio));
            }
        }

}


/**************************************************************************************/

void vista_mostrarRelaciones(ArrayList* pListaRelaciones)
{
    int i;
    Relacion* auxRelacion;
    for(i=0;i<al_len(pListaRelaciones);i++)
    {
        auxRelacion = al_get(pListaRelaciones,i);
        if(auxRelacion->estado==RELACION_ESTADO_ACTIVO)
        {
            auxRelacion = al_get(pListaRelaciones,i);
            printf("idSocio: %d - idSocio: %d - ID: %d\n",rel_getIdSocio(auxRelacion),rel_getIdServicio(auxRelacion),rel_getId(auxRelacion));
        }
    }

}
