#ifndef ENTIDAD1_H_INCLUDED
#define ENTIDAD1_H_INCLUDED
#define CANTIDAD_CARACTERES 50
#define ESTADO_OCUPADO 1
#define ESTADO_lIBRE 0
#define INTENTOS 3

typedef struct
{
    int id;
    int flagEstadoOcupado;
    char a;
    int b;

}Entidad1;

#endif // ENTIDAD1_H_INCLUDED

int ent1_buscarPosicionLibre(Entidad1* array, int len);
int ent1_buscarIncicePorId(Entidad1* array, int len, int id);
int ent1_baja(Entidad1* array, int id, int len);

