

void cont_init();

int cont_altaCliente (char* nombre,char* apellido,char* dni);

int cont_bajaCliente (int);

int cont_modificarCliente (char* nombre,char* apellido,char* dni, int id, int estado);

int cont_existeCliente (int id);

int cont_listarCliente ();

int cont_ordenarCliente();


//********************Alquiler

int cont_altaAlquiler (int idCliente,int equipo);

int cont_bajaAlquiler (int id);

int cont_modificarAlquiler (char* descripcion, int id, int estado);

int cont_existeAlquiler (int id);

int cont_listarAlquiler ();

int cont_ordenarAlquiler();



