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

}

static void opcion_descontarProductos()
{

}

static void opcion_agregarProductos()
{

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
