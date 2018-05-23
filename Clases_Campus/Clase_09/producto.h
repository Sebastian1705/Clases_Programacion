#ifndef _PRODUCTO
#define _PRODUCTO
typedef struct{
    char nombre[51];
    char desc[201];
    float precio;
    unsigned char estado;
    int Id;
}sProducto;
#endif // _PRODUCTO

#define PRODUCTO_LIBRE 0
#define PRODUCTO_OCUPADO 1
#define CANTIDAD_PRODUCTOS 200
#define INTENTOS 3

int prod_cargarProducto (sProducto* arrayProducto, int index);
int prod_printProducto (sProducto* arrayProducto, int longitud);
int prod_initProducto (sProducto* arrayProducto, int longitud);
int prod_IndiceLibre(sProducto* arrayProducto, int longitud);
int prod_obtenerId(sProducto* arrayProducto, int longitud);
int prog_recibirYmodificarProductos(sProducto* arrayProducto);
