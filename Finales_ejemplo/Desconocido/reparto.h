#ifndef REPARTO_H_INCLUDED
#define REPARTO_H_INCLUDED
typedef struct
{
    int idReparto;
    char producto[50];
    char direccion[200];
    char localidad[50];
    char recibe[20];
}EReparto;

EReparto* reparto_new();
EReparto* reparto_newParametros(int idReparto, char producto[50], char direccion[200], char localidad[50], char recibe[20]);

void reparto_delete();

int reparto_setIdReparto(EReparto* this,int idReparto);
int reparto_getIdReparto(EReparto* this,int* idReparto);

int reparto_setProducto(EReparto* this,char* producto);
int reparto_getProducto(EReparto* this,char* producto);

int reparto_setDireccion(EReparto* this,char* direccion);
int reparto_getDireccion(EReparto* this,char* direccion);

int reparto_setLocalidad(EReparto* this,char* localidad);
int reparto_getLocalidad(EReparto* this,char* localidad);

int reparto_setRecibe(EReparto* this,char* recibe);
int reparto_getRecibe(EReparto* this,char* recibe);

#endif // REPARTO_H_INCLUDED
