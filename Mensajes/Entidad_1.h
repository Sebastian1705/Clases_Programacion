
#include "ArrayList.h"

#ifndef _MENSAJE_H
#define _MENSAJE_H
typedef struct
{
        int id_mensaje;
        int id_usuario;
        int popularidad;
        char mensaje[4096];
}Mensaje;
#endif// _MENSAJE_H

Mensaje* mensaje_new(int id_mensaje,int id_usuario,int popularidad,char* mensaje
);
void mensaje_delete(Mensaje* this);
int mensaje_setId_mensaje(Mensaje* this,int id_mensaje);
int mensaje_setId_usuario(Mensaje* this,int id_usuario);
int mensaje_setPopularidad(Mensaje* this,int popularidad);
int mensaje_setMensaje(Mensaje* this,char* mensaje);
int mensaje_getId_mensaje(Mensaje* this);
int mensaje_getId_usuario(Mensaje* this);
int mensaje_getPopularidad(Mensaje* this);
char* mensaje_getMensaje(Mensaje* this);
Mensaje* mensaje_findById_mensaje(ArrayList* pArray,int id_mensaje);
Mensaje* mensaje_findById_usuario(ArrayList* pArray,int id_usuario);
Mensaje* mensaje_findByPopularidad(ArrayList* pArray,int popularidad);
Mensaje* mensaje_findByMensaje(ArrayList* pArray,char* mensaje);

void mensaje_print(void* this);
