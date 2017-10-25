#include "Lib.h"
#include <stdio.h>
#include <stdlib.h>

int obtenerDatos (int edad[], float salario[], int qtyMaxima)
{
    int i;
    float aux;

    for(i = 0; i < qtyMaxima ; i++)
    {
        printf("\nIngrese edad persona [%d]: ", i+1);
        scanf("%d", &edad[i]);

        printf("\nIngrese salario persona [%d]: ", i+1);
        scanf("%f", &aux);

        salario[i] = aux;

    }

    return 0;

}

int mostrarDatos(int edad[], float salario[], int qtyMaxima)
{
    int i;

    printf("\nEDAD\t\tSALARIO");
    for(i = 0; i < qtyMaxima; i++)
    {
        printf("\n%d\t\t%.2f\n", edad[i], salario[i]);
    }
    return 0;
}

int calcularPromedio(int edad[], int qtyMaxima, float* promedio)
{
    int i,retorno = -1,acumulador = 0;

    if(qtyMaxima > 0 && edad != NULL && promedio != NULL)
    {
        retorno = 0;
        for(i = 0; i < qtyMaxima; i++)
        {
            acumulador = acumulador  + edad[i];
        }
        *promedio = ((float)acumulador) / qtyMaxima;
    }
    return retorno;
}


int calcularIndiceMaximo(float salario[], int qtyMaxima)
{
    int i,retorno = -1,iMaximo;

    if(qtyMaxima > 0 && salario != NULL)
    {
        iMaximo = 0;
        for(i = 1; i < qtyMaxima; i++)
        {
            if(salario[i]>salario[iMaximo])
                iMaximo = i;
        }
        retorno = iMaximo;
    }
    return retorno;
}
