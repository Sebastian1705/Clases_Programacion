#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pantalla.h"
#include "Contratacion.h"
#include "Validar.h"
#define CANT_PANTALLAS 10
#define CANT_CONTRATACIONES 10

int main()
{
    sPantalla arrayPantallas[CANT_PANTALLAS];
    sContratacion arrayContrataciones[CANT_CONTRATACIONES];
    char buffer[5];

    pant_init(arrayPantallas,CANT_PANTALLAS);
    cont_init(arrayContrataciones, CANT_CONTRATACIONES);

    do
    {
        pant_printMenu();
        val_getUnsignedInt(buffer, "\nElija una opcion: ", "Error!\n", INTENTOS, 5);
        switch(atoi(buffer))
        {
            case 1:
                val_cleanScreen();
                pant_alta(arrayPantallas, CANT_PANTALLAS);
                break;
            case 2:
                val_cleanScreen();
                pant_modificar(arrayPantallas, CANT_PANTALLAS);
                break;
            case 3:
                val_cleanScreen();
                pant_baja(arrayPantallas, CANT_PANTALLAS);
                break;
            case 4:
                val_cleanScreen();
                pant_print(arrayPantallas, CANT_PANTALLAS);
                cont_alta(arrayContrataciones, arrayPantallas, CANT_CONTRATACIONES, CANT_PANTALLAS);
                break;
            case 5:
                val_cleanScreen();
                break;
        }
    }while(atoi(buffer) != 0);

    return 0;
}
