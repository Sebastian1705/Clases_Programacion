#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "LogEntry.h"
#include "Service.h"
#include "Funciones.h"
#include "Validaciones.h"
#include "Parser.h"

int p_leerLogEntry(ArrayList* nominaLogEntry)
{
    int retorno = -1;
    char date[11];
	char time[6];
	char serviceId[5];
	char gravedad[5];
	char msg[65];

    FILE* pFile = fopen("log.txt", "r");
    LogEntry* auxiliar;

    if(pFile != NULL)
    {
        retorno = 0;
        if(fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",date,time,serviceId,gravedad,msg)==5)
        {
            do
            {
                if(fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",date,time,serviceId,gravedad,msg)==5)
                {
                    if( !val_validarFecha(date) && !val_validarHora(time) && val_validarString(msg) &&
                        !val_validarUnsignedInt(serviceId) && val_validarUnsignedInt(gravedad))
                    {
                        auxiliar = logEntry_new(date,time,atoi(serviceId),atoi(gravedad),msg);
                        al_add(nominaLogEntry,auxiliar);
                    }
                }
            }
            while(!feof(pFile));
        }
    }
    return retorno;
}

int p_leerLogService(ArrayList* nominaService)
{
    int retorno = -1;
    char id[5];
	char name[33];
	char email[65];

    FILE* pFile = fopen("services.txt", "r");
    Service* auxiliar;

    if(pFile != NULL)
    {
        retorno = 0;
        if(fscanf(pFile,"%[^;];%[^;];%[^\n]\n",id,name,email)==3)
        {
            do
            {
                if(fscanf(pFile,"%[^;];%[^;];%[^\n]\n",id,name,email)==3)
                {
                    if(!val_validarUnsignedInt(id) && val_validarEmail(name) && val_validarEmail(email))
                    {
                        auxiliar = service_new(atoi(id),name,email);
                        al_add(nominaService,auxiliar);
                    }
                }
            }
            while(!feof(pFile));
        }
    }
    return retorno;
}
