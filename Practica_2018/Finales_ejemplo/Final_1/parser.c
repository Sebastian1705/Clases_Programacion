#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "ArrayList.h"
#include "deposito.h"


int cargarDepositos(ArrayList* pArrayDepositos, char* archivoDep)
{
    FILE* pFile;
    if(pArrayDepositos!=NULL)
    {
        pFile=fopen(archivoDep,"r");
        int producto;
        char descripcion[50];
        int cantidad;
        EProducto* this;

        printf("%p",pFile);

        char primerLinea[100];
        fgetc(pFile);

        do
        {
                fscanf(pFile,"%d,%[^,],%d\n)",&producto,descripcion,&cantidad);
                this=deposito_newP()_newParametros(id,firstName,lastName,isEmpty);

                if(this!=NULL)
                {
                    al_add(pArrayListEmployee,this);
                }

        }while(!feof(pFile));
    }
    fclose(pFile);
    return 0;
}

int guardarDepositos(ArrayList* pArrayDepositos, char* archivoDep)
{
    int i;
    int retorno = -1;
    FILE* depositos = fopen(archivoDep, "w");
    if(depositos != NULL)
    {
        for(i=0; i<al_len(pArrayDepositos);i++)
        {
            fprintf(depositos,"%d,%[^,],%d\n",proal_get(pArrayDepositos,i));
        }
        fclose(depositos);
        retorno = 0;
    }
    return retorno;
}

