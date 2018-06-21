#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Empleado.h"
#include "Validaciones.h"

int parser_parseEmpleados(char* fileName, ArrayList* listaEmpleados)
{
    int retorno = -1;
    char bId[4096];
    char bName[4096];
    char bhoras[4096];
    FILE* pFile = fopen(fileName, "r");


    Empleado* auxiliarEmpleado;

    if(fileName != NULL)
    {
        retorno = 0;
        fscanf(pFile,"%[^,],%[^,],%[^\n]\n",bId,bName,bhoras);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^\n]\n",bId,bName,bhoras);
            if( !val_validarUnsignedInt(bId) && !val_validarString(bName)&&
                !val_validarInt(bhoras))
            {
                auxiliarEmpleado = empleado_new(atoi(bId),bName,atoi(bhoras),0);
                al_add(listaEmpleados,auxiliarEmpleado);
                retorno = 1;
            }
        }
    }

    return retorno;

}

