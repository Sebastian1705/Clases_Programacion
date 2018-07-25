#define ARCHIVO_LOG "log.txt"
#define ARCHIVO_SERVICE "services.txt"
#define ARCHIVO_WARNINGS "warnings.txt"
#define ARCHIVO_ERRORS "errors.txt"


int dm_saveAllLogEntry(ArrayList* pNominaLogEntry);
int dm_readAllLogEntry(ArrayList* pNominaLogEntry);

int dm_saveAllService(ArrayList* pArrayService);
int dm_readAllService(ArrayList* pArrayService);

int dm_save3(ArrayList* pArrayLogEntry, ArrayList* pArrayService, char* file);
