#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED

#endif // VISTA_H_INCLUDED

#define VISTA_IDIOMA_ES 0
#define VISTA_IDIOMA_EN 1

#define MENU_PPAL_ES "\n1. Alta de cliente​\n2. Modificación​ ​ de​ ​ cliente\n3. Baja de cliente\n4. Listar​ ​ clientes\n5. Realizar una venta\n6. Anular​ ​ una​ ​ venta\n7. Informar​ ​ ventas\n8. Informar ventas por producto\n9. Generar informe de ventas\n10. Informar cantidad de ventas por cliente\n\n0. Salir\n\nOpcion: "
#define MENU_PPAL_ERROR_ES "\nOPCION INVALIDA\n"




int vista_init (int idioma);
int vista_mostrarMenu();
void mostrarError(char * mensaje);
void vista_mostrarCliente(ArrayList* nominaCliente);
void vista_mostrarVentas(ArrayList* nominaVenta);
void vista_mostrarVentasProducto(ArrayList* nominaVenta);

