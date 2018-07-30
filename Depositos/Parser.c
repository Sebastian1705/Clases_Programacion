#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Depositos.h"
#include "Funciones.h"
#include "Validaciones.h"
#include "Parser.h"

int p_guardarDeposito_1(ArrayList* lista)
{
    int i;
    int retorno=-1;

    FILE* pFile=fopen("Deposito_1.txt","w");
    Depositos* pDeposito=NULL;
    if(pFile!=NULL)
    {
        fprintf(pFile,"Producto,Descripcion,Cantidad\n");
        for(i=0; i<al_len(lista); i++)
        {
            pDeposito=al_get(lista,i);
            fprintf(pFile, "%d,%s,%d\n",depositos_getProducto(pDeposito),
                                        depositos_getDescripcion(pDeposito),
                                        depositos_getCantidad(pDeposito));
            retorno=0;
        }
    }
    fclose(pFile);
    return retorno;
}

int p_guardarDeposito_0(ArrayList* lista)
{
    int i;
    int retorno=-1;

    FILE* pFile=fopen("Deposito_0.txt","w");
    Depositos* pDeposito=NULL;
    if(pFile!=NULL)
    {
        fprintf(pFile,"Producto,Descripcion,Cantidad\n");
        for(i=0; i<al_len(lista); i++)
        {
            pDeposito=al_get(lista,i);
            fprintf(pFile, "%d,%s,%d\n",depositos_getProducto(pDeposito),
                                        depositos_getDescripcion(pDeposito),
                                        depositos_getCantidad(pDeposito));
            retorno=0;
        }
    }
    fclose(pFile);
    return retorno;
}

int p_leerDeposito_0(ArrayList* lista)
{
    int retorno = -1;
    char bProducto[4096];
    char bDescripcion[4096];
    char bCantidad[4096];

    FILE* pFile = fopen("Deposito_0.txt", "r");

    Depositos* auxiliar;

    if(pFile != NULL)
    {
        retorno = 0;
        if(fscanf(pFile,"%[^,],%[^,]%[^\n]\n",bProducto,bDescripcion,bCantidad)==3)
        {
            do
            {
                if(fscanf(pFile,"%[^,],%[^,],%[^\n]\n",bProducto,bDescripcion,bCantidad)==3)
                {
                    if( !val_validarUnsignedInt(bProducto) && !val_validarString(bDescripcion) &&
                        !val_validarUnsignedInt(bCantidad))
                    {
                        auxiliar = depositos_new(atoi(bProducto),bDescripcion,atoi(bCantidad));
                        al_add(lista,auxiliar);
                    }
                }
            }
            while(!feof(pFile));
        }
    }
    return retorno;
}

int p_leerDeposito_1(ArrayList* lista)
{
    int retorno = -1;
    char bProducto[4096];
    char bDescripcion[4096];
    char bCantidad[4096];

    FILE* pFile = fopen("Deposito_1.txt", "r");

    Depositos* auxiliar;

    if(pFile != NULL)
    {
        retorno = 0;
        if(fscanf(pFile,"%[^,],%[^,]%[^\n]\n",bProducto,bDescripcion,bCantidad)==3)
        {
            do
            {
                if(fscanf(pFile,"%[^,],%[^,],%[^\n]\n",bProducto,bDescripcion,bCantidad)==3)
                {
                    if( !val_validarUnsignedInt(bProducto) && !val_validarString(bDescripcion) &&
                        !val_validarUnsignedInt(bCantidad))
                    {
                        auxiliar = depositos_new(atoi(bProducto),bDescripcion,atoi(bCantidad));
                        al_add(lista,auxiliar);
                    }
                }
            }
            while(!feof(pFile));
        }
    }
    return retorno;
}
