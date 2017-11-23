#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Empleado.h"

int main()
{
    ArrayList* nominaEmpleados = NULL;
    nominaEmpleados = al_newArrayList();

    FILE *pFile;
    Empleado* auxEmpleado;
    int i;
    char nombre[50];
    char id[50];
    char salario[50];

    pFile = fopen("data.csv","rb");

    fscanf(pFile,"%[^;];%[^;];%[^\n]\n",id,nombre,salario);

    while(!feof(pFile))
    {
        fscanf(pFile,"%[^;];%[^;];%[^\n]\n",id,nombre,salario);

        auxEmpleado = emp_new(nombre,atoi(id), 1,atof(salario));

        al_add(nominaEmpleados, auxEmpleado);

    }


    for(i=0; i<al_len(nominaEmpleados);i++)
    {
        auxEmpleado = al_get(nominaEmpleados,i);
        printf("%d, %s, %.2f\n", emp_getId(auxEmpleado), emp_getNombre(auxEmpleado), emp_getSalario(auxEmpleado));
    }
    return 0;

}
