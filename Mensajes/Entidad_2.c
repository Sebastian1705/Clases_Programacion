#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Entidad_2.h"

Usuario* usuario_new(int id_usuario,int popularidad,char* nick)
{
        Usuario* this = malloc(sizeof(Usuario));

        if(this != NULL)
        {

                usuario_setId_usuario(this,id_usuario);
                usuario_setPopularidad(this,popularidad);
                usuario_setNick(this,nick);
        }
        return this;
}

void usuario_delete(Usuario* this)
{
        free(this);
}

int usuario_setId_usuario(Usuario* this,int id_usuario)
{
        this->id_usuario = id_usuario;
        return 0;
}

int usuario_setPopularidad(Usuario* this,int popularidad)
{
        this->popularidad = popularidad;
        return 0;
}

int usuario_setNick(Usuario* this,char* nick)
{
        strcpy(this->nick,nick);
        return 0;
}

int usuario_getId_usuario(Usuario* this)
{
        return this->id_usuario;
}

int usuario_getPopularidad(Usuario* this)
{
        return this->popularidad;
}

char* usuario_getNick(Usuario* this)
{
        return this->nick;
}

Usuario* usuario_findById_usuario(ArrayList* pArray,int id_usuario)
{

        int i;
        Usuario* aux;
        Usuario* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(id_usuario == usuario_getId_usuario(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Usuario* usuario_findByPopularidad(ArrayList* pArray,int popularidad)
{

        int i;
        Usuario* aux;
        Usuario* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(popularidad == usuario_getPopularidad(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Usuario* usuario_findByNick(ArrayList* pArray,char* nick)
{

        int i;
        Usuario* aux;
        Usuario* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(nick,usuario_getNick(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

void usuario_print(void* this)
{
    if(this != NULL)
    {
        printf("ID_USU: %d\tNICK: %s\tPOP: %d", usuario_getId_usuario(this),
                                                usuario_getNick(this),
                                                usuario_getPopularidad(this));
    }
}


