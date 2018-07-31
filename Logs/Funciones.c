#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Validaciones.h"
#include "Entidad_1.h"
#include "Entidad_2.h"
#include "Funciones.h"
#include "Parser.h"

static void opcion_1();
static void opcion_2();
static void opcion_3();
static void opcion_4();
static void opcion_5();

static ArrayList* lista_Log;
static ArrayList* lista_Service;
static ArrayList* lista_3;
static ArrayList* lista_4y7;
static ArrayList* lista_8;

int f_init()
{
    lista_Log = al_newArrayList();
    lista_Service = al_newArrayList();
    lista_3 = al_newArrayList();
    lista_4y7 = al_newArrayList();
    lista_8 = al_newArrayList();

    f_mostrarMenu();

    return 0;
}



int f_mostrarMenu()
{
    char buffer[10];
    int option=0;

    while(option != 6)
    {
        val_getUnsignedInt(buffer, MENU, MENU_ERROR,2,5);
        option = atoi(buffer);

        switch(option)
        {
        case 1:
            opcion_1();
            break;
        case 2:
            opcion_2();
            break;
        case 3:
            opcion_3();
            break;
        case 4:
            opcion_4();
            break;
        case 5:
            opcion_5();
            break;
        }
    }
    return 0;
}



static void opcion_1()
{
    f_opcion_1();
}

static void opcion_2()
{
    f_opcion_2();
}

static void opcion_3()
{
    f_opcion_3();
}

static void opcion_4()
{
    f_opcion_4();
}

static void opcion_5()
{
    f_opcion_5();
}



int f_opcion_1()
{
    p_leerLog(lista_Log,"log.txt");
    p_leerService(lista_Service,"services.txt");
    printf("\n\nLOGS\n\n");
    al_map(lista_Log,logEntry_print);
    printf("\n\nSERVICIOS\n\n");
    al_map(lista_Service,service_print);

    return 0;
}

int f_opcion_2()
{
    LogEntry* auxiliar;
    int i, gravedad;

    for(i=0; i<al_len(lista_Log); i++)
    {
        auxiliar = al_get(lista_Log,i);
        gravedad = logEntry_getGravedad(auxiliar);
        if(gravedad==3 && logEntry_getServiceId(auxiliar)!=45)
        {
            al_add(lista_3,auxiliar);
            p_guardar(lista_3,lista_Service,"warnings.txt");
        }
        else if(gravedad>3 && gravedad<=7)
        {
            al_add(lista_4y7,auxiliar);
        }
        else if(gravedad>7)
        {
            al_add(lista_8,auxiliar);
            p_guardar(lista_8, lista_Service, "errors.txt");
        }
    }
    printf("\nGravedad entre 4 y 7\n\n");
    f_opcion_4();
    return 0;
}

int f_opcion_3()
{
    f_mostrarFallos();
    return 0;
}

int f_opcion_4()
{
    int i;
    int retorno=-1;
    LogEntry* auxLog=NULL;
    Service* auxService=NULL;

    for(i=0; i<al_len(lista_4y7); i++)
    {
        auxLog=al_get(lista_4y7,i);
        auxService = service_findById(lista_Service,logEntry_getServiceId(auxLog));
        printf("%s;%s;%s;%s;%s\n",  logEntry_getDate(auxLog),
                                    logEntry_getTime(auxLog),
                                    service_getName(auxService),
                                    logEntry_getMsg(auxLog),
                                    service_getEmail(auxService));
        retorno=0;
    }
    return retorno;
}

int f_opcion_5()
{
    printf("logs: %d\tservices: %d\tlista_3: %d\tlista_4y7: %d\tlista_8: %d\n", al_len(lista_Log),
           al_len(lista_Service),
           al_len(lista_3),
           al_len(lista_4y7),
           al_len(lista_8));

    return 0;
}

int f_calcularFallos(int id)
{
    LogEntry* auxiliar;
    int i, contador = 0;
    for(i=0; i<al_len(lista_Log); i++)
    {
        auxiliar=al_get(lista_Log,i);
        if(logEntry_getServiceId(auxiliar) == id)
        {
                contador++;
        }
    }
    return contador;
}

void f_mostrarFallos()
{
    LogEntry* auxLog=NULL;
    Service* auxService=NULL;
    int i, max=0, idService, auxCantidad;
    for(i=0;i<al_len(lista_Log);i++)
    {
        auxLog = al_get(lista_Log,i);
        idService = logEntry_getServiceId(auxLog);
        auxCantidad = f_calcularFallos(idService);
        if(auxCantidad>max)
        {
            max = auxCantidad;
            auxService = service_findById(lista_Service,idService);
        }
    }

    f_mostarFallo(auxService);
    printf("La cantidad es %d\n\n",max);
}

void f_mostarFallo(Service* auxiliar)
{
    printf("\nEl service que mas fallos tiene es: %s\n",service_getName(auxiliar));
}

