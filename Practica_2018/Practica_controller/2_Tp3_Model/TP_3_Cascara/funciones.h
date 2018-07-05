#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "Model.h"

void generarPagina(EMovie lista[], char nombre[], int lenPeliculas);
int importarPeliculas(EMovie movie[],int lenPeliculas);
int autoSavePeliculas(EMovie movie[],int lenPeliculas);
int pelicula_alta(EMovie movie[],int lenPeliculas);
int pelicula_init(EMovie movie[], int len);
int pelicula_buscarPosicionLibre(EMovie movie[], int len);
int pelicula_generarProximoId(EMovie movie[],int len);
int pelicula_buscarIndicePorId(EMovie movie[],int len,int id);
int pelicula_modificar(EMovie movie[],int len);
int pelicula_baja(EMovie movie[],int len);
void pelicula_print(EMovie movie[], int len, int estado);

#endif // FUNCIONES_H_INCLUDED
