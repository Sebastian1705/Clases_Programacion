#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Entidad_1.h"

Mensaje* mensaje_new(int id_mensaje,int id_usuario,int popularidad,char* mensaje
)
{
        Mensaje* this = malloc(sizeof(Mensaje));

        if(this != NULL)
        {

                mensaje_setId_mensaje(this,id_mensaje);
                mensaje_setId_usuario(this,id_usuario);
                mensaje_setPopularidad(this,popularidad);
                mensaje_setMensaje(this,mensaje);
        }
        return this;
}

void mensaje_delete(Mensaje* this)
{
        free(this);
}

int mensaje_setId_mensaje(Mensaje* this,int id_mensaje)
{
        this->id_mensaje = id_mensaje;
        return 0;
}

int mensaje_setId_usuario(Mensaje* this,int id_usuario)
{
        this->id_usuario = id_usuario;
        return 0;
}

int mensaje_setPopularidad(Mensaje* this,int popularidad)
{
        this->popularidad = popularidad;
        return 0;
}

int mensaje_setMensaje(Mensaje* this,char* mensaje)
{
        strcpy(this->mensaje,mensaje);
        return 0;
}

int mensaje_getId_mensaje(Mensaje* this)
{
        return this->id_mensaje;
}

int mensaje_getId_usuario(Mensaje* this)
{
        return this->id_usuario;
}

int mensaje_getPopularidad(Mensaje* this)
{
        return this->popularidad;
}

char* mensaje_getMensaje(Mensaje* this)
{
        return this->mensaje;
}

Mensaje* mensaje_findById_mensaje(ArrayList* pArray,int id_mensaje)
{

        int i;
        Mensaje* aux;
        Mensaje* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(id_mensaje == mensaje_getId_mensaje(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Mensaje* mensaje_findById_usuario(ArrayList* pArray,int id_usuario)
{

        int i;
        Mensaje* aux;
        Mensaje* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(id_usuario == mensaje_getId_usuario(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Mensaje* mensaje_findByPopularidad(ArrayList* pArray,int popularidad)
{

        int i;
        Mensaje* aux;
        Mensaje* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(popularidad == mensaje_getPopularidad(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Mensaje* mensaje_findByMensaje(ArrayList* pArray,char* mensaje)
{

        int i;
        Mensaje* aux;
        Mensaje* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(mensaje,mensaje_getMensaje(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

void mensaje_print(void* this)
{
    if(this != NULL)
    {
        printf("ID_MSG: %d\tID_USU: %d\tPOP: %d\tMSG: %s\n\n",  mensaje_getId_mensaje(this),
                                    mensaje_getId_usuario(this),
                                    mensaje_getPopularidad(this),
                                    mensaje_getMensaje(this));
    }
}

int mensaje_compareByPop(void* pA ,void* pB)
{

	int retorno = 0;

	if(mensaje_getPopularidad(pA) > mensaje_getPopularidad(pB))
		retorno = 1;
	else if(mensaje_getPopularidad(pA) < mensaje_getPopularidad(pB))
		retorno = -1;

	return retorno;
}
