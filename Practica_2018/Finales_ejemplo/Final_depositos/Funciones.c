#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "Depositos.h"
#include "ArrayList.h"
#include "Parser.h"

static void opcion_cargarDeposito();
static void opcion_listarProductos();
static void opcion_moverProductos();
static void opcion_descontarProductos();
static void opcion_agregarProductos();

static ArrayList* lista_0;
static ArrayList* lista_1;


void f_init()
{
    lista_0 = al_newArrayList();
    lista_1 = al_newArrayList();
    p_leerDeposito_0(lista_0);
    p_leerDeposito_1(lista_1);
    f_mostrarMenu();
}

int f_mostrarMenu()
{
    char buffer[10];
    int option=0;

    while(option != 6)
    {
        val_getUnsignedInt(buffer, MENU, MENU_ERROR,2,5);
        option = atoi(buffer);

        switch(option)
        {
        case 1:
            opcion_cargarDeposito();
            break;
        case 2:
            opcion_listarProductos();
            break;
        case 3:
            opcion_moverProductos();
            break;
        case 4:
            opcion_descontarProductos();
            break;
        case 5:
            opcion_agregarProductos();
            break;
        }
    }
    return 0;
}

static void opcion_cargarDeposito()
{
    char producto[50];
    char descripcion[4096];
    char cantidad[50];
    char deposito[50];

    if( !val_getUnsignedInt(producto, "\nIngrese el producto: ", "Error\n",2,50)&&
        !val_getString(descripcion, "Ingrese la descripcion: ", "Error\n",2,50)&&
        !val_getUnsignedInt(cantidad, "Ingrese la cantidad: ", "Error\n",2,50)&&
        !val_getUnsignedInt(deposito, "Ingrese deposito(0 - 1): ","Error\n",2,50))
    {
        if(atoi(deposito) == 0)
        {
            f_altaDeposito_0(atoi(producto),descripcion,atoi(cantidad));
        }
        else if(atoi(deposito) == 1)
        {
            f_altaDeposito_1(atoi(producto),descripcion,atoi(cantidad));
        }
        else
        {
            printf("\nDeposito incorrecto!\n");
        }
    }
}

static void opcion_listarProductos()
{
    char opcion[50];
    if(!val_getUnsignedInt(opcion,"Deposito a listar (0 - 1): ","\nDeposito incorrecto\n",2,50))
    {
        if(atoi(opcion) == 0)
        {
            f_imprimirLista_0();
        }
        else if(atoi(opcion) == 1)
        {
            f_imprimirLista_1();
        }
        else
        {
            printf("\nOpcion incorrecta\n");
        }
    }
}

static void opcion_moverProductos()
{
    char origen[50], destino[50], producto[50];

    if( !val_getUnsignedInt(origen,"\nIngrese el deposito de origen (0 - 1): ","\nError!\n",2,50) &&
        !val_getUnsignedInt(destino,"\nIngrese el deposito destino(0 - 1): ","\nError\n",2,50))
    {
        if(atoi(origen) == atoi(destino))
        {
            printf("\nDeposito origen igual que destino\n");
        }
        else if(!val_getUnsignedInt(producto,"\nIngrese producto a mover: ","\nError/n",2,50))
        {
            f_modificarDeposito(atoi(origen),atoi(destino),atoi(producto));
            p_guardarDeposito_0(lista_0);
            p_guardarDeposito_1(lista_1);
        }
    }

}

static void opcion_descontarProductos()
{
    char producto[50], cantidad[50];
    if( !val_getUnsignedInt(producto,"\nIngrese el codigo de producto: ","Error\n",2,50) &&
        !val_getUnsignedInt(cantidad,"Cantidad a restar: ","Error\n",2,50));
    {
        if(!f_existeDeposito(atoi(producto),lista_0))
        {
            f_descontarProducto(atoi(producto),atoi(cantidad),lista_0);
            p_guardarDeposito_0(lista_0);
        }
        else if(!f_existeDeposito(atoi(producto),lista_1))
        {
            f_descontarProducto(atoi(producto),atoi(cantidad),lista_1);
            p_guardarDeposito_1(lista_1);
        }
        else
        {
            printf("\nEl producto no existe!\n");
        }
    }
}

static void opcion_agregarProductos()
{
    char producto[50], cantidad[50];
    if( !val_getUnsignedInt(producto,"\nIngrese el codigo de producto: ","Error\n",2,50) &&
        !val_getUnsignedInt(cantidad,"Cantidad a restar: ","Error\n",2,50));
    {
        if(!f_existeDeposito(atoi(producto),lista_0))
        {
            f_agregarProducto(atoi(producto),atoi(cantidad),lista_0);
        }
        else if(!f_existeDeposito(atoi(producto),lista_1))
        {
            f_agregarProducto(atoi(producto),atoi(cantidad),lista_1);
        }
        else
        {
            printf("\nEl producto no existe!\n");
        }
    }
}

int f_altaDeposito_1(int producto, char* descripcion, int cantidad)
{
    Depositos* aux;
    aux = depositos_new(producto, descripcion, cantidad);
    al_add(lista_1,aux);
    p_guardarDeposito_1(lista_1);
    return 0;
}

int f_altaDeposito_0(int producto, char* descripcion, int cantidad)
{
    Depositos* aux;
    aux = depositos_new(producto, descripcion, cantidad);
    al_add(lista_0,aux);
    p_guardarDeposito_0(lista_0);
    return 0;
}

int f_imprimirLista_0()
{
    al_map(lista_0,depositos_imprimir);
    return 0;
}

int f_imprimirLista_1()
{
    al_map(lista_1,depositos_imprimir);
    return 0;
}

int f_modificarDeposito(int origen, int destino, int producto)
{
    Depositos* auxiliar;
    int i=0, bProducto, bCantidad;
    char bDescripcion[4096];
    int retorno = -1;
    if(!f_existeDeposito(producto, lista_0))
    {
        for(i=0;i<al_len(lista_0);i++)
        {
            auxiliar = al_get(lista_0,i);
            if(depositos_getProducto(auxiliar) == producto)
            {
                bProducto = depositos_getProducto(auxiliar);
                bCantidad = depositos_getCantidad(auxiliar);
                strncpy(bDescripcion,depositos_getDescripcion(auxiliar),4096);
                f_altaDeposito_1(bProducto,bDescripcion,bCantidad);
                f_borrarDeposito(bProducto, lista_0);
                retorno = 0;
            }
        }
    }
    else if(!f_existeDeposito(producto, lista_1))
    {
        for(i=0;i<al_len(lista_1);i++)
        {
            auxiliar = al_get(lista_1,i);
            if(depositos_getProducto(auxiliar) == producto)
            {
                bProducto = depositos_getProducto(auxiliar);
                bCantidad = depositos_getCantidad(auxiliar);
                strncpy(bDescripcion,depositos_getDescripcion(auxiliar),4096);
                f_altaDeposito_0(bProducto,bDescripcion,bCantidad);
                f_borrarDeposito(bProducto, lista_1);
                retorno = 0;
            }
        }
    }
    return retorno;
}

int f_existeDeposito(int producto, ArrayList* lista)
{
    int retorno = -1;
    Depositos* auxiliar = depositos_findByProducto(lista,producto);

    if (auxiliar!= NULL)
    {
        retorno = 0;
    }
    return retorno;
}

int f_borrarDeposito(int producto, ArrayList* lista)
{
    Depositos* auxiliar;
    int i=0;
    for(i=0;i<al_len(lista);i++)
    {
        auxiliar = al_get(lista,i);
        if(depositos_getProducto(auxiliar)==producto)
        {
            al_remove(lista,i);
            break;
        }

    }
    return 0;
}

int f_descontarProducto(int producto,int cantidad,ArrayList* lista)
{
    Depositos* auxiliar;
    int retorno=-1, nuevoValor;

    auxiliar = depositos_findByProducto(lista,producto);
    if(auxiliar!=NULL && depositos_getCantidad(auxiliar)<cantidad)
    {
        nuevoValor=depositos_getCantidad(auxiliar)-cantidad;
        depositos_setCantidad(auxiliar,nuevoValor);
        retorno =0;
    }
    return retorno;
}

int f_agregarProducto(int producto,int cantidad,ArrayList* lista)
{
    return 0;
}
