#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Cliente.h"
#include "Validaciones.h"
#include "parser.h"

/****************************************************
    Menu:
        1. Cargar datos desde data.csv
        2. Listar Clientes
        3. Ordenar por nombre y apellido
        4. Ordenar por mail
        5. Agregar un Cliente
        6. Elimina un Cliente
        7. Modificar Cliente (Nombre, Apellido y Mail)
        8. Listar Clientes
        9. Guardar datos en data.csv (modo texto)
       10. Guardar datos en data.bin (modo binario)
*****************************************************/


int main()
{
    FILE* pFile;
    ArrayList* pArrayEmpleados;
    pArrayEmpleados = al_newArrayList();

    char buffer[10];
    int option=0;
    int i;

    while(option != 11)
    {
        val_getUnsignedInt(buffer, "Menu\n\n1. Cargar datos desde data.csv\n2. Listar Clientes\n", "Error",2,5);
        option = atoi(buffer);

        switch(option)
        {
            case 1:
                parserEmployee("~/Escritorio/Programacion_1/Practica_2018/practica_pair_2/data.csv",pArrayEmpleados);
                for(i=0; i < al_len(pArrayEmpleados);i++)
                {
                    cliente_imprimir(al_get(pArrayEmpleados,i));
                }
                break;
            case 2:
                //al_map(pArrayEmpleados,cliente_imprimir);
                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
            case 8:

                break;
            case 9:

                break;
            case 10:

                break;
        }
    }


    return 0;
}

