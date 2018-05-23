#include "ArrayList.h"

#ifndef _LOGENTRY_H
#define _LOGENTRY_H
typedef struct
{
        char date[11];
        char time[6];
        int serviceId;
        int gravedad;
        char msg[65];
}LogEntry;
//#define CLIENTE_ESTADO_ACTIVO 1
//#define CLIENTE_ESTADO_INACTIVO 0
#endif// _LOGENTRY_H

LogEntry* logEntry_new(char* date,char* time,int serviceId,int gravedad,char* msg);
void logEntry_delete(LogEntry* this);
int logEntry_setDate(LogEntry* this,char* date);
int logEntry_setTime(LogEntry* this,char* time);
int logEntry_setServiceId(LogEntry* this,int serviceId);
int logEntry_setGravedad(LogEntry* this,int gravedad);
int logEntry_setMsg(LogEntry* this,char* msg);
char* logEntry_getDate(LogEntry* this);
char* logEntry_getTime(LogEntry* this);
int logEntry_getServiceId(LogEntry* this);
int logEntry_getGravedad(LogEntry* this);
char* logEntry_getMsg(LogEntry* this);
LogEntry* logEntry_findByDate(ArrayList* pArray,char* date);
LogEntry* logEntry_findByTime(ArrayList* pArray,char* time);
LogEntry* logEntry_findByServiceId(ArrayList* pArray,int serviceId);
LogEntry* logEntry_findByGravedad(ArrayList* pArray,int gravedad);
LogEntry* logEntry_findByMsg(ArrayList* pArray,char* msg);
int logEntry_compareByDate(void* pA ,void* pB);
int logEntry_compareByTime(void* pA ,void* pB);
int logEntry_compareByServiceId(void* pA ,void* pB);
int logEntry_compareByGravedad(void* pA ,void* pB);
int logEntry_compareByMsg(void* pA ,void* pB);



/***********************************/

void logEntry_imprimir(void* pCliente); //cambiar nombre entidad
int logEntry_filterLog(void* item);
