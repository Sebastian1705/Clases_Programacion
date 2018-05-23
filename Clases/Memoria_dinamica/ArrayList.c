#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "ArrayList.h"

ArrayList* arrayList_new(void)
{
    ArrayList* pArrayList;
    pArrayList = malloc(sizeof(ArrayList));
    pArrayList->size = 0;
    pArrayList->rSize = INIT_SIZE;
    pArrayList->pElements = malloc(sizeof(void*)*pArrayList->rSize);

    return pArrayList;
}

/*************************************/

int arrayList_add(ArrayList* pArray, void *element)
{
    int retorno = -1;
    if(pArray->size < pArray->rSize)
    {
        *(pArray->pElements + pArray->size) = element;
        pArray->size++;
        retorno = 0;
    }
    return retorno;
}

/*************************************/

/*nt arrayList_debugShow(ArrayList* pArray)
{
    int retorno = -1;

    return retorno;
}
*/
/*************************************/
