/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
struct
{
    int id;
    char name[51];
    char lastName[51];
    int isEmpty;

}typedef Employee;


Employee* employee_new(void);
Employee* employee_newParametros(char* strId,char* name, char* lastName, char* strIsEmpty);
void employee_delete(Employee* this);
int employee_setId(Employee* this, int id);
int employee_getId(Employee* this, int* id);
int employee_getIsEmpty(Employee* this, int* isEmpty);
int employee_setIsEmpty(Employee* this, int isEmpty);
int employee_setName(Employee* this, char* name);
int employee_getName(Employee* this, char* name);
int employee_setLastName(Employee* this, char* lastName);
int employee_getLastName(Employee* this, char* lastName);
int employee_compare(void* pEmployeeA,void* pEmployeeB);
void employee_print(Employee* this);
int employee_compareName(Employee* pEmployeeA,Employee* pEmployeeB);
#endif // _EMPLOYEE_H



