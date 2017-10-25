#include <stdio.h>
#include <stdlib.h>

int tomaNumero(char mensaje[], float *x, float maximo, float minimo)
{
    float numeroAuxiliar;
    printf("%s",mensaje);
    scanf("%f",&numeroAuxiliar);
    if(numeroAuxiliar < maximo && numeroAuxiliar > minimo)
    {
        *x = numeroAuxiliar;
        return 0;
    }
    return  -1;
}
