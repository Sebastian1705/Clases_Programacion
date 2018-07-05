#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "Model.h"

int main()
{
    char seguir='s';
    int opcion=0;

    if ((importarPeliculas(model_getMovies(),model_getMoviesLen())) == -1)
        pelicula_init(model_getMovies(),model_getMoviesLen());


    while(seguir=='s')
    {
        printf("\n1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion)
        {
            case 1:
                 pelicula_alta(model_getMovies(),model_getMoviesLen());
                 autoSavePeliculas(model_getMovies(),model_getMoviesLen());
                break;
            case 2:
                 pelicula_baja(model_getMovies(),model_getMoviesLen());
                 autoSavePeliculas(model_getMovies(),model_getMoviesLen());
                break;
            case 3:
                  pelicula_modificar(model_getMovies(),model_getMoviesLen());
                  autoSavePeliculas(model_getMovies(),model_getMoviesLen());
               break;
            case 4:
                 generarPagina(model_getMovies(),"template/index.html",model_getMoviesLen());
                break;
            case 5:
                autoSavePeliculas(model_getMovies(),model_getMoviesLen());
                seguir = 'n';

                break;
        }
    }

    return 0;
}
