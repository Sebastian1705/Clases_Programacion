#include "Validaciones.h"
#include "ArrayList.h"

#define MENU "\n1. Cargar depositos\n2. Listar produstos de deposito\n3. Mover productos a deposito\n4. Descontar productos de deposito\n5. Agregar productos a deposito\n6. Salir\n\nOpcion: "
#define MENU_ERROR "\nError\n"

int f_mostrarMenu();

int f_altaDeposito(int producto, char* descripcion, int cantidad);
void f_init();
int f_altaDeposito_0(int producto, char* descripcion, int cantidad);
int f_altaDeposito_1(int producto, char* descripcion, int cantidad);
int f_imprimirLista_0();
int f_imprimirLista_1();
int f_modificarDeposito(int origen, int destino, int producto);
int f_existeDeposito(int producto, ArrayList* lista);
int f_borrarDeposito(int producto, ArrayList* lista);
int f_descontarProducto(int producto,int cantidad,ArrayList* lista);
int f_agregarProducto(int producto,int cantidad,ArrayList* lista);
