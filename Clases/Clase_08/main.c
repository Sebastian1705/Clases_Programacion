#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char nombre[51];
  int edad;
  char apellido[51];

}sPersona;

int main()
{
    sPersona persona_1;

    strncpy(persona_1.nombre,"Seba",10);
    printf("%s",persona_1.nombre);

    persona_1.edad = 27;
    printf("%i", persona_1.edad);

return 0;
}
