#include "ArrayList.h"
#include "Empleado.h"
#include <stdlib.h>
#include <stdio.h>
#include"Empleado.h"

int parser_parseEmpleados(char* fileName, ArrayList* listaEmpleados)
{
    char id[1048];
    char nombre[1048];
    char horasTrabajadas[1048];
    FILE* pFile;
    Empleado* auxiliarempleado;
    pFile=fopen(fileName, "r");

    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^\n]",id,nombre,horasTrabajadas);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^\n]",id,nombre,horasTrabajadas);
            auxiliarempleado = emp_newParametros(nombre, horasTrabajadas,id);
            al_add(listaEmpleados, auxiliarempleado);
        }
        fclose(pFile);
    }
    return 1; // OK
}

int generarArchivoSueldos(char* fileName,ArrayList* listaEmpleados)
{
    int i;
    FILE* pFile;
    pFile=fopen(fileName,"w");
    int id;
    int horasTrabajadas;
    int sueldo;
    char nombre[1048];
    Empleado* auxEmpleado;
    if(pFile != NULL && listaEmpleados != NULL)
    {
        fprintf(pFile,"%s,%s,%s,%s\n","ID","Nombre","HorasTrabajadas","Sueldo");
        fprintf(stdout,"%s,%s,%s,%s\n","ID","Nombre","HorasTrabajadas","Sueldo");

        for(i=0;i<(al_len(listaEmpleados));i++)
        {
            auxEmpleado=al_get(listaEmpleados,i);
            emp_getId(auxEmpleado,&id);
            emp_getHorasTrabajadas(auxEmpleado,&horasTrabajadas);
            emp_getNombre(auxEmpleado,nombre);
            emp_getSueldo(auxEmpleado,&sueldo);
            fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
            fprintf(stdout,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
        }
        return 1;
    }
    return -1;
}


