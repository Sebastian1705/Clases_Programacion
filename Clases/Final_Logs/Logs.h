

#include "ArrayList.h"

#ifndef _LOGS_H
#define _LOGS_H
typedef struct
{
	int id;
	char date[11];
	char time[6];
	int serviceId;
	int gravedad;
	char msg[65];
}Logs;
#endif// _LOGS_H

Logs* logs_new(int id,char* date,char* time,int serviceId,int gravedad,char* msg);
void logs_delete(Logs* this);
int logs_setId(Logs* this,int id);
int logs_setDate(Logs* this,char* date);
int logs_setTime(Logs* this,char* time);
int logs_setServiceId(Logs* this,int serviceId);
int logs_setGravedad(Logs* this,int gravedad);
int logs_setMsg(Logs* this,char* msg);
int logs_getId(Logs* this);
char* logs_getDate(Logs* this);
char* logs_getTime(Logs* this);
int logs_getServiceId(Logs* this);
int logs_getGravedad(Logs* this);
char* logs_getMsg(Logs* this);
Logs* logs_findById(ArrayList* pArray,int id);
Logs* logs_findByDate(ArrayList* pArray,char* date);
Logs* logs_findByTime(ArrayList* pArray,char* time);
Logs* logs_findByServiceId(ArrayList* pArray,int serviceId);
Logs* logs_findByGravedad(ArrayList* pArray,int gravedad);
Logs* logs_findByMsg(ArrayList* pArray,char* msg);
int logs_compareById(void* pA ,void* pB);
int logs_compareByDate(void* pA ,void* pB);
int logs_compareByTime(void* pA ,void* pB);
int logs_compareByServiceId(void* pA ,void* pB);
int logs_compareByGravedad(void* pA ,void* pB);
int logs_compareByMsg(void* pA ,void* pB);
