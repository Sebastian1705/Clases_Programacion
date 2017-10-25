#ifndef ENTIDAD2_H_INCLUDED
#define ENTIDAD2_H_INCLUDED

typedef struct
{
    int id;
    int flagEstadoOcupado;
    char a[CANTIDAD_CARACTERES];
    int b;
    int idEntidad1;

}Entidad2;

#endif // ENTIDAD2_H_INCLUDED

int ent2_init(Entidad2* array, int len);
int ent2_generarProx_Id(Entidad2* array, int len);
int ent2_buscarPosicionLibre(Entidad2* array, int len);
int ent2_buscarPosicionLibre(Entidad2* array, int len);
int ent2_baja(Entidad2* array, int id, int len);
