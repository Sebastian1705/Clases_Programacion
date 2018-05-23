#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"
#include "Log.h"
#include"Service.h"

static void opcionAltaLog();
static void opcionBajaLog();
static void opcionModificacionLog();
static void opcionListadoLog();
static void opcionOrdenarLog();

static void opcionAltaService();
static void opcionBajaService();
static void opcionModificacionService();
static void opcionListadoService();
static void opcionOrdenarService();

static int idiomaVista;

int vista_init (int idioma)
{
    idiomaVista = idioma;
    return 0;
}

int vista_mostrarMenu()
{
    char buffer[10];
    int option=0;

    while(option != 6)
    {
        val_getInt(buffer, MENU_PPAL_ES, MENU_PPAL_ERROR_ES,2,5);
        option = atoi(buffer);

        switch(option)
        {
            case 1:
                opcionListadoLog();
                break;
            case 2:
                opcionAltaLog();
                break;
            case 3:
                opcionBajaLog();
                break;
            case 4:
                opcionModificacionLog();
                break;
            case 5:
                opcionOrdenarLog();
                break;
            case 6:
                opcionListadoService();
                break;
            case 7:
                opcionAltaService();
                break;
            case 8:
                opcionBajaService();
                break;
            case 9:
                opcionModificacionService();
                break;
            case 10:
                opcionOrdenarService();
                break;
        }
    }

    return 0;
}

void vista_mostrarLog(ArrayList* pListaLog)
{

    printf("\t%s\t\t%s\t\t\t%s\t\t%s\t\t%s\n","FECHA","HORA","ID SERVICIO","GRAVEDAD","MENSAJE");
    printf("***********************************************************************************************************************\n");
    al_map(pListaLog,log_printOne);


    printf("***********************************************************************************************************************\n");

}


void mostrarError(char * mensaje)
{

    printf("\nIMPRIMO ERROR\n");

}

static void opcionAltaLog()
{
    char a[50];
    char b[50];
    char c[50];
    if(val_getString(a, "A? ", "Error",2,50) == 0 &&
       val_getString(b, "B? ", "Error",2,50) == 0 &&
       val_getInt(c, "C? ", "Error",2,50) == 0)
    {
        cont_altaLog(a,b,atoi(c));
    }


}

static void opcionBajaLog()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        cont_bajaLog(id);
    }

}

static void opcionModificacionLog()
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
            cont_modificarLog(id,a,b,atoi(c));
        }
    }

}

static void opcionListadoLog()
{
    cont_listarLog();
}

static void opcionOrdenarLog()
{
    cont_ordenarLog();
}



void vista_mostrarService(ArrayList* pListaService)
{
printf("\t%s\t\t%s\t\t\t%s\n","ID","NOBRE SERVICIO","EMAIL SOPORTE");
    printf("***********************************************************************************************************************\n");
    al_map(pListaService,service_imprimir);


    printf("***********************************************************************************************************************\n");

}


static void opcionAltaService()
{
    char a[50];
    char b[50];
    char c[50];
    if(val_getString(a, "A? ", "Error",2,50) == 0 &&
       val_getString(b, "B? ", "Error",2,50) == 0 &&
       val_getInt(c, "C? ", "Error",2,50) == 0)
    {
        cont_altaService(a,b,atoi(c));
    }


}

static void opcionBajaService()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        cont_bajaService(id);
    }

}

static void opcionModificacionService()
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
            cont_modificarService(id,a,b,atoi(c));
        }
    }


}

static void opcionListadoService()
{
    cont_listarService();
}

static void opcionOrdenarService()
{
    cont_ordenarService();
}
