#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    ArrayList* listaEmpleados = al_newArrayList();
    Employee* auxiliarEmpleado;
    int i;



    FILE* pFile;
    pFile = fopen("data.csv","r");
    parserEmployee(pFile,listaEmpleados);


    auxiliarEmpleado = employee_newParametros("-1","Juan","Perez","true");
    al_add(listaEmpleados,auxiliarEmpleado);
    auxiliarEmpleado = employee_newParametros("-1","Lucas","Lopez","true");
    al_add(listaEmpleados,auxiliarEmpleado);

    //al_sort(listaEmpleados,employee_compareName,0);
    al_sort(listaEmpleados,employee_compare,0);
    for(i=0; i < al_len(listaEmpleados);i++)
    {
        //auxiliarEmpleado = al_get(listaEmpleados,i);
        //employee_print(auxiliarEmpleado);

        employee_print(al_get(listaEmpleados,i));
    }

    return 0;
}
