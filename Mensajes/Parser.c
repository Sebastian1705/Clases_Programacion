#include <stdio.h>
#include <stdlib.h>
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
        if(fscanf(pFile,"%[^,],%[^,],%[^,]%[^\n]\n",b_1,b_2,b_3,b_4)==4)
        {
            do
            {
                if(fscanf(pFile,"%[^,],%[^,],%[^,]%[^\n]\n",b_1,b_2,b_3,b_4)==4)
                {
//                    if( !val_validarUnsignedInt(b_1) &&
//                        !val_validarUnsignedInt(b_2) &&
//                        !val_validarUnsignedInt(b_3) &&
//                        !val_validarEmail(b_4));
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
        if(fscanf(pFile,"%[^,],%[^,]%[^\n]\n",b_1,b_2,b_3)==3)
        {
            do
            {
                if(fscanf(pFile,"%[^,],%[^,]%[^\n]\n",b_1,b_2,b_3)==3)
                {
                    if( !val_validarUnsignedInt(b_1) &&
                        !val_validarString(b_2) &&
                        // !val_validarEmail(b_3))
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
