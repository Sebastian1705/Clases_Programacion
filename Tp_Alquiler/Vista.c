#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Cliente.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"

static int idiomaVista = VISTA_IDIOMA_ES;

//static void opcionAlta();
//static void opcionBaja();
//static void opcionModificacion();
static void opcionListado();


int vista_init (int idioma)
{
    idiomaVista = idioma;
    return 0;
}

int vista_mostrarMenu()
{
    char buffer[10];
    int option=0;

    while(option != 5)
    {
        val_getInt(buffer, MENU_PPAL_ES, MENU_PPAL_ERROR_ES,2,5);
        option = atoi(buffer);

        switch(option)
        {
            case 1:
                opcionListado();
                break;
            case 2:
//
                break;
            case 3:
//
                break;
            case 4:
//
                break;

        }
    }

    return 0;
}

void vista_mostrarClientes(ArrayList* pListaClientes)
{
    int i;
    Cliente* auxCliente;
    for(i=0;i<al_len(pListaClientes);i++)
        {
            auxCliente=al_get(pListaClientes,i);
            if(auxCliente->estado==CLIENTE_ESTADO_ACTIVO)
            {
            auxCliente = al_get(pListaClientes,i);
            printf("ID: %d - NOMBRE: %s - APELLIDO: %s - DNI: %s\n",cliente_getId(auxCliente),cliente_getNombre(auxCliente),
                            cliente_getApellido(auxCliente),cliente_getDni(auxCliente));
            }
        }
}

void mostrarError(char *);

static void opcionAlta()
{
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];
    val_getString(auxNombre, "Nombre? ", "Error",2,50);
    val_getString(auxApellido, "Apellido? ", "Error",2,50);
    val_getInt(auxDni, "DNI? ", "Error",2,50);
    cont_altaCliente(auxNombre,auxApellido,auxDni);

}

//static void opcionBaja()
//{
//    char auxId[10];
//    int id;
//
//    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
//    {
//        id = atoi(auxId);
//        cont_bajaCliente(id);
//    }
//
//}
//
//static void opcionModificacion()
//{
//    char auxId[10];
//    int id;
//    int estado;
//    char auxNombre[50];
//    char auxApellido[50];
//    char auxDni[50];
//    char auxEstado[5];
//
//    if((val_getUnsignedInt(auxId,"Id a modificar" , "Error",2,10)==0))
//    {
//        id = atoi(auxId);
//        if(val_getString(auxNombre, "Nombre? ", "Error",2,50)==0)
//        {
//            if(val_getString(auxApellido, "Apellido? ", "Error",2,50)==0)
//            {
//                if(val_getInt(auxDni, "DNI? ", "Error",2,50)==0)
//                {
//                    if(val_getUnsignedInt(auxEstado,"Estado?\nACTIVO= 0\nINACTIVO= 1", "Error",2,5)==0)
//                    {
//                        estado=atoi(auxEstado);
//                        if(estado == 0 || estado == 1)
//                        {
//                            cont_modificarCliente(auxNombre,auxApellido,auxDni,id,estado);
//                        }
//
//                    }
//
//                }
//            }
//
//        }
//
//    }
//
//}

static void opcionListado()
{
    cont_listarClientes();
}
