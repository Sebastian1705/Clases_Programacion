#ifndef ENTIDAD2_H_INCLUDED
#define ENTIDAD2_H_INCLUDED

typedef struct
{
    int id;
    int flagEstadoOcupado;
    int numero;
    char cadena[50];
    char cadenaConEspacio[50];
    float numeroFlotante;
    char telefono[50];
    int idEntidad1;

}Entidad2;

#endif // ENTIDAD2_H_INCLUDED

#define ESTADO_LIBRE 0
#define ESTADO_OCUPADO 1

