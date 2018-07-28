#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
static ArrayList* lista_2;

int f_init()
{
    lista_0 = al_newArrayList();
    lista_1 = al_newArrayList();
    lista_2 = al_newArrayList();
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
     char b_1[65], b_2[65], b_3[65];

     if(!val_getString(b_1, "\nIngrese localidad: ","Error!\n",2,65) &&
        !val_getString(b_2, "\nIngrese localidad: ","Error!\n",2,65) &&
        !val_getString(b_3, "\nIngrese localidad: ","Error!\n",2,65))
     {

        f_opcion_4(b_1,b_2,b_3);
     }

}

static void opcion_5()
{
     f_opcion_5();
}

int f_opcion_1()
{
    p_leer(lista_0);
    return 0;
}

int f_opcion_2()
{
    al_map(lista_0,entrega_print);
    return 0;
}

int f_opcion_3()
{
    Entrega* auxiliar;
    int i;
    char localidad[65];
    for(i=0;i<al_len(lista_0);i++)
    {
        auxiliar=al_get(lista_0,i);
        strncpy(localidad,entrega_getLocalidad(auxiliar),65);
        if(entrega_findByLocalidad(lista_1,localidad)==NULL)
        {
            al_add(lista_1,auxiliar);
        }
    }
    al_sort(lista_1,entrega_compareByLocalidad,1);
    al_map(lista_1,entrega_printLocalidad);
    return 0;
}

int f_opcion_4(char* b_1, char* b_2, char* b_3)
{
    Entrega*auxiliar;
    int i;

    for(i=0;i<al_len(lista_0);i++)
    {
        auxiliar = al_get(lista_0,i);
        if( strcmp(b_1,entrega_getLocalidad(auxiliar))==0 ||
            strcmp(b_2,entrega_getLocalidad(auxiliar))==0 ||
            strcmp(b_3,entrega_getLocalidad(auxiliar))==0)
            {
                al_add(lista_2,auxiliar);
            }
    }
    al_sort(lista_2,entrega_compareByLocalidad,1);
    p_guardar(lista_2);
    return 0;
}

int f_opcion_5()
{
    return 0;
}

