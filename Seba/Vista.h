#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED

#endif // VISTA_H_INCLUDED


#define MENU_PPAL_ES "\n1. Alta Cliente\n2. Modificacion cliente\n3. Baja cliente\n4. Listar clientes\n5. Importar clientes desde CSV\n6. Ingresar servicio tecnico\n7. Exportar servicios\n\n8. Salir\n\nOpcion: "

#define MENU_PPAL_ERROR_ES "\nOPCION INVALIDA\n"




int vista_init (void);

int vista_mostrarMenu(void);

void vista_mostrarSocios(ArrayList* pListaSocios);

void vista_mostrarError(char *);

void vista_mostrarError(char * mensaje);

void vista_mostrarServicios(ArrayList* pListaServicios);


