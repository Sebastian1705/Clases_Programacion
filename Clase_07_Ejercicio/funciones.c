#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int getEdad(int* pEdad, char* msg)
{
    char buffer[4096];
    int retorno = -1;
    printf(msg);
    fgets(buffer,4096,stdin);
    buffer[4094] = LF ;
    buffer[4095] = '\0';

    if(validarNumero(buffer) == 0)
    {
        *pEdad = atoi(buffer);
        retorno = 0;
    }
    return retorno;
}

int validarNumero(char* buffer)
{
    int retorno = 0,i=0;
    while(buffer[i]!= '\0')
    {
        printf("%d",buffer[i]);
        if((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != LF )
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}
