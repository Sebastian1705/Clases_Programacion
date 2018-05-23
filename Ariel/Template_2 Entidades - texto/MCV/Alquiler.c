#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Alquiler.h"

Alquiler* alquiler_new(int id,int idCliente,int equipo,int estado)
{
    Alquiler* this = malloc(sizeof(Alquiler));

    if(this != NULL)
    {

        alquiler_setId(this,id);
        alquiler_setIdCliente(this,idCliente);
        alquiler_setEquipo(this,equipo);
        alquiler_setEstado(this,estado);
    }
    return this;
}

void alquiler_delete(Alquiler* this)
{
    free(this);
}

int alquiler_setId(Alquiler* this,int id)
{
    this->id = id;
    return 0;
}

int alquiler_setIdCliente(Alquiler* this,int idCliente)
{
    this->idCliente = idCliente;
    return 0;
}

int alquiler_setEquipo(Alquiler* this,int equipo)
{
    this->equipo = equipo;
    return 0;
}

int alquiler_setEstado(Alquiler* this,int estado)
{
    this->estado = estado;
    return 0;
}

int alquiler_getId(Alquiler* this)
{
    return this->id;
}

int alquiler_getIdCliente(Alquiler* this)
{
    return this->idCliente;
}

int alquiler_getEquipo(Alquiler* this)
{
    return this->equipo;
}

int alquiler_getEstado(Alquiler* this)
{
    return this->estado;
}

Alquiler* alquiler_findById(ArrayList* pArray,int id)
{

    int i;
    Alquiler* aux;
    Alquiler* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(id == alquiler_getId(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Alquiler* alquiler_findByIdCliente(ArrayList* pArray,int idCliente)
{

    int i;
    Alquiler* aux;
    Alquiler* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(idCliente == alquiler_getIdCliente(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Alquiler* alquiler_findByEquipo(ArrayList* pArray,int equipo)
{

    int i;
    Alquiler* aux;
    Alquiler* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(equipo == alquiler_getEquipo(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Alquiler* alquiler_findByEstado(ArrayList* pArray,int estado)
{

    int i;
    Alquiler* aux;
    Alquiler* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(estado == alquiler_getEstado(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

int alquiler_compareById(void* pA ,void* pB)
{

	int retorno = 0;

	if(alquiler_getId(pA) > alquiler_getId(pB))
		retorno = 1;
	else if(alquiler_getId(pA) < alquiler_getId(pB))
		retorno = -1;

	return retorno;
}

int alquiler_compareByIdCliente(void* pA ,void* pB)
{

	int retorno = 0;

	if(alquiler_getIdCliente(pA) > alquiler_getIdCliente(pB))
		retorno = 1;
	else if(alquiler_getIdCliente(pA) < alquiler_getIdCliente(pB))
		retorno = -1;

	return retorno;
}

int alquiler_compareByIdEquipo(void* pA ,void* pB)
{

	int retorno = 0;

	if(alquiler_getEquipo(pA) > alquiler_getEquipo(pB))
		retorno = 1;
	else if(alquiler_getEquipo(pA) < alquiler_getEquipo(pB))
		retorno = -1;

	return retorno;
}

int alquiler_compareByEstado(void* pA ,void* pB)
{

	int retorno = 0;

	if(alquiler_getEstado(pA) > alquiler_getEstado(pB))
		retorno = 1;
	else if(alquiler_getEstado(pA) < alquiler_getEstado(pB))
		retorno = -1;

	return retorno;
}


/*******************************************************************/


void alquiler_imprimir(void* pAlquiler) //cambiar nombre entidad
{
    if(alquiler_getEstado(pAlquiler) == ALQUILER_ESTADO_ACTIVO)
        printf("ID: %d - ID CLIENTE: %d- EQUIPO: %d\n",alquiler_getId(pAlquiler),
                alquiler_getIdCliente(pAlquiler),alquiler_getEquipo(pAlquiler));
}








