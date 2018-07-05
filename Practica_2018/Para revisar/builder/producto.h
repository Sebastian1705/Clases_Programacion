#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
typedef struct
{
    int cantidad;
    char nombre[40];
    char descripcion[128];
    float precio;
    char categoria;
    int id;
}EProducto;

