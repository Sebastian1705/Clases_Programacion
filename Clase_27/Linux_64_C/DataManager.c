
#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Socio.h"
#include "DataManager.h"
#include "Servicios.h"
#include "Relacion.h"

int dm_saveAll(ArrayList* pArraySocios)
{
    int i;
    int retorno=-1;
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
    return retorno;
}

int dm_readAll(ArrayList* pArraySocios)
{
    int retorno=-1;
    Socio auxSocio;
    int maxId=0;
    Socio* pSocio=NULL;
    FILE* pArchivoSocios=fopen(ARCHIVO_SOCIOS,"rb");

    if(pArchivoSocios!=NULL)
    {
        do{
            if(fread(&auxSocio,sizeof(Socio),1,pArchivoSocios)==1)
            {
                pSocio=soc_new(auxSocio.nombre,auxSocio.apellido,auxSocio.dni,auxSocio.id,auxSocio.estado);
                al_add(pArraySocios,pSocio);
                if(auxSocio.id>maxId)
                {
                    maxId=auxSocio.id;
                }
                retorno=maxId;
            }
        }while(!feof(pArchivoSocios));
        fclose(pArchivoSocios);
    }
    return retorno;
}


int dm_saveAllServicios(ArrayList* pArrayServicios)
{
    int i;
    int retorno=-1;
    FILE* pArchivoServicios=fopen(ARCHIVO_SERVICIOS,"wb");
    void* pServicio=NULL;
    if(pArchivoServicios!=NULL)
    {
        for(i=0;i<al_len(pArrayServicios);i++)
        {
            pServicio=al_get(pArrayServicios,i);
            fwrite(pServicio,sizeof(Servicio),1,pArchivoServicios);
            retorno=0;
        }

    }
    fclose(pArchivoServicios);
    return retorno;
}

int dm_readAllServicios(ArrayList* pArrayServicios)
{
    int retorno=-1;
    Servicio auxServicio;
    int maxId=0;
    Servicio* pServicio=NULL;
    FILE* pArchivoServicios=fopen(ARCHIVO_SERVICIOS,"rb");

    if(pArchivoServicios!=NULL)
    {
        do{
            if(fread(&auxServicio,sizeof(Servicio),1,pArchivoServicios)==1)
            {
                pServicio=ser_new(auxServicio.descripcion,auxServicio.id,auxServicio.estado);
                al_add(pArrayServicios,pServicio);
                if(auxServicio.id>maxId)
                {
                    maxId=auxServicio.id;
                }
                retorno=maxId;
            }
        }while(!feof(pArchivoServicios));
        fclose(pArchivoServicios);
    }
    return retorno;
}

int dm_saveAllRelacion(ArrayList* pArrayRelaciones)
{
    int i;
    int retorno=-1;
    FILE* pArchivoRelacion=fopen(ARCHIVO_RELACIONES,"wb");
    void* pRelacion=NULL;
    if(pArchivoRelacion!=NULL)
    {
        for(i=0;i<al_len(pArrayRelaciones);i++)
        {
            pRelacion=al_get(pArrayRelaciones,i);
            fwrite(pRelacion,sizeof(Relacion),1,pArchivoRelacion);
            retorno=0;
        }

    }
    fclose(pArchivoRelacion);
    return retorno;
}

int dm_readAllRelacion(ArrayList* pArrayRelaciones)
{
    int retorno=-1;
    Relacion auxRelacion;
    int maxId=0;
    Relacion* pRelacion=NULL;
    FILE* pArchivoRelacion=fopen(ARCHIVO_RELACIONES,"rb");

    if(pArchivoRelacion!=NULL)
    {
        do{
            if(fread(&auxRelacion,sizeof(Relacion),1,pArchivoRelacion)==1)
            {
                pRelacion=rel_new(auxRelacion.idServicio,auxRelacion.idSocio,auxRelacion.id,auxRelacion.estado);
                al_add(pArrayRelaciones,pRelacion);
                if(auxRelacion.id>maxId)
                {
                    maxId=auxRelacion.id;
                }
                retorno=maxId;
            }
        }while(!feof(pArchivoRelacion));
        fclose(pArchivoRelacion);
    }
    return retorno;
}
