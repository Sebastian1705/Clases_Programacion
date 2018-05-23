#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "Validaciones.h"

int parserEmployee(FILE* pFile, ArrayList* this)
{
    int retorno = -1;
    if(pFile != NULL && this != NULL)
    {
        Employee* Employe;
        char name[50];
        char lastName[50];
        char id[50];
        char age[50];
        char type[50];

        pFile = fopen("data.csv","r");

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id, name, lastName, age, type);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id, name,lastName, age, type);
            if(val_validarUnsignedInt(id)==0 && val_validarUnsignedInt(type)==0 && val_validarUnsignedInt(age)==0)
            {
                if(val_validarString(name)==0 && val_validarString(lastName)==0)
                {
                    Employe = employee_new(name, lastName, atoi(id), atoi(age), atoi(type));
                    al_add(this, Employe);
                }
            }
        }
        fclose(pFile);
        retorno = 0;
    }
    return retorno;
}
