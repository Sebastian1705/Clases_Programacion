#ifndef ASOCIADO_H_INCLUDED
#define ASOCIADO_H_INCLUDED
#define CANTIDAD_CARACTERES 51
#define ASOCIADO_OCUPADO 1
#define ASOCIADO_LIBRE 0
#define INTENTOS 3
#define CANTIDAD_ASOCIADOS 20
#include <string.h>

typedef struct
{
    char nombre[CANTIDAD_CARACTERES];
    char apellido[CANTIDAD_CARACTERES];
    char dni[CANTIDAD_CARACTERES];
    int edad;
    int idAsociado;
    int flagEstado;

}sAsociado;

#endif // ASOCIADO_H_INCLUDED

int asoc_obtenerId(sAsociado* arrayAsociado, int longitud);
int asoc_IndiceLibre(sAsociado* arrayAsociado, int longitud);
int cargarAsociado(sAsociado* arrayAsociado, int index);
int asoc_initAsociado(sAsociado* arrayAsociado, int longitud);
int asoc_modificarAsociado(sAsociado* arrayAsociado, int index);
int asoc_recibirYmodificarAsociados(sAsociado* arrayAsociado);
