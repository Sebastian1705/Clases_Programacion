#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED

typedef struct
{
    char nombre[51];
    char apellido[51];
    char dni[21];
    int id;

}Socio;


#endif // SOCIO_H_INCLUDED
#include "ArrayList.h"
#define NAME_SIZE 51
#define LAST_NAME_SIZE 51

Socio* soc_new();
void soc_delete(Socio* pSocio);

int soc_setNombre(Socio* pSocio, char *nombre);
char* soc_getNombre(Socio* pSocio);

int soc_setApellido(Socio* pSocio, char *apellido);
char* soc_getApellido(Socio* pSocio);

int soc_setId(Socio* pSocio, int id);
int soc_getId(Socio* pSocio, int id);
