#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define CANTIDAD_PELICULAS 10
#define LEN_DESCRIPCION 1000
#define LEN_LINK 1000

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[LEN_DESCRIPCION];
    float puntaje;
    char linkImagen[LEN_LINK];
    int flagOcupado;
    int idPelicula;
}EMovie;

#endif // FUNCIONES_H_INCLUDED



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
