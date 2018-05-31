#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"

static int isValidName(char* name);
static int isValidLastName(char* lastName);
static int isValidIsEmpty(int isEmpty);

Employee* employee_new(void)
{

    Employee* returnAux = (Employee*) malloc(sizeof(Employee));
    return returnAux;

}

Employee* employee_newParametros(char* strId,char* name, char* lastName, char* strIsEmpty)
{
    int id;
    int isEmpty=0;
    Employee* this;

    id = atoi(strId); //FALTA VALIDAR
    if(!strcmp(strIsEmpty,"true")) //FALTA VALIDAR
        isEmpty = 1;
    this = employee_new();
    if( !employee_setId(this,id) &&
        !employee_setName(this,name) &&
        !employee_setLastName(this,lastName) &&
        !employee_setIsEmpty(this,isEmpty)
       )
    {
        return this;
    }
    employee_delete(this);
    return NULL;
}


void employee_delete(Employee* this)
{
    if(this != NULL)
        free(this);
}

int employee_setId(Employee* this, int id)
{
    static int ultimoId = -1;
    int retorno = -1;
    if(this != NULL && id == -1)
    {
        retorno = 0;
        ultimoId++;
        this->id = ultimoId;
    }
    else if(this != NULL && id > ultimoId)
    {
        retorno = 0;
        ultimoId = id;
        this->id = ultimoId;
    }
    return retorno;
}

int employee_getId(Employee* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this->id;
    }
    return retorno;
}

int employee_getIsEmpty(Employee* this, int* isEmpty)
{
    int retorno = -1;
    if(this != NULL && isEmpty != NULL)
    {
        retorno = 0;
        *isEmpty = this->isEmpty;
    }
    return retorno;
}

int employee_setIsEmpty(Employee* this, int isEmpty)
{
    int retorno = -1;
    if(this != NULL && isValidIsEmpty(isEmpty))
    {
        retorno = 0;
        this->isEmpty = isEmpty ;
    }
    return retorno;
}

int employee_setName(Employee* this, char* name)
{
    int retorno = -1;
    if(this != NULL && name != NULL && isValidName(name))
    {
        retorno = 0;
        strcpy(this->name,name);
    }
    return retorno;
}

int employee_getName(Employee* this, char* name)
{
    int retorno = -1;
    if(this != NULL && name != NULL)
    {
        retorno = 0;
        strcpy(name,this->name);
    }
    return retorno;
}

int employee_setLastName(Employee* this, char* lastName)
{
    int retorno = -1;
    if(this != NULL && lastName != NULL && isValidLastName(lastName))
    {
        retorno = 0;
        strcpy(this->lastName,lastName);
    }
    return retorno;
}

int employee_getLastName(Employee* this, char* lastName)
{
    int retorno = -1;
    if(this != NULL && lastName != NULL)
    {
        retorno = 0;
        strcpy(lastName,this->lastName);
    }
    return retorno;
}



static int isValidName(char* name)
{
    return 1;
}

static int isValidLastName(char* lastName)
{
    return 1;
}

static int isValidIsEmpty(int isEmpty)
{
    return 1;
}
int employee_compareName(Employee* pEmployeeA,Employee* pEmployeeB)
{
    char nameEmployeeA[51];
    char nameEmployeeB[51];
    int retorno = 0;
    if(pEmployeeA!=NULL && pEmployeeB != NULL)
    {
        employee_getName(pEmployeeA,nameEmployeeA);
        employee_getName(pEmployeeB,nameEmployeeB);
        retorno = strcmp(nameEmployeeA,nameEmployeeB);
    }
    return retorno ;
}

int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    int idEmployeeA;
    int idEmployeeB;
    int retorno = 0;
    if(pEmployeeA!=NULL && pEmployeeB != NULL)
    {
        employee_getId(pEmployeeA,&idEmployeeA);
        employee_getId(pEmployeeB,&idEmployeeB);
        if(idEmployeeA > idEmployeeB)
        {
            retorno = 1;
        }
        else if(idEmployeeA < idEmployeeB)
        {
            retorno = -1;
        }

    }
    return retorno;

}


void employee_print(Employee* this)
{
    int id;
    char name[51];
    char lastName[51];
    int isEmpty;
    if(this != NULL)
    {
        employee_getId(this,&id);
        employee_getName(this,name);
        employee_getLastName(this,lastName);
        employee_getIsEmpty(this,&isEmpty);
        fprintf(stdout,"\nId: %d - Nombre: %s - Apellido: %s - IsEmpty: %d", id,name,lastName,isEmpty);
    }

}


void employee_print2(Employee* this)
{
    int id;
    char name[51];
    char lastName[51];
    int isEmpty;
    char auxisEmpty[51];
    if(this != NULL)
    {
        employee_getId(this,&id);
        employee_getName(this,name);
        employee_getLastName(this,lastName);
        employee_getIsEmpty(this,&isEmpty);
        if(isEmpty==0)
        {
            strcpy(auxisEmpty,"true");
        }
        else
        {
            strcpy(auxisEmpty,"false");
        }
        fprintf(stdout,"%d,%s,%s,%s\n", id,name,lastName,auxisEmpty);
    }

}
