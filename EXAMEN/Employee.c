#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"


Employee* employee_new(char* name, char* lastName, int id, int age, int type)
{
    Employee* newEmployee = malloc(sizeof(Employee));
    emp_setName(newEmployee, name);
    emp_setLastName(newEmployee, lastName);
    emp_setId(newEmployee, id);
    emp_setAge(newEmployee, age);
    emp_setType(newEmployee, type);

    return newEmployee;
}

void employee_delete(Employee* this)
{
    free(this);
}

void employee_print(Employee* this)
{
    printf("%d, %s, %s, %d, %d\n", emp_getId(this), emp_getName(this),emp_getLastName(this), emp_getAge(this), emp_getType(this));
}

int employee_filterEmployee(void* this)
{
    int retorno = 0;
    int age = emp_getAge(this);
    int type = emp_getType(this);
    if(age > 30 && type == 4)
    {
        retorno = 1;
    }
    return retorno;
}

/**************** SETTERS ****************/

int emp_setName(Employee* this,char* name)
{
    strcpy(this->name,name);
    return 0;
}

int emp_setLastName(Employee* this,char* lastName)
{
    strcpy(this->lastName,lastName);
    return 0;
}

int emp_setId(Employee* this,int id)
{

    this->id = id;
    return 0;
}

int emp_setAge(Employee* this,int age)
{

    this->age = age;
    return 0;
}

int emp_setType(Employee* this,int type)
{

    this->type = type;
    return 0;
}

/**************** GETTERS ****************/

char* emp_getName(Employee* this)
{
    return this->name;
}

char* emp_getLastName(Employee* this)
{
    return this->lastName;
}

int emp_getId(Employee* this)
{
    return this->id;
}

int emp_getAge(Employee* this)
{
    return this->age;
}

int emp_getType(Employee* this)
{
    return this->type;
}
