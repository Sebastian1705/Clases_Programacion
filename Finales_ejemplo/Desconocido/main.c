#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayList.h"
#include "parserRepartos.h"
#include "reparto.h"

int mostrarRepartos(ArrayList* listaRepartos, int limite);

int main()
{
    ArrayList* listaRepartos;
    listaRepartos=al_newArrayList();

    int menu;
    char nombreArchivo[50];
    do
    {
        menu=-1;
        getValidInt("1. Cargar archivo.\n2. Imprimir entregas.\n3. Imprimir localidades.\n4. Generar archivo de reparto\n5. Salir\n\n","Opcion no valida!\n",&menu,1,5,1);

        switch(menu)
        {
        case 1:
            printf("Ingrese el nombre del archivo a cargar\n");
            fgets(nombreArchivo,50,stdin);
            strcpy(nombreArchivo,"DATA_FINAL_V3.csv");

            parserRepartos(listaRepartos,nombreArchivo);
            break;
        case 2:
            mostrarRepartos(listaRepartos,al_len(listaRepartos));
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
            printf("\nSaliendo!\n");
            break;
        }
    system("pause");
    system("cls");
    }while(menu!=5);
    return 0;
}


int mostrarRepartos(ArrayList* listaRepartos, int limite)
{
    int i;
    int retorno=-1;

    if(listaRepartos != NULL)
    {
        retorno=0;

        int auxId;
        char auxProducto[50];
        char auxDireccion[200];
        char auxLocalidad[50];
        char auxRecibe[20];

        printf("Mostrando repartos\n------------------------------\n");
        printf("Id\tProducto\tDireccion\tLocalidad\tRecibe\n");

        for(i=0;i<limite;i++)
        {
            reparto_getIdReparto(al_get(listaRepartos,i),&auxId);
            reparto_getProducto(al_get(listaRepartos,i),auxProducto);
            reparto_getDireccion(al_get(listaRepartos,i),auxDireccion);
            reparto_getLocalidad(al_get(listaRepartos,i),auxLocalidad);
            reparto_getRecibe(al_get(listaRepartos,i),auxRecibe);

            printf("%d\t%s\t%s\t%s\t%s\n",auxId,auxProducto,auxDireccion,auxLocalidad,auxRecibe);
        }
    }
    return retorno;
}
