void cont_init();
int cont_altaCliente (char* nombre,char* apellido,char* dni);
int cont_bajaCliente (int id);
int cont_modificarCliente(int id,char* nombre,char* apellido,char* dni);
int cont_listarCliente ();
int cont_ordenarCliente ();

int cont_existeCliente(int id);

int cont_altaVenta(int idCliente,int producto, int cantidad);
void imprimir_ventas(void* pVentas);
