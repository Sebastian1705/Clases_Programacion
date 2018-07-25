#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "LogEntry.h"
#include "Service.h"
#include "Vista.h"
#include "DataManager.h"

static ArrayList* nominaLogEntry;

static ArrayList* nominaService;

static ArrayList* gravedadMenorA3;
static ArrayList* gravedad3;
static ArrayList* gravedad4a7;
static ArrayList* gravedadMayorA7;

void cont_init()
{
    nominaLogEntry = al_newArrayList();
    dm_readAllLogEntry(nominaLogEntry);

    nominaService = al_newArrayList();
    dm_readAllService(nominaService);

    gravedadMenorA3 = al_newArrayList();
    gravedad3 = al_newArrayList();
    gravedad4a7 = al_newArrayList();
    gravedadMayorA7 = al_newArrayList();


    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_listarLogEntry ()
{
    vista_mostrarLogEntry(nominaLogEntry);
    return 0;
}

int cont_existeLogEntry (int id)
{
    int retorno = -1;/*
    LogEntry* auxLogEntry = logEntry_findById(nominaLogEntry,id);

    if (auxLogEntry != NULL && logEntry_getEstado(auxLogEntry) == CLIENTE_ESTADO_ACTIVO)
        retorno = 0;*/

    return retorno;
}

int cont_ordenarLogEntry()
{
    al_sort(nominaLogEntry,logEntry_compareByServiceId,0);
    return 0;
}


/*****************************************///Service


int cont_listarService ()
{
    vista_mostrarService(nominaService);
    return 0;
}

int cont_existeService (int id)
{
    int retorno = -1;/*
    Service* auxService = service_findById(nominaService,id);

    if (auxService != NULL && service_getEstado(auxService) == ALQUILER_ESTADO_ACTIVO)
    {
        retorno = 0;
    }*/
    return retorno;
}

int cont_ordenarService()
{
    al_sort(nominaService,service_compareById,0);
    return 0;
}



/**********************************************///informes


void cont_procesarInformacion()
{
    int i;
    int opcion;
    void* aux=NULL;
    if (nominaLogEntry != NULL)
    {
        for(i=0; i<nominaLogEntry->len(nominaLogEntry); i++)
        {
            aux = nominaLogEntry->get(nominaLogEntry,i);
            opcion = logEntry_filterLog(aux);
            switch(opcion)
            {
            case 0:
                al_add(gravedadMenorA3,aux);
                break;
            case 1:
                al_add(gravedad3,aux);
                break;
            case 2:
                al_add(gravedad4a7,aux);
                break;
            case 3:
                al_add(gravedadMayorA7,aux);
                //printf("%d\n", logEntry_getGravedad(aux));
                break;
            }
        }
    }
    dm_save3(gravedad3,nominaService,ARCHIVO_WARNINGS);
    dm_save3(gravedadMayorA7,nominaService,ARCHIVO_ERRORS);

}

