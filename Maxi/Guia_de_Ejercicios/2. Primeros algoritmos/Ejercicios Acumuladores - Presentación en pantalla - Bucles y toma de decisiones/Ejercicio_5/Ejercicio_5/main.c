/***************************************************************************
 *	Escribir en C un programa que muestre los números impares entre 0 y 100
 *  y que imprima cuantos impares hay.
 ***************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int aux;
    int pares = 0;
    int impares = 0;
    int numero = 100;

    printf("Los numeros impares entre 0 y 100 son: \n");

    for(i=0; i<100; i++)
    {
        aux = numero % 2;

        if(aux == 0)
        {
            pares++;
        }
        else
        {
            impares++;
            printf("%d\n", i);
        }

        numero--;
    }

    printf("El numero 100 contiene: %d numeros impares\n", impares);

    return 0;
}
