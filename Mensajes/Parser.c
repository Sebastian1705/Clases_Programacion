#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Validaciones.h"
#include "Funciones.h"
#include "Parser.h"
#include "Entidad_1.h"
#include "Entidad_2.h"

/*
int p_guardar(ArrayList* lista, char* archivo)
{
    int i;
    int retorno=-1;

    FILE* pFile=fopen(archivo,"w");
    Entidad* auxiliar=NULL;

    if(pFile!=NULL)
    {
        fprintf(pFile,"b_1,b_2,b_3,b_4,b_5\n");
        for(i=0; i<al_len(lista); i++)
        {
            auxiliar=al_get(lista,i);
            fprintf(pFile, "%s,%s,%s,%s,%s\n",entidad_get()) //get de cada item
            retorno=0;
        }
    }
    fclose(pFile);
    return retorno;
}
*/
/*
int p_leer(ArrayList* lista, char* archivo)
{
    int retorno = -1;
    char b_1[4096];
    char b_2[4096];
    char b_3[4096];
    char b_4[4096];
    char b_5[4096];

    FILE* pFile = fopen(archivo, "r");

    Entidad* auxiliar;

    if(pFile != NULL)
    {
        retorno = 0;
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,]%[^\n]\n",b_1,b_2,b_3,b_4,b_5)==5)
        {
            do
            {
                if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,]%[^\n]\n",b_1,b_2,b_3,b_4,b_5)==5)
                {
                    if( !val_validarUnsignedInt(b_1) && !val_validarString(b_2) && !val_validarString(b_3)&&
                        !val_validarString(b_4) && !val_validarString(b_5))
                    {
                        auxiliar = entidad_new()); //cargar parametros de entidad
                        al_add(lista,auxiliar);
                    }
                }
            }
            while(!feof(pFile));
        }
    }
    return retorno;
}
*/

int p_leerMensajes(ArrayList* lista, char* archivo)
{
    int retorno = -1;
    char b_1[4096];
    char b_2[4096];
    char b_3[4096];
    char b_4[4096];

    FILE* pFile = fopen(archivo, "r");

    Mensaje* auxiliar;

    if(pFile != NULL)
    {
        retorno = 0;
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",b_1,b_2,b_3,b_4)==4)
        {
            do
            {
                if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",b_1,b_2,b_3,b_4)==4)
                {
                    if( !val_validarUnsignedInt(b_1) &&
                        !val_validarUnsignedInt(b_2) &&
                        !val_validarUnsignedInt(b_3) &&
                        !val_validarEmail(b_4));
                    {
                        auxiliar = mensaje_new(atoi(b_1),atoi(b_2),atoi(b_3),b_4);
                        al_add(lista,auxiliar);
                    }
                }
            }
            while(!feof(pFile));
        }
    }
    return retorno;
}

int p_leerUsuarios(ArrayList* lista, char* archivo)
{
    int retorno = -1;
    char b_1[4096];
    char b_2[4096];
    char b_3[4096];

    FILE* pFile = fopen(archivo, "r");

    Usuario* auxiliar;

    if(pFile != NULL)
    {
        retorno = 0;
        if(fscanf(pFile,"%[^,],%[^,],%[^\n]\n",b_1,b_2,b_3)==3)
        {
            do
            {
                if(fscanf(pFile,"%[^,],%[^,],%[^\n]\n",b_1,b_2,b_3)==3)
                {
                    if( !val_validarUnsignedInt(b_1) &&
                        !val_validarString(b_2) &&
                        !val_validarUnsignedInt(b_3))
                    {
                        auxiliar = usuario_new(atoi(b_1),atoi(b_3),b_2);
                        al_add(lista,auxiliar);
                    }
                }
            }
            while(!feof(pFile));
        }
    }
    return retorno;
}

int p_guardarFeeds(ArrayList* lista_mensajes, ArrayList* lista_usuarios, char* archivo)
{
    int i, id_mensaje, id_usuario, pop_usuario, pop_msg;
    char nick[40], msg[4096];
    int retorno=-1;

    FILE* pFile=fopen(archivo,"w");
    Mensaje* auxMsg=NULL;
    Usuario* auxUsu=NULL;

    if(pFile!=NULL)
    {

        al_sort(lista_mensajes, mensaje_compareByPop,1);
        fprintf(pFile,"ID_MENSAJE,MENSAJE,POP_MSG,ID_USUARIO,NICK,POP_USUARIO\n\n");
        for(i=0; i<al_len(lista_mensajes); i++)
        {
            auxMsg=al_get(lista_mensajes,i);
            id_mensaje = mensaje_getId_mensaje(auxMsg);
            id_usuario = mensaje_getId_usuario(auxMsg);
            strncpy(msg, mensaje_getMensaje(auxMsg),4096);
            pop_msg = mensaje_getPopularidad(auxMsg);
            auxUsu = usuario_findById_usuario(lista_usuarios, id_usuario);
            strncpy(nick, usuario_getNick(auxUsu),40);
            pop_usuario = usuario_getPopularidad(auxUsu);

            fprintf(pFile, "%d,%s,%d,%d,%s,%d\n\n", id_mensaje,
                                                    msg,
                                                    pop_msg,
                                                    id_usuario,
                                                    nick,
                                                    pop_usuario);
            retorno=0;
        }
    }
    fclose(pFile);
    return retorno;
}
