#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Validaciones.h"
#include "Funciones.h"
#include "Parser.h"
#include "Entidad_1.h"
#include "Entidad_2.h"

/*
int p_guardar(ArrayList* lista, char* archivo)
{
    int i;
    int retorno=-1;

    FILE* pFile=fopen(archivo,"w");
    Entidad* auxiliar=NULL;

    if(pFile!=NULL)
    {
        fprintf(pFile,"b_1,b_2,b_3,b_4,b_5\n");
        for(i=0; i<al_len(lista); i++)
        {
            auxiliar=al_get(lista,i);
            fprintf(pFile, "%s,%s,%s,%s,%s\n",entidad_get()) //get de cada item
            retorno=0;
        }
    }
    fclose(pFile);
    return retorno;
}
*/

int p_leerLog(ArrayList* lista, char* archivo)
{
    int retorno = -1;
    char b_1[4096];
    char b_2[4096];
    char b_3[4096];
    char b_4[4096];
    char b_5[4096];

    FILE* pFile = fopen(archivo, "r");

    LogEntry* auxiliar;

    if(pFile != NULL)
    {
        retorno = 0;
        do
        {
            if(fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",b_1,b_2,b_3,b_4,b_5)==5)
            {
                if(   !val_validarTelefono(b_1) &&
                        !val_validarHora(b_2) &&
                        !val_validarUnsignedInt(b_3) &&
                        !val_validarUnsignedInt(b_4) &&
                        !val_validarAlfanumerico(b_5))
                {
                    auxiliar = logEntry_new(b_1,b_2,atoi(b_3),atoi(b_4),b_5);
                    al_add(lista,auxiliar);
                }
            }
        }
        while(!feof(pFile));
    }
    return retorno;
}

int p_leerService(ArrayList* lista, char* archivo)
{
    int retorno = -1;
    char b_1[4096];
    char b_2[4096];
    char b_3[4096];

    FILE* pFile = fopen(archivo, "r");

    Service* auxiliar;

    if(pFile != NULL)
    {
        retorno = 0;
        do
        {
            if(fscanf(pFile,"%[^;];%[^;];%[^\n]\n",b_1,b_2,b_3)==3)
            {
                if(   !val_validarUnsignedInt(b_1) &&
                        !val_validarEmail(b_2)  &&
                        !val_validarEmail(b_3))
                {
                    auxiliar = service_new(atoi(b_1),b_2,b_3);
                    al_add(lista,auxiliar);
                }
            }
        }
        while(!feof(pFile));
    }

    return retorno;
}


int p_guardar(ArrayList* lista_log, ArrayList* lista_Service,char* archivo)
{
    int i;
    int retorno=-1;

    FILE* pFile=fopen(archivo,"w");
    LogEntry* auxLog=NULL;
    Service* auxService=NULL;

    if(pFile!=NULL)
    {
        for(i=0; i<al_len(lista_log); i++)
        {
            auxLog=al_get(lista_log,i);
            auxService = service_findById(lista_Service,logEntry_getServiceId(auxLog));
            fprintf(pFile, "%s;%s;%s;%s;%s\n",  logEntry_getDate(auxLog),
                    logEntry_getTime(auxLog),
                    service_getName(auxService),
                    logEntry_getMsg(auxLog),
                    service_getEmail(auxService));
            retorno=0;
        }
    }
    fclose(pFile);
    return retorno;
}
