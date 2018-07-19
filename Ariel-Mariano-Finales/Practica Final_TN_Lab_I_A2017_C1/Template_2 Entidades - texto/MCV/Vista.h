#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED

#endif // VISTA_H_INCLUDED

#define VISTA_IDIOMA_ES 0
#define VISTA_IDIOMA_EN 1

#define MENU_PPAL_ES "\n1. Listar LogEntrys\n2. Ordenar LogEntry\n3. Listar Services\n4. Ordenar Service\n5. Procesar INFO\n6. Mostrar Estadisticas\n7. Salir\n"
#define MENU_PPAL_EN "\n1. List Employees\n2. Add an item\n3. Edit an item\n4. Delete an item \n5. Exit \n"
#define MENU_PPAL_ERROR_ES "\nOPCION INVALIDA\n"
#define MENU_PPAL_ERROR_EN "\nINVALID OPTION\n"



int vista_init (int idioma);

int vista_mostrarMenu();

void vista_mostrarLogEntry(ArrayList* pListaLogEntry);
void vista_mostrarService(ArrayList* pListaService);


void vista_mostrarError(char *);





