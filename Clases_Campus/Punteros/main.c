#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int edad;
    char nombre[20];

}Persona;

int cargarPersona(Persona* pPersona)
{
    int auxInt = 0;
    char auxChar[20];
    printf("Nombre:\n");
    fgets(auxChar, 20, stdin);
    printf("Edad:\n");
    scanf("%d", &auxInt);

    pPersona->edad = auxInt;
    strncpy(pPersona->nombre, auxChar, 21);

    return 0;
}

void printPersona(Persona* pPersona)
{
    printf("Nombre: %s\n", pPersona->nombre);
    printf("Edad: %d\n", pPersona->edad);

}

int main()
{
    Persona yo;

    cargarPersona(&yo);
    printPersona(&yo);

    return 0;
}
