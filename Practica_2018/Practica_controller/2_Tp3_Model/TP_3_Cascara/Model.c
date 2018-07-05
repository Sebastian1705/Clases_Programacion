#include "Model.h"

#define CANTIDAD_PELICULAS 10

static EMovie arrayPeliculas[CANTIDAD_PELICULAS];


EMovie* model_getMovies(void)
{
    return arrayPeliculas;
}

int model_getMoviesLen(void)
{
    return CANTIDAD_PELICULAS;
}



