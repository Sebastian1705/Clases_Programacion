#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre[20];
    char descripcion[64];
    float precio;
    int estaCargado;
}Producto;


#endif // FUNCIONES_H_INCLUDED

int validarPrecio(char bPrecio[]);
int cargarDato(Producto a[],int indice);
int inicializarArray(Producto a[],int len);
