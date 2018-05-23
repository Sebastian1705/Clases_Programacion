#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


int main()
{
    //char arrayNombres[CANTIDAD_ELEMENTOS][CANTIDAD_CARACTERES];
    int edad[CANTIDAD_ELEMENTOS];
    int i;

    for(i=0; i < CANTIDAD_ELEMENTOS;i++ )
        if(getEdad(&edad[i],"Edad? ") == -1)
        {
            printf("MALlllllllllllllll");
        }

    return 0;
}
