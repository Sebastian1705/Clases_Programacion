#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "LogEntry.h"
#include "Service.h"
#include "ArrayList.h"
#include "Parser.h"


static void opcion_leerLogs();
static void opcion_procesarInformacion();
static void opcion_mostrarEstadisticas();

static ArrayList* nominaLogEntry;
static ArrayList* nominaService;
static ArrayList* gravedadMenorA3;
static ArrayList* gravedad3;
static ArrayList* gravedad4a7;
static ArrayList* gravedadMayorA7;

int f_init()
{
    nominaLogEntry = al_newArrayList();
    nominaService = al_newArrayList();

    gravedadMenorA3 = al_newArrayList();
    gravedad3 = al_newArrayList();
    gravedad4a7 = al_newArrayList();
    gravedadMayorA7 = al_newArrayList();

    f_mostrarMenu();

    return 0;
}

int f_mostrarMenu()
{
    char buffer[10];
    int option=0;

    while(option != 4)
    {
        val_getUnsignedInt(buffer, MENU, MENU_ERROR,2,5);
        option = atoi(buffer);

        switch(option)
        {
        case 1:
            opcion_leerLogs();
            al_map(nominaLogEntry,logEntry_print);
            //al_map(nominaService,service_print);
            break;
        case 2:
            opcion_procesarInformacion();
            break;
        case 3:
            opcion_mostrarEstadisticas();
            break;
        }
    }
    return 0;
}

static void opcion_leerLogs()
{
    f_leerLogs();
}

static void opcion_procesarInformacion()
{
    f_procesarInformacion();
}

static void opcion_mostrarEstadisticas()
{

}

int f_leerLogs()
{
    p_leerLogEntry(nominaLogEntry);
    p_leerLogService(nominaService);

    return 0;
}

int f_procesarInformacion()
{
    int i;
    int opcion;
    LogEntry* aux = NULL;

    if (nominaLogEntry != NULL)
    {
        for(i=0; i < al_len(nominaLogEntry); i++)
        {
            aux = al_get(nominaLogEntry,i);
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
                    break;
            }
        }
    }
    return 0;
}

