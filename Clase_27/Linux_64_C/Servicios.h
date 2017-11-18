#include "ArrayList.h"

#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED
typedef struct
{
    int id;
    char descripcion[51];
    int estado;

}Servicio;
#endif // SOCIO_H_INCLUDED

#define SERVICIO_ESTADO_ACTIVO 0
#define SERVICIO_ESTADO_INACTIVO 1

Servicio* ser_new(char* Descripcion, int id, int estado);
int ser_delete(Servicio*);

int ser_setDescripcion(Servicio*,char* nombre);
char* ser_getDescripcion(Servicio*);

int ser_setId(Servicio* this,int id);
int ser_getId(Servicio* this);

int ser_setEstado(Servicio* this,int estado);
int ser_getEstado(Servicio* this);

Servicio* ser_findById(ArrayList*, int);




