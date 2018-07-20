#ifndef DEPOSITO_H_INCLUDED
#define DEPOSITO_H_INCLUDED

typedef struct
{
    int codProducto;
    char descripcion[256];
    int cantidad;
}EProducto;

EProducto* producto_new(void);
EProducto* producto_newP(int codProducto, char* descripcion, int cantidad);
void producto_delete(EProducto* this);

int producto_setCodProducto(EProducto* this,int codProducto);
int producto_setDescripcion(EProducto* this,char* descripcion);
int producto_setCantidad(EProducto* this,int cantidad);

int producto_getCodProducto(EProducto* this,int* codProducto);
int producto_getDescripcion(EProducto* this,char* descripcion);
int producto_getCantidad(EProducto* this,int* cantidad);


#endif // DEPOSITO_H_INCLUDED
