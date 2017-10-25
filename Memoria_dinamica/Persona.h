#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#define LAST_NAME_SIZE 51
#define NAME_SIZE 51
typedef struct
{
    char nombre[51];
    char apellido[51];
    int idSector;

}Empleado;

#endif // PERSONA_H_INCLUDED
#define DEBUG 1

Empleado* empleado_new(void);
Empleado* empleado_newConstructor(char* nombre, char* apellido, int idSector);

void empleado_delete(Empleado* pEmpleado);

int empleado_setNombre(Empleado* pEmpleado, char *nombre);
char* empleado_getNombre(Empleado* pEmpleado);

int empleado_setApellido(Empleado* pEmpleado, char *apellido);
char* empleado_getApellido(Empleado* pEmpleado);

int empleado_setIdSector(Empleado* pEmpleado, int idSector);
int empleado_getIdSector(Empleado* pEmpleado, int idSector);

void empleado_debugShow(Empleado* pEmpleado);
