#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED

typedef struct
{
    int id;
    int tipo;
    char nombre[50];
    char direccion[100];
    float precio;
    unsigned char flagEstado;

} sPantalla;

#endif // PANTALLA_H_INCLUDED

#define PANTALLA_LIBRE 0
#define PANTALLA_OCUPADA 1
#define INTENTOS 3
#define LED 1
#define LCD 2


int pant_init(sPantalla* array, int longitud);

int pant_buscarPosicionLibre(sPantalla* array, int longitud);
int pant_buscarIndicePorId(sPantalla* array, int len, int id);

void pant_printMenu(void);

int pant_alta(sPantalla* array, int longitud);
int pant_modificar(sPantalla* array, int longitud);
int pant_baja(sPantalla* array, int longitud);
int pant_print(sPantalla* array, int longitud);
