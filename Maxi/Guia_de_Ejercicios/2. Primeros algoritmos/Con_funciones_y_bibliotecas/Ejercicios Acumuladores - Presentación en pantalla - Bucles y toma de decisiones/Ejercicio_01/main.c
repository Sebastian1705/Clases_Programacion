/*****************************************
 * Ingresar 5 números y calcular su media.
 *****************************************/
#include <stdio.h>
#include <stdlib.h>

#define ITERACIONES 5

int calculaPromedio(char mensaje[], float* promedio);

int main()
{
    float promedio = 0;

    calculaPromedio("Ingrese un numero: ", &promedio);

    printf("El promedio de los numeros ingresados es: %.2f", promedio);

    return 0;
}

int calculaPromedio(char mensaje[], float* promedio)
{
    int retorno;
    int i = 0;
    float aux;
    float acumulador = 0;

    for(i=0; i<ITERACIONES; i++)
    {
        printf("%s", mensaje);
        scanf("%f", &aux);
        acumulador = aux + acumulador;
    }

    *promedio = acumulador / ITERACIONES;
    retorno = 0;

    return retorno;
}
