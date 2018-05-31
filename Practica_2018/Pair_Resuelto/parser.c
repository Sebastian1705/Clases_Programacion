#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "Validaciones.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    int retorno = -1;
    char bId[4096];
    char bName[4096];
    char bLastName[4096];
    char bIsEmpty[4096];
    Employee* auxiliarEmpleado;

    if(pFile != NULL)
    {
        retorno = 0;
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bId,bName,bLastName,bIsEmpty);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bId,bName,bLastName,bIsEmpty);
            if( !val_validarUnsignedInt(bId) && !val_validarString(bName)&&
                !val_validarString(bLastName)&& !val_validarString(bIsEmpty))
            {
                auxiliarEmpleado = employee_newParametros(bId,bName,bLastName,bIsEmpty);
                al_add(pArrayListEmployee,auxiliarEmpleado);
            }

        }
    }

    return retorno;
}




