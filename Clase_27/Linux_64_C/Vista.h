#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED

#endif // VISTA_H_INCLUDED

#define VISTA_IDIOMA_ES 0
#define VISTA_IDIOMA_EN 1

#define MENU_PPAL_ES "\n1. Listar Asociados\n2. Agregar un socio\n3. Elimina un asociado\n4. Edita un asociado\n5. Alta servicio\n6. Baja servicio\n\n8. Salir\n"
#define MENU_PPAL_EN "\n1. List Employees\n2. Add an item\n3. Edit an item\n4. Delete an item \n5. Exit \n"
#define MENU_PPAL_ERROR_ES "\nOPCION INVALIDA\n"
#define MENU_PPAL_ERROR_EN "\nINVALID OPTION\n"



int vista_init (int idioma);

int vista_mostrarMenu();

void vista_mostrarError(char *);

void vista_mostrarSocios(ArrayList* pListaSocios);

void vista_mostrarServicios(ArrayList* pListaServicios);

void vista_mostrarRelaciones(ArrayList* pListaRelaciones);

