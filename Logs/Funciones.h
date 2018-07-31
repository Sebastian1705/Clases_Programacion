#include "ArrayList.h"
#include "Validaciones.h"
#include "Entidad_1.h"
#include"Entidad_2.h"

#define MENU "\n1. Opcion_1\n2. Opcion_2\n3. Opcion_3\n4. Opcion_4\n5. Opcion_5\n\n6. Salir\n\nOpcion: "
#define MENU_ERROR "\nError\n"

int f_mostrarMenu();
int f_init();
int f_opcion_1();
int f_opcion_2();
int f_opcion_3();
int f_opcion_4();
int f_opcion_5();

int f_calcularFallos(int id);
void f_mostrarFallos();
void f_mostarFallo(Service* auxiliar);
