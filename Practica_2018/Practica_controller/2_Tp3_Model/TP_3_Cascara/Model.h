#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

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

EMovie* model_getMovies(void);
int model_getMoviesLen(void);


#endif // MODEL_H_INCLUDED
