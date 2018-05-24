#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "DataManager.h"
#include "Vista.h"

#include "Cliente.h"

////////////////////////////////////////
static ArrayList* listaX;
static int proximoIdX=0;
static int getNewIdX();
static int setNewIdX(int id);

static ArrayList* listaCliente;
static int proximoIdCliente=0;
static int getNewIdCliente();
static int setNewIdCliente(int id);


void cont_init()
{
    listaX = al_newArrayList();
    setNewIdX(dm_readAllX(listaX) + 1);

    listaCliente = al_newArrayList();
    setNewIdCliente(dm_readAllClientes(listaCliente) + 1);





    vista_mostrarMenu();
}



////////////////////////////////////////
// para cada entidad                  //
////////////////////////////////////////
static int getNewIdX()
{
    return proximoIdX++;
}
static int setNewIdX(int id)
{
    proximoIdX = id;
    return 0;
}

int cont_altaX (char* a,char* b,int c)
{
    return 0;
}
int cont_bajaX (int id)
{
    return 0;
}
int cont_modificarX (int id, char* a,char* b,int c)
{
    return 0;
}


int cont_listarX ()
{
    //vista_mostrarX(nominaX);
    return 0;
}
int cont_ordenarX ()
{
    return 0;
}
////////////////////////////////////////

////////////////////////////////////////
// ENTIDAD CLIENTE                    //
////////////////////////////////////////
static int getNewIdCliente()
{
    return proximoIdCliente++;
}
static int setNewIdCliente(int id)
{
    proximoIdCliente = id;
    return 0;
}

int cont_altaCliente (char* nombre,char* apellido,char* dni)
{
    Cliente* auxiliar;

    auxiliar = cliente_new (getNewIdCliente(), CLIENTE_ESTADO_ALTA, nombre, apellido, dni);

    al_add (listaCliente, auxiliar);
    dm_saveAllClientes (listaCliente);
    return 0;
}
int cont_bajaCliente (int id)
{
    return 0;
}
int cont_modificarCliente (int id, char* a,char* b,char* c)
{
    return 0;
}


int cont_listarCliente ()
{
    //vista_mostrarX(nominaX);
    return 0;
}
int cont_ordenarCliente ()
{
    return 0;
}
////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
