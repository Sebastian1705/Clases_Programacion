#define ARCHIVO_SOCIOS "socios.bin"
#define ARCHIVO_SERVICIOS "servicios.bin"
#define ARCHIVO_RELACIONES "servicios.bin"

int dm_saveAll(ArrayList* pArraySocios);
int dm_readAll(ArrayList* pArraySocios);

int dm_saveAllServicios(ArrayList* pArrayServicios);
int dm_readAllServicios(ArrayList* pArrayServicios);

int dm_saveAllRelacion(ArrayList* pArrayRelaciones);
int dm_readAllRelacion(ArrayList* pArrayRelaciones);
