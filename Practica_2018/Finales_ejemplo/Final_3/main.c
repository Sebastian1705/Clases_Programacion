#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "ArrayList.h"
#include "funciones.h"
#include "deposito.h"
#include "utn.h"

int main()
{
    ArrayList* pArrayDepositos;
    pArrayDepositos = al_newArrayList();
    char seguir='s';
    int opcion;

    EDeposito* auxDeposito;

    cargarPeliculas(pArrayDepositos);

    while(seguir=='s')
    {
        opcion = 0;
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);
        system("cls");
        switch(opcion)
        {
            case 1:
                auxDeposito = crearPelicula();
                if(auxDeposito != NULL)
                {
                    if(agregarPelicula(pArrayDepositos, auxDeposito))
                       printf("\nHa habido un error\n");
                }
                break;
            case 2:
                if(borrarPelicula(pArrayDepositos))
                    printf("\nHa habido un error\n");
                break;
            case 3:
                if(modificarPelicula(pArrayDepositos))
                    printf("\nHa habido un error\n");
               break;
            case 4:
                generarPagina
                (pArrayDepositos );
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("\nOpcion incorrecta\n");
        }
        clearStdin();
    }

    return 0;
}
