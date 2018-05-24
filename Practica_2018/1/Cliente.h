typedef struct
{
    char dni[50];
    char nombre[51];
    char apellido[51];
    char cuit[15];
    float sueldo;
    int id;
}Cliente;


Cliente* Cliente_new();
void Cliente_delete(Cliente* this);



int Cliente_setSueldo(Cliente* this, float sueldo);
int Cliente_getSueldo(Cliente* this, float* sueldo);

int Cliente_setDni(Cliente* this, char* dni);
int Cliente_getDni(Cliente* this, char* dni);

int Cliente_setApellido(Cliente* this, char* apellido);
int Cliente_getApellido(Cliente* this, char* apellido);

int Cliente_setNombre(Cliente* this, char* nombre);
int Cliente_getNombre(Cliente* this, char* nombre);

int Cliente_setCuit(Cliente* this, char* cuit);
int Cliente_getCuit(Cliente* this, char* cuit);

int Cliente_setNewId(Cliente* this);
int Cliente_setId(Cliente* this, int id);


int isValidDni(char* dni);
int isValidNombre(char* nombre);
int isValidApellido(char* apellido);
int isValidCuit(char* cuit);
int isValidSueldo(int sueldo);
int isValidId(int id);


//int  Cliente_setEdad(Cliente* this, int edad);
//int Cliente_getEdad(Cliente* this, int* edad);


