#include "ArrayList.h"

#ifndef _USUARIO_H
#define _USUARIO_H
typedef struct
{
        int id_usuario;
        int popularidad;
        char nick[50];
}Usuario;
#endif// _USUARIO_H

Usuario* usuario_new(int id_usuario,int popularidad,char* nick);
void usuario_delete(Usuario* this);
int usuario_setId_usuario(Usuario* this,int id_usuario);
int usuario_setPopularidad(Usuario* this,int popularidad);
int usuario_setNick(Usuario* this,char* nick);
int usuario_getId_usuario(Usuario* this);
int usuario_getPopularidad(Usuario* this);
char* usuario_getNick(Usuario* this);
Usuario* usuario_findById_usuario(ArrayList* pArray,int id_usuario);
Usuario* usuario_findByPopularidad(ArrayList* pArray,int popularidad);
Usuario* usuario_findByNick(ArrayList* pArray,char* nick);

void usuario_print(void* this);


