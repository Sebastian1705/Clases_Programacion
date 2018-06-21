#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Empleado.h"


void em_calcularSueldo(void* p)
{
    //Leer campos y escribir sueldo
    int horas, primerasHoras=180, de120a160=240, de160a240=350;
    if(p != NULL)
    {
       horas = empleado_getHorasTrabajadas(p);
       if(horas <= 120)
       {
            horas = horas * primerasHoras;
       }
       else if(horas > 120 && horas <= 160)
       {
            horas = horas * de120a160;
       }
       else
       {
            horas = horas * de160a240;
       }
    }
    empleado_setSueldo(p,horas);

}

Empleado* empleado_new(int id,char* nombre,int horasTrabajadas,int sueldo)
{
	Empleado* this = malloc(sizeof(Empleado));

	if(this != NULL)
	{

		empleado_setId(this,id);
		empleado_setNombre(this,nombre);
		empleado_setHorasTrabajadas(this,horasTrabajadas);
		empleado_setSueldo(this,sueldo);
	}
	return this;
}

void empleado_delete(Empleado* this)
{
	free(this);
}

int empleado_setId(Empleado* this,int id)
{
	this->id = id;
	return 0;
}

int empleado_setNombre(Empleado* this,char* nombre)
{
	strcpy(this->nombre,nombre);
	return 0;
}

int empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas)
{
	this->horasTrabajadas = horasTrabajadas;
	return 0;
}

int empleado_setSueldo(Empleado* this,int sueldo)
{
	this->sueldo = sueldo;
	return 0;
}

int empleado_getId(Empleado* this)
{
	return this->id;
}

char* empleado_getNombre(Empleado* this)
{
	return this->nombre;
}

int empleado_getHorasTrabajadas(Empleado* this)
{
	return this->horasTrabajadas;
}

int empleado_getSueldo(Empleado* this)
{
	return this->sueldo;
}

Empleado* empleado_findById(ArrayList* pArray,int id)
{

	int i;
	Empleado* aux;
	Empleado* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(id == empleado_getId(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Empleado* empleado_findByNombre(ArrayList* pArray,char* nombre)
{

	int i;
	Empleado* aux;
	Empleado* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(nombre,empleado_getNombre(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Empleado* empleado_findByHorasTrabajadas(ArrayList* pArray,int horasTrabajadas)
{

	int i;
	Empleado* aux;
	Empleado* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(horasTrabajadas == empleado_getHorasTrabajadas(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Empleado* empleado_findBySueldo(ArrayList* pArray,int sueldo)
{

	int i;
	Empleado* aux;
	Empleado* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(sueldo == empleado_getSueldo(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

int empleado_compareById(void* pA ,void* pB)
{

	int retorno = 0;

	if(empleado_getId(pA) > empleado_getId(pB))
		retorno = 1;
	else if(empleado_getId(pA) < empleado_getId(pB))
		retorno = -1;

	return retorno;
}

int empleado_compareByNombre(void* pA ,void* pB)
{

	int retorno;

	retorno = strcmp(empleado_getNombre(pA),empleado_getNombre(pB));

	return retorno;
}

int empleado_compareByHorasTrabajadas(void* pA ,void* pB)
{

	int retorno = 0;

	if(empleado_getHorasTrabajadas(pA) > empleado_getHorasTrabajadas(pB))
		retorno = 1;
	else if(empleado_getHorasTrabajadas(pA) < empleado_getHorasTrabajadas(pB))
		retorno = -1;

	return retorno;
}

int empleado_compareBySueldo(void* pA ,void* pB)
{

	int retorno = 0;

	if(empleado_getSueldo(pA) > empleado_getSueldo(pB))
		retorno = 1;
	else if(empleado_getSueldo(pA) < empleado_getSueldo(pB))
		retorno = -1;

	return retorno;
}

