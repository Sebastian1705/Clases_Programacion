#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Validaciones.h"
#include "Funciones.h"
#include "Parser.h"
#include "Entidad_1.h"

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

int p_leer(ArrayList* lista_0)
{
    int retorno = -1;
    char b_1[4096];
    char b_2[4096];
    char b_3[4096];
    char b_4[4096];
    char b_5[4096];

    FILE* pFile = fopen("data.txt", "r");

    Entrega* auxiliar;

    if(pFile != NULL)
    {
        retorno = 0;
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,]%[^\n]\n",b_1,b_2,b_3,b_4,b_5)==5)
        {
            do
            {
                if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,]%[^\n]\n",b_1,b_2,b_3,b_4,b_5)==5)
                {
                    if  (!val_validarUnsignedInt(b_1) &&
                         !val_validarString(b_2) &&
                         !val_validarAlfanumerico(b_3) &&
                         !val_validarString(b_4))
                  {
                        if(val_validarString(b_5) == -1)
                        strncpy(b_5, "vacio", 65);
                        auxiliar = entrega_new(atoi(b_1),b_2,b_3,b_4,b_5); //cargar parametros de entidad
                        al_add(lista_0,auxiliar);
                  }
                }
            }
            while(!feof(pFile));
        }
    }
    return retorno;
}

