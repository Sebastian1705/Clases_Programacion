#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "LogEntry.h"
#include "Service.h"
#include "DataManager.h"
#include "Validaciones.h"


int dm_readAllLogEntry(ArrayList* pArrayLogEntry)
{
    FILE *pFile;
    LogEntry* auxLogEntry;
    int retorno=-1;

    char date[50],time[50],serviceId[50],gravedad[50],msg[65];

    pFile = fopen(ARCHIVO_LOG,"r");
    if(pFile == NULL)
    {
        printf("No se pudo abrir el archivo para lectura\n");
    }
    else
    {
        //char aux[200];
        //fgets(aux,200,pFile); //leer primer fila
        //fscanf(pFile,"%[^\n]\n",aux,aux,aux,aux,aux);

        while(!feof(pFile))
        {
           fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",date,time,serviceId,gravedad,msg);
           if (val_validarDate(date) == 0 &&
               val_validarTime(time) == 0 &&
               val_getUnsignedIntFromFile(serviceId,0,9999) == 0 &&
               val_getUnsignedIntFromFile(gravedad,0,9999) == 0)
               //val_validarString(msg) == 0)
               {
                    auxLogEntry = logEntry_new(date,time,atoi(serviceId),atoi(gravedad),msg);
                    al_add(pArrayLogEntry,auxLogEntry);
               }
        }
        fclose(pFile);
    }
    return retorno;
}

int dm_saveAllLogEntry(ArrayList* nominaLogEntry)
{
    int i,retorno = -1;
    FILE *pArchivo;
    pArchivo=fopen(ARCHIVO_LOG, "w");
    if(pArchivo == NULL)
    {
        printf("No se pudo abrir el archivo para escritura\n");
    }
    else
    {
        fprintf(pArchivo,"serviceId;nombre;apellido;estado;dni\n");
        LogEntry* auxLogEntry;
        for(i=0; i<al_len(nominaLogEntry); i++)
        {
            auxLogEntry = al_get(nominaLogEntry,i);
            //if(auxLogEntry->estado == EMPLEADO_ESTADO_ACTIVO)
            //{
                fprintf(pArchivo,"%s;%s;%d;%d;%s\n", logEntry_getDate(auxLogEntry),
                        logEntry_getTime(auxLogEntry),logEntry_getServiceId(auxLogEntry),
                        logEntry_getGravedad(auxLogEntry),logEntry_getMsg(auxLogEntry));
            //}
        }
        retorno = 0;
    }
    fclose(pArchivo);
    //printf("\nArchivo guardado con exito\n");
    return retorno;
}






/**********************************************///Service


int dm_readAllService(ArrayList* pArrayService)
{
    FILE *pFile;
    Service* auxService;
    int retorno=-1;

    char id[50],name[50],email[65];

    pFile = fopen(ARCHIVO_SERVICE,"r");
    if(pFile == NULL)
    {
        printf("No se pudo abrir el archivo para lectura\n");
    }
    else
    {
        //char aux[200];
        //fgets(aux,200,pFile); //leer primer fila
        //fscanf(pFile,"%[^\n]\n",aux,aux,aux,aux,aux);

        while(!feof(pFile))
        {
           fscanf(pFile,"%[^;];%[^;];%[^\n]\n",id,name,email);
           if (val_getUnsignedIntFromFile(id,0,9999) == 0 &&
               //val_validarString(name) == 0 &&
               val_validarEmail(email) == 0)
               {
                    auxService = service_new(atoi(id),name,email);
                    al_add(pArrayService,auxService);
               }
        }
        fclose(pFile);
    }
    return retorno;
}

int dm_saveAllService(ArrayList* nominaService)
{
    int retorno = -1;/*
    int i;
    FILE *pArchivo;
    pArchivo=fopen(ARCHIVO_SERVICE, "w");
    if(pArchivo == NULL)
    {
        printf("No se pudo abrir el archivo para escritura\n");
    }
    else
    {
        fprintf(pArchivo,"id;nombre;apellido;estado;dni\n");
        Service* auxService;
        for(i=0; i<al_len(nominaService); i++)
        {
            auxService = al_get(nominaService,i);
            //if(auxService->estado == EMPLEADO_ESTADO_ACTIVO)
            //{
                fprintf(pArchivo,"%d,%d,%d,%d\n", service_getId(auxService),
                        service_getId(auxService),service_getEquipo(auxService),
                        service_getEstado(auxService));
            //}
        }
        retorno = 0;
    }
    fclose(pArchivo);
    //printf("\nArchivo guardado con exito\n");*/
    return retorno;
}


/***************************************************///

int dm_save3(ArrayList* pArrayLogEntry, ArrayList* pArrayService, char* file)
{
    int i,retorno = -1;
    FILE *pArchivo;
    pArchivo=fopen(file, "w");
    if(pArchivo == NULL)
    {
        printf("No se pudo abrir el archivo para escritura\n");
    }
    else
    {
        //fprintf(pArchivo,"serviceId;nombre;apellido;estado;dni\n");
        LogEntry* auxLogEntry;
        Service* auxService;
        for(i=0; i<al_len(pArrayLogEntry); i++)
        {
            auxLogEntry = al_get(pArrayLogEntry,i);
            auxService = service_findById(pArrayService,logEntry_getServiceId(auxLogEntry));
            //if(auxLogEntry->estado == EMPLEADO_ESTADO_ACTIVO)
            //{
                fprintf(pArchivo,"%s;%s;%s;%s;%s\n", logEntry_getDate(auxLogEntry),
                        logEntry_getTime(auxLogEntry),service_getName(auxService),
                        logEntry_getMsg(auxLogEntry),service_getEmail(auxService));
            //}
        }
        retorno = 0;
    }
    fclose(pArchivo);
    //printf("\nArchivo guardado con exito\n");
    return retorno;

}

















