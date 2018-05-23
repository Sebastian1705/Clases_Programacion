#define ARCHIVO_CLIENTES "clientes.bin"
#define ARCHIVO_ALQUILER "alquiler.bin"

int dm_saveAll(ArrayList* pArraySocios);
int dm_readAll(ArrayList* pArraySocios);

int dm_saveAllAlquiler(ArrayList* pArrayAlquiler);
int dm_readAllAlquiler(ArrayList* pArrayAlquiler);



int dm_saveAllClienteTexto(ArrayList* nominaCliente);
int dm_readAllClienteTexto(ArrayList* pArrayCliente);

