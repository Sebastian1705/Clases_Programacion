#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generador.h"
#include "utn.h"
#include "ArrayList.h"


int main()
{
    ArrayList* listaCampos;
    int menu;
    listaCampos=al_newArrayList();
    char estructura[25];
    char nombreArchivo[50];
    do
    {
        menu=-1;
        getValidInt("1. Leer archivo .h. \n2. Ver estructura y campos.\n3. Generar archivos.\n4. Salir\n\n","Opcion no valida!\n",&menu,1,4,1);
        switch(menu)
        {
        case 1:
            if(parserHeader(listaCampos,estructura,nombreArchivo))
            {
                al_clear(listaCampos);
                printf("Error");
            }
            break;
        case 2:
            printf("El nombre de la estructura es %s \n",estructura);
            mostrarCampos(listaCampos);
            break;
        case 3:
            generarArchivos(estructura,nombreArchivo,listaCampos,nombreArchivo);
            break;
        case 4:
            printf("\nSaliendo!\n");
            break;
        }
    system("pause");
    system("cls");
    }while(menu!=4);
    return 0;
}


