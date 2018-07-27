#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Validaciones.h"
#include "Entidad_1.h"
#include "Entidad_2.h"
#include "Funciones.h"
#include "Parser.h"

static void opcion_1();
static void opcion_2();
static void opcion_3();
static void opcion_4();
static void opcion_5();

static ArrayList* lista_0;
static ArrayList* lista_1;

int f_init()
{
    lista_0 = al_newArrayList();
    lista_1 = al_newArrayList();
    f_mostrarMenu();

    return 0;
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
            opcion_1();
            break;
        case 2:
            opcion_2();
            break;
        case 3:
            opcion_3();
            break;
        case 4:
            opcion_4();
            break;
        case 5:
            opcion_5();
            break;
        }
    }
    return 0;
}

static void opcion_1()
{

}

static void opcion_2()
{

}

static void opcion_3()
{

}

static void opcion_4()
{

}

static void opcion_5()
{

}

int f_opcion_1()
{
    return 0;
}

int f_opcion_2()
{
    return 0;
}

int f_opcion_3()
{
    return 0;
}

int f_opcion_4()
{
    return 0;
}

int f_opcion_5()
{
    return 0;
}

