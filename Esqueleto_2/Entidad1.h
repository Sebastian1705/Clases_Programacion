#ifndef ENTIDAD1_H_INCLUDED
#define ENTIDAD1_H_INCLUDED
#define CANTIDAD_CARACTERES 50

typedef struct
{
    int id;
    int flagEstadoOcupado;
    int numero;
    char cadena[CANTIDAD_CARACTERES];
    char cadenaConEspacio[CANTIDAD_CARACTERES];
    float numeroFlotante;
    char telefono[CANTIDAD_CARACTERES];

}Entidad1;

#endif // ENTIDAD1_H_INCLUDED

#define ESTADO_LIBRE 0
#define ESTADO_OCUPADO 1

int ent1_buscarIncicePorId(Entidad1* array, int len, int id);
int ent1_init(Entidad1* array, int len);
