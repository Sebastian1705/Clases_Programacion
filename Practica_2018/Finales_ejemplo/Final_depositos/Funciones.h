#include "Validaciones.h"


#define MENU "\n1. Cargar depositos\n2. Listar produstos de deposito\n3. Mover productos a deposito\n4. Descontar productos de deposito\n5. Agregar productos a deposito\n6. Salir\n\nOpcion: "
#define MENU_ERROR "\nError\n"

int f_mostrarMenu();

int f_altaDeposito(int producto, char* descripcion, int cantidad);
void f_init();
int f_altaDeposito_0(int producto, char* descripcion, int cantidad);
int f_altaDeposito_1(int producto, char* descripcion, int cantidad);
