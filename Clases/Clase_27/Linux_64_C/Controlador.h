
void cont_init();

int cont_altaSocio (char* nombre,char* apellido,char* dni);
int cont_bajaSocio (int);
int cont_modificarSocio (char* nombre,char* apellido,char* dni, int id, int estado);
int cont_listarSocios ();

int cont_altaServicio(char* descripcion);
int cont_bajaServicio(int id);
int cont_modificarServicio(char* descripcion, int id, int estado);
int cont_listarServicios();

int cont_altaRelacion(int idServicio, int idSocio);
int cont_bajaRelacion(int id);
int cont_listarRelacion();
