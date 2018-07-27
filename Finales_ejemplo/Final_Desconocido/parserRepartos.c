#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "reparto.h"
#include "parserRepartos.h"


int parserRepartos(ArrayList* repartos, char* archivo)
{
    FILE *pFile;
    EReparto* auxReparto;
    int retorno=-1;

    char id[5];
    char producto[50];
    char direccion[200];
    char localidad[50];
    char recibe[20];
    int id2;
    pFile = fopen(archivo,"r");


    if(pFile!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,producto,direccion,localidad,recibe);
        do
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,producto,direccion,localidad,recibe) > 0)
            {
                id2=atoi(id);
                auxReparto=reparto_newParametros(id2, producto, direccion,localidad, recibe);
                al_add(repartos, auxReparto);

            }
        }
        while(!feof(pFile));
        fclose(pFile);
    }
    return retorno;
}
