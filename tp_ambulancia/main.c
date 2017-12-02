#include <stdio.h>
#include <stdlib.h>
#include "asociado.h"
#include "llamada.h"
#include "validar.h"

int main()
{
    sAsociado array_asociados[CANTIDAD_ASOCIADOS];
    char buffer[20];

    asoc_initAsociado(array_asociados, CANTIDAD_ASOCIADOS);


    do
    {
        val_getUnsignedInt(buffer,"\tMENU PRINCIPAL\n1. ALTA DEL ASOCIADO\n2. MODIFICAR DATOS DEL ASOCIADO\n3. BAJA DEL ASOCIADO\n4. NUEVA LLAMADA\n5. ASIGNAR AMBULANCIA\n6. INFORMAR\n9. SALIR\n\n","errror\n",INTENTOS,CANTIDAD_ASOCIADOS);

        switch(atoi(buffer))
        {
            case 1:
                system("cls");
                cargarAsociado(array_asociados, asoc_IndiceLibre(array_asociados, CANTIDAD_ASOCIADOS));
                system("cls");
                break;
            case 2:
                system("cls");
                asoc_recibirYmodificarAsociados(array_asociados);
                system("cls");
                break;
            case 3:

                break;
        }

    }while(atoi(buffer) != 9);


    return 0;
}
