#include "ArrayList.h"
#ifndef _LOGS_H
#define _LOGS_H
typedef struct
{
	char fecha[50];
	char hora[50];
	int id_servicio;
	int gravedad;
	char msj_error[50];
	int id;
}Logs;
#endif// _LOGS_H

Logs* logs_new(char* fecha,char* hora,int id_servicio,int gravedad,char* msj_error,int id);
void logs_delete(Logs* this);
int logs_setFecha(Logs* this,char* fecha);
int logs_setHora(Logs* this,char* hora);
int logs_setId_servicio(Logs* this,int id_servicio);
int logs_setGravedad(Logs* this,int gravedad);
int logs_setMsj_error(Logs* this,char* msj_error);
int logs_setId(Logs* this,int id);
char* logs_getFecha(Logs* this);
char* logs_getHora(Logs* this);
int logs_getId_servicio(Logs* this);
int logs_getGravedad(Logs* this);




