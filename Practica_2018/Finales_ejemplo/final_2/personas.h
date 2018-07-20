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
#ifndef __PERSONAS
#define __PERSONAS
struct
{
    int id;
    char name[51];
    char direccion[51];
    int horas;
    int sueldo;

}typedef eEmpleado;
#endif // __EMPLOYEE

void persona_printPersona(eEmpleado* p);
int persona_compareName(void* pEmployeeA,void* pEmployeeB);
int persona_compareDNI(void* pEmployeeA,void* pEmployeeB);
int persona_calcularSueldo(void* pEmployeeA);
