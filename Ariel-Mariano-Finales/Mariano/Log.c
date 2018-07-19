
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Log.h"

Log* log_new(char* fecha,char* hora,int idServicio,int gravedad,char* mensajeError)
{
        Log* this = malloc(sizeof(Log));

        if(this != NULL)
        {

                log_setFecha(this,fecha);
                log_setHora(this,hora);
                log_setIdServicio(this,idServicio);
                log_setGravedad(this,gravedad);
                log_setMensajeError(this,mensajeError);
        }
        return this;
}

void log_delete(Log* this)
{
        free(this);
}

int log_setFecha(Log* this,char* fecha)
{
        strcpy(this->fecha,fecha);
        return 0;
}

int log_setHora(Log* this,char* hora)
{
        strcpy(this->hora,hora);
        return 0;
}

int log_setIdServicio(Log* this,int idServicio)
{
        this->idServicio = idServicio;
        return 0;
}

int log_setGravedad(Log* this,int gravedad)
{
        this->gravedad = gravedad;
        return 0;
}

int log_setMensajeError(Log* this,char* mensajeError)
{
        strcpy(this->mensajeError,mensajeError);
        return 0;
}

char* log_getFecha(Log* this)
{
        return this->fecha;
}

char* log_getHora(Log* this)
{
        return this->hora;
}

int log_getIdServicio(Log* this)
{
        return this->idServicio;
}

int log_getGravedad(Log* this)
{
        return this->gravedad;
}

char* log_getMensajeError(Log* this)
{
        return this->mensajeError;
}

Log* log_findByFecha(ArrayList* pArray,char* fecha)
{

        int i;
        Log* aux;
        Log* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(fecha,log_getFecha(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Log* log_findByHora(ArrayList* pArray,char* hora)
{

        int i;
        Log* aux;
        Log* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(hora,log_getHora(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Log* log_findByIdServicio(ArrayList* pArray,int idServicio)
{

        int i;
        Log* aux;
        Log* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(idServicio == log_getIdServicio(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Log* log_findByGravedad(ArrayList* pArray,int gravedad)
{

        int i;
        Log* aux;
        Log* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(gravedad == log_getGravedad(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Log* log_findByMensajeError(ArrayList* pArray,char* mensajeError)
{

        int i;
        Log* aux;
        Log* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(mensajeError,log_getMensajeError(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

int log_compareByFecha(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(log_getFecha(pA),log_getFecha(pB));

        return retorno;
}

int log_compareByHora(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(log_getHora(pA),log_getHora(pB));

        return retorno;
}

int log_compareByIdServicio(void* pA ,void* pB)
{

        int retorno = 0;

        if(log_getIdServicio(pA) > log_getIdServicio(pB))
                retorno = 1;
        else if(log_getIdServicio(pA) < log_getIdServicio(pB))
                retorno = -1;

        return retorno;
}

int log_compareByGravedad(void* pA ,void* pB)
{

        int retorno = 0;

        if(log_getGravedad(pA) > log_getGravedad(pB))
                retorno = 1;
        else if(log_getGravedad(pA) < log_getGravedad(pB))
                retorno = -1;

        return retorno;
}

int log_compareByMensajeError(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(log_getMensajeError(pA),log_getMensajeError(pB));

        return retorno;
}


void log_printOne(void* this)
{
    printf("\t%s\t\t%s\t\t\t%d\t\t%d\t\t%s\n",log_getFecha(this),
                                          log_getHora(this),
                                          log_getGravedad(this),
                                          log_getGravedad(this),
                                          log_getMensajeError(this));

}
