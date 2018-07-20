#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "formatos.h"


int main()
{
   ArrayList* dep0;
   ArrayList* dep1;
    int seguir=1;

    dep0=al_newArrayList();//llamo al constructor
    dep1=al_newArrayList();//llamo al constructor
    if (validaArrayList(dep0)==0  ||validaArrayList(dep1)==0   )
    {
        return 0;
    }
    do
    {
        seguir= formato_ABM_Archivo(dep0, dep1);
    }
    while (seguir!=0);
    al_deleteArrayList(dep1);
    al_deleteArrayList(dep0);
    return 0;

}
