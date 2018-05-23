#include "ArrayList.h"

#ifndef _LOG_H
#define _LOG_H
typedef struct
{
        char fecha[50];
        char hora[50];
        int idServicio;
        int gravedad;
        char mensajeError[50];
}Log;
#endif// _LOG_H

Log* log_new(char* fecha,char* hora,int idServicio,int gravedad,char* mensajeError);
void log_delete(Log* this);
int log_setFecha(Log* this,char* fecha);
int log_setHora(Log* this,char* hora);
int log_setIdServicio(Log* this,int idServicio);
int log_setGravedad(Log* this,int gravedad);
int log_setMensajeError(Log* this,char* mensajeError);
char* log_getFecha(Log* this);
char* log_getHora(Log* this);
int log_getIdServicio(Log* this);
int log_getGravedad(Log* this);
char* log_getMensajeError(Log* this);
Log* log_findByFecha(ArrayList* pArray,char* fecha);
Log* log_findByHora(ArrayList* pArray,char* hora);
Log* log_findByIdServicio(ArrayList* pArray,int idServicio);
Log* log_findByGravedad(ArrayList* pArray,int gravedad);
Log* log_findByMensajeError(ArrayList* pArray,char* mensajeError);
int log_compareByFecha(void* pA ,void* pB);
int log_compareByHora(void* pA ,void* pB);
int log_compareByIdServicio(void* pA ,void* pB);
int log_compareByGravedad(void* pA ,void* pB);
int log_compareByMensajeError(void* pA ,void* pB);


void log_printOne (void* this);
