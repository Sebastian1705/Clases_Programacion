

void cont_init(void);

int cont_altaCliente (char* nombre,char* apellido,char* dni);

int cont_bajaCliente (int);

int cont_modificarCliente (int id, char* nombre,char* apellido,char* dni);

int cont_listarClientes (void);

int cont_existeCliente (int id);

int cont_importarClientes();

int cont_ordenarCliente();

int cont_servicioTecnico(int idCliente, char* cdProducto, float costo,char* fecha);
