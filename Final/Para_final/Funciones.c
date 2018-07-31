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
static void opcion_6();
static void opcion_7();
static void opcion_8();
static void opcion_9();
static void opcion_10();

static ArrayList* lista_0;
static ArrayList* lista_1;
static ArrayList* lista_2;
static ArrayList* lista_3;

int f_init()
{
    lista_0 = al_newArrayList();
    lista_1 = al_newArrayList();
    lista_2 = al_newArrayList();
    lista_3 = al_newArrayList();

    f_mostrarMenu();

    return 0;
}



int f_mostrarMenu()
{
    char buffer[10];
    int option=11;

    while(option != 0)
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
             case 6:
            opcion_6();
            break;
        case 7:
            opcion_7();
            break;
        case 8:
            opcion_8();
            break;
        case 9:
            opcion_9();
            break;
        case 10:
            opcion_10();
            break;
        }
    }
    return 0;
}



static void opcion_1()
{
    f_opcion_1();
}

static void opcion_2()
{
    f_opcion_2();
}

static void opcion_3()
{
    f_opcion_3();
}

static void opcion_4()
{
    f_opcion_4();
}

static void opcion_5()
{
    f_opcion_5();
}

static void opcion_6()
{
    f_opcion_6();
}

static void opcion_7()
{
    f_opcion_7();
}

static void opcion_8()
{
    f_opcion_8();
}

static void opcion_9()
{
    f_opcion_9();
}

static void opcion_10()
{
    f_opcion_10();
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

int f_opcion_6()
{
    return 0;
}

int f_opcion_7()
{
    return 0;
}

int f_opcion_8()
{
    return 0;
}

int f_opcion_9()
{
    return 0;
}

int f_opcion_10()
{
    printf("\n1. %d\t2. %d\t3. %d\t4. %d\n\n",al_len(lista_0),
                                            al_len(lista_1),
                                            al_len(lista_2),
                                            al_len(lista_3));
    return 0;
}
