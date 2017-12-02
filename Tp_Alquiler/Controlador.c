#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Cliente.h"
#include "Vista.h"
#include "DataManager.h"

static ArrayList* nominaClientes;
static int proximoIdCliente=0;
static int getNewId();
static int setNewId(int id);

void cont_init()
{
    nominaClientes = al_newArrayList();
//    setNewId(dm_readAll(nominaClientes) + 1);
    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_altaCliente (char* nombre,char* apellido,char* dni)
{
    Cliente* auxCliente;
    auxCliente = cliente_new(getNewId(),nombre,apellido,dni,CLIENTE_ESTADO_ACTIVO);
    al_add(nominaClientes,auxCliente);
//    dm_saveAll(nominaClientes);
    return 0;
}
//
//int cont_bajaCliente (int id)
//{
//    Cliente* auxCliente;
//    auxCliente=soc_findById(nominaClientes,id);
//    if(auxCliente!=NULL)
//    {
//        soc_setEstado(auxCliente,Cliente_ESTADO_INACTIVO);
//        dm_saveAll(nominaClientes);
//    }
//
//    return 0;
//}
//
//
//int cont_modificarCliente (char* nombre,char* apellido,char* dni, int id, int estado)
//{
//    Cliente* auxCliente;
//
//    auxCliente=soc_findById(nominaClientes,id);
//
//    if(auxCliente!=NULL)
//    {
//        soc_setNombre(auxCliente,nombre);
//        soc_setApellido(auxCliente,apellido);
//        soc_setDni(auxCliente,dni);
//        soc_setEstado(auxCliente,estado);
//        dm_saveAll(nominaClientes);
//    }
//
//    return 0;
//}
//
int cont_listarClientes ()
{
    vista_mostrarClientes(nominaClientes);
    return 0;
}


static int getNewId()
{
    return proximoIdCliente++;
}

static int setNewId(int id)
{
    proximoIdCliente = id;
    return 0;
}
