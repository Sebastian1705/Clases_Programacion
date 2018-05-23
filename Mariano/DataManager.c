#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Validaciones.h"
#include "Log.h"
#include "Service.h"

int dm_saveAllLog(ArrayList* pArrayLog)
{

    int i;
    int retorno=-1;
    FILE* pFile=fopen("out.csv","w");
    void* pLogs=NULL;
    if(pFile!=NULL)
    {
    //fprintf(pFile,"id,first_name,last_name,age,type\n");
        for(i=0;i<al_len(pArrayLog);i++)
        {
            pLogs=al_get(pArrayLog,i);
            fprintf(pFile, "%s,%s,%d,%d,%s\n", log_getFecha(pLogs),
                                               log_getHora(pLogs),
                                               log_getIdServicio(pLogs),
                                               log_getGravedad(pLogs),
                                               log_getMensajeError(pLogs));

            retorno=0;
        }

    }
    fclose(pFile);
    return retorno;




    return retorno;
}

int dm_readAllLog(ArrayList* nominaLog)
{

    FILE *pFile;
    Log* auxLogEntry;
    int retorno=-1;

    char date[50],time[50],serviceId[50],gravedad[50],msg[65];

    pFile = fopen("log.txt","r");
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
                    auxLogEntry = log_new(date,time,atoi(serviceId),atoi(gravedad),msg);
                    al_add(nominaLog,auxLogEntry);
               }
        }
    }
    return retorno;

/*
    FILE *pFile;
	Log* auxLog;
	int retorno=-1;

    char var1[50],var2[50],var3[50],var4[50],var5[65];

    pFile = fopen("log.txt","r");

	if(pFile!=NULL)
    {
        retorno=0;
		//fscanf(pFile,"%[^;],%[^;],%[^;],%[^;],%[^\n]\n",var1,var2,var3,var4,var5);
        do{
            if(fscanf(pFile,"%[^;],%[^;],%[^;],%[^;],%[^\n]\n",var1,var2,var3,var4,var5) >0)
			{
				if(val_validarDate(var1)!=-1 && val_validarTime(var2)!=-1 && val_validarInt(var3)!=-1 && val_validarInt(var4)!=-1)
				{
					auxLog=log_new(var1, var2, atoi(var3),atoi(var4), var5);
					al_add(nominaLog, auxLog);
				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}
	return retorno;
	*/
}


/////////////////////////////////////// ENTIDAD 2

int dm_saveAllService(ArrayList* pArrayX)
{
    //int i;
    int retorno=-1;


 /*WRITE BINARY
    FILE* pArchivoSocios=fopen(ARCHIVO_SOCIOS,"wb");
    void* pSocio=NULL;
    if(pArchivoSocios!=NULL)
    {
        for(i=0;i<al_len(pArraySocios);i++)
        {
            pSocio=al_get(pArraySocios,i);
            fwrite(pSocio,sizeof(Socio),1,pArchivoSocios);
            retorno=0;
        }

    }
    fclose(pArchivoSocios);

END WRITE BINARY*/


/* WRITE TXT

 int i;
    int retorno=-1;
    FILE* pFile=fopen("out.csv","w");
    void* pLogs=NULL;
    if(pFile!=NULL)
    {
		fprintf(pFile,"id,first_name,last_name,age,type\n");
        for(i=0;i<al_len(list);i++)
        {
            pLogs=al_get(list,i);
            fprintf(pFile, "%d,%s,%s,%d,%d\n", log_getId(pLogs),
                                               log_getName(pLogs),
                                               log_getLastName(pLogs),
                                               log_getAge(pLogs),
                                               log_getType(pLogs));

            retorno=0;
        }

    }
    fclose(pFile);
    return retorno;


END WRITE TXT*/


    return retorno;
}

int dm_readAllService(ArrayList* pArrayService)
{

    FILE *pFile;
	Service* auxService;
	int retorno=-1;

    char var1[50],var2[50],var3[50];

    pFile = fopen("services.txt","r");

	if(pFile!=NULL)
    {
		//fscanf(pFile,"%[^;];%[^;];%[^\n]\n",var1,var2,var3);  leer la primer linea
        do{
            if(fscanf(pFile,"%[^;];%[^;];%[^\n]\n",var1,var2,var3) >0)
			{
				if(val_validarInt(var1)!=-1 && val_validarEmail(var3)!=-1)
				{
					auxService=service_new(atoi(var1), var2, var3);
					al_add(pArrayService, auxService);
					retorno=0;
				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}


    return retorno;
}

