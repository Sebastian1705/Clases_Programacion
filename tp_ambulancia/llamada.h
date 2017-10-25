#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED
#define INFARTO 0
#define ACV 1
#define GRIPE 2
#define PENDIENTE 0
#define CUMPLIDO 1
#include <string.h>

typedef struct
{
    int flagEstado;
    int idLlamada;
    int idAsociado;
    int idAmbulancia;
    int tiempo;
    int motivo;
    int estado;

}sLlamada;

#endif // LLAMADA_H_INCLUDED
