#include <stdio.h>
#include <stdlib.h>
#include "Entidad1.h"
#include "Validar.h"

int main()
{
    char bufferInt[10];
    do
    {
            val_getInt(bufferInt, "\n\tMenu\n1. opcion\n2. opcion\n3. opcion\n", "Error", 3, 10);

            switch(atoi(bufferInt))
            {
                    case 1:
                            printf("pulso 1");
                            break;
                    case 2:
                            break;
            }
    }while(atoi(bufferInt) != 5);
    return 0;
}
