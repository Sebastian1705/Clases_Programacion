#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_NUMEROS_INGRESADOS 5
int main()
{
    float numeroIngresado;
    float minimoIngresado=0;
    float maximoIngresado=0;
    float acumuladorNumerosIngresados=0;
    int i=0;
    for(i=0;i<CANTIDAD_NUMEROS_INGRESADOS;i++)
    {
        printf("Ingrese un numero\n");
        scanf("%f",&numeroIngresado);
        acumuladorNumerosIngresados+=numeroIngresado;
        if(i==0)
        {
            minimoIngresado=numeroIngresado;
            maximoIngresado=numeroIngresado;
        }
        if(numeroIngresado<minimoIngresado)
        {
            minimoIngresado=numeroIngresado;
        }
        if(numeroIngresado>maximoIngresado)
        {
            maximoIngresado=numeroIngresado;
        }
    }
    printf("El maximo es %f",maximoIngresado);
    printf("\nEl minimo es %f",minimoIngresado);
    return 0;
}
