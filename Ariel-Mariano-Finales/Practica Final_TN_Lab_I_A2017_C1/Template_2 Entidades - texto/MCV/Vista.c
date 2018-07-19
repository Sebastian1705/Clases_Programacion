#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "LogEntry.h"
#include "Service.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"

static int idiomaVista = VISTA_IDIOMA_ES;

static void opcionListadoLogEntry();
static void opcionOrdenarLogEntry();

static void opcionListadoService();
static void opcionOrdenarService();

static void opcionProcesarInformacion();
static void opcionMostrarEstadisticas();


int vista_init (int idioma)
{
    idiomaVista = idioma;
    return 0;
}

int vista_mostrarMenu()
{
    int buffer;
    int option=0;

    while(option != 7)
    {
        val_getUnsignedInt(&buffer, MENU_PPAL_ES, MENU_PPAL_ERROR_ES,2,1,11);
        option = buffer;

        switch(option)
        {
        case 1:
            opcionListadoLogEntry();
            break;
        case 2:
            opcionOrdenarLogEntry();
            break;
        case 3:
            opcionListadoService();
            break;
        case 4:
            opcionOrdenarService();
            break;
        case 5:
            opcionProcesarInformacion();
            break;
        case 6:
            opcionMostrarEstadisticas();
            break;
        }
    }

    return 0;
}


static void opcionListadoLogEntry()
{
    cont_listarLogEntry();
}

void vista_mostrarLogEntry(ArrayList* pListaLogEntry)
{
    al_map(pListaLogEntry,logEntry_imprimir);
}

static void opcionOrdenarLogEntry()
{
    cont_ordenarLogEntry();
}

void vista_mostrarError(char* mensaje)
{
    printf("%s",mensaje);
}



/*********************************************************///Service

static void opcionListadoService()
{
    cont_listarService();
}

void vista_mostrarService(ArrayList* pListaService)
{
    al_map(pListaService,service_imprimir);

    /*int i;
    Service* auxService;
    for(i=0;i<al_len(pListaService);i++)
        {
            auxService=al_get(pListaService,i);
            if(auxService->estado==ESTADO_ALQUILADO)
            {
                auxService = al_get(pListaService,i);
                printf("ID: %d - ID LogEntry: %d\n",service_getId(auxService),service_getIdLogEntry(auxService));
            }
        }*/
}


static void opcionOrdenarService()
{
    cont_ordenarService();
}

/*******************************************************///Informes

static void opcionProcesarInformacion()
{
    cont_procesarInformacion();

}

static void opcionMostrarEstadisticas()
{

}

