#include <stdio.h>
#include <stdlib.h>

void imprimirCadena(char cadena[])
{
    int i = 0;
    int flagEncontreFinal = 0;

    while(flagEncontreFinal == 0)
    {
        char c = cadena[i];
        if(c!=0)
        {
            //imprimir
            printf("%c",c);
        }
        else
        {
            flagEncontreFinal = 1;
        }
        i++;
    }
}





