#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "DataManager.h"


int dm_dumpEmployeeList(ArrayList* list)
{
    int i;
    int retorno=-1;
    FILE* archivo = fopen("out.csv","wb");
    void* employee = NULL;
    if(archivo!=NULL)
    {
        fprintf(archivo,"Id, Name, Last Name, Age, Type\n");
        for(i=0; i<al_len(list); i++)
        {
            employee = al_get(list,i);
            fprintf(archivo,"%d, %s, %s, %d, %d\n", emp_getId(employee), emp_getName(employee),emp_getLastName(employee),emp_getAge(employee), emp_getType(employee));
            retorno=0;
        }
    }
    fclose(archivo);
    return retorno;
}
