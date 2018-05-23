#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Interfaz.h"
#include "Validar.h"

int main()
{
    int_menu();
    ArrayList* arraySocios = NULL;
    arraySocios = al_newArrayList();

    printf("\n\n%p\n\n", arraySocios);


    return 0;
}
