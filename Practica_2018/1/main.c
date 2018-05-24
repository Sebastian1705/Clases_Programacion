#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"

void mostrar(Cliente* array[],int cantidad);
void cargar(Cliente* array[],int cantidad);

int main()
{
    Cliente* arrayPunteroClientes[50];
    cargar(arrayPunteroClientes,50);


    mostrar(arrayPunteroClientes,50);
    return 0;
}

void cargar(Cliente** array,int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {

    }
}

void mostrar(Cliente* array[],int cantidad)
{

}


