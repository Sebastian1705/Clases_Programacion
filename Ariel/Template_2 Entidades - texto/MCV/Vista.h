#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED

#endif // VISTA_H_INCLUDED

#define VISTA_IDIOMA_ES 0
#define VISTA_IDIOMA_EN 1

#define MENU_PPAL_ES "\n1. Listar Clientes\n2. Agregar Cliente\n3. Baja Cliente\n4. Editar Cliente\n5. Ordenar Cliente\n6. Listar Alquileres\n7. Alta Alquiler\n8. Baja Alquiler\n9. Ordenar Alquiler\n10. Salir\n"
#define MENU_PPAL_EN "\n1. List Employees\n2. Add an item\n3. Edit an item\n4. Delete an item \n5. Exit \n"
#define MENU_PPAL_ERROR_ES "\nOPCION INVALIDA\n"
#define MENU_PPAL_ERROR_EN "\nINVALID OPTION\n"



int vista_init (int idioma);

int vista_mostrarMenu();

void vista_mostrarCliente(ArrayList* pListaCliente);
void vista_mostrarAlquiler(ArrayList* pListaAlquiler);


void vista_mostrarError(char *);





