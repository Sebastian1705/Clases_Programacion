#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"
#include "ArrayList.h"

int main()
{
    //Empleado *pEmpleado[50];
    void *pGenerico[50];
    int i;

    for(i=0; i<50; i++)
    {
        //pEmpleado[i] = empleado_newConstructor("Juan", "Perez",i);
        pGenerico[i] = empleado_newConstructor("Juan", "Perez",i);
    }

    //empleado_debugShow(pEmpleado[33]);
    //empleado_debugShow(pEmpleado[42]);

    empleado_debugShow(pGenerico[33]);
    empleado_debugShow(pGenerico [42]);

/*************************************/

    ArrayList* listaEmpleados;
    listaEmpleados = arrayList_new();



    return 0;
}
