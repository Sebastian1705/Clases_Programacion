#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Vista.h"
#include "Cliente.h"

static ArrayList* nominaCliente;
static int proximoIdCliente=0;
static int getNewIdCliente();
static int setNewIdCliente(int id);

void cont_init()
{
    nominaCliente = al_newArrayList();
    setNewIdCliente(dm_readAllCliente(nominaCliente) + 1);
    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_altaCliente (char* nombre,char* apellido,char* dni)
{
    Cliente* auxCliente;

    auxCliente = cliente_new(nombre,apellido,dni,getNewIdCliente(),CLIENTE_ALTA);
    al_add(nominaCliente, auxCliente);
    dm_saveAllCliente(nominaCliente);
    return 0;
}

int cont_bajaCliente (int id)
{
    Cliente* auxCliente;
    auxCliente = cliente_findById(nominaCliente,id);

    if(auxCliente != NULL)
    {
        //cliente_delete(auxCliente);
        cliente_setEstado(auxCliente,CLIENTE_BAJA);
        dm_saveAllCliente(nominaCliente);
    }
    return 0;
}


int cont_modificarCliente(int id,char* nombre,char* apellido,char* dni)
{
    Cliente* auxCliente;
    auxCliente = cliente_findById(nominaCliente, id);

    if(auxCliente != NULL)
    {
        cliente_setNombre(auxCliente,nombre);
        cliente_setApellido(auxCliente,apellido);
        cliente_setDni(auxCliente,dni);
        dm_saveAllCliente(nominaCliente);
    }
    return 0;
}

int cont_listarCliente ()
{
    vista_mostrarCliente(nominaCliente);
    return 0;
}

int cont_ordenarCliente ()
{

    return 0;
}

static int getNewIdCliente()
{
    return proximoIdCliente++;
}

static int setNewIdCliente(int id)
{
    proximoIdCliente = id;
    return 0;
}

int cont_existeCliente(int id)
{
    int retorno = -1;
    Cliente* auxCliente = cliente_findById(nominaCliente,id);

    if (auxCliente != NULL && cliente_getEstado(auxCliente) == CLIENTE_ALTA)
    {
        retorno = 0;
    }
    return retorno;
}
