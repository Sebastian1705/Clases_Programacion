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
        fprintf(archivo,"Id, Name, Last Name, Age, Type");
        for(i=0; i<al_len(list); i++)
        {
            employee = al_get(list,i);
            fprintf(archivo,"%d, %s, %s, %d, %d\n", emp_getId(list), emp_getName(list),emp_getLastName(list),emp_getAge(list), emp_getType(list));
            retorno=0;
        }
    }
    fclose(archivo);
    return retorno;
}
