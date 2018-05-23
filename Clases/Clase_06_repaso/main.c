#include <stdio.h>
#include <stdlib.h>
#include "Lib.h"
#define CANT_EMPLEADOS 5


int main()
{
    int edad[CANT_EMPLEADOS];
    float salario[CANT_EMPLEADOS],promedio;

    obtenerDatos (edad, salario, CANT_EMPLEADOS);
    mostrarDatos(edad, salario, CANT_EMPLEADOS);

    calcularPromedio(edad,CANT_EMPLEADOS,&promedio);
    printf("\nPROM: %.2f",promedio);

    //int aux;
    //aux = calcularMaximo(salario,CANT_EMPLEADOS);
    //printf("\nMAX: %d",aux);

    printf("\nMAX: %d",calcularIndiceMaximo(salario,CANT_EMPLEADOS));

    return 0;
}
