#ifndef CONTRATACION_H_INCLUDED
#define CONTRATACION_H_INCLUDED

typedef struct
{
    int idContratacion;
    int idPantalla;
    int dias;
    char cuit[20];
    char nombreVideo[50];
    unsigned char flagEstado;

} sContratacion;


#endif // CONTRATACION_H_INCLUDED

#define CONTRATACION_LIBRE 0
#define CONTRATACION_EN_CURSO 1
#include "Pantalla.h"

int cont_init(sContratacion* array, int longitud);

int cont_buscarIndiceLibre(sContratacion* array, int longitud);
int cont_alta(sContratacion* arrayContrataciones, sPantalla* arrayPantallas, int lenContrataciones, int lenPantallas);
