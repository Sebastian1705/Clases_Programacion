#include <stdio.h>
#include <stdlib.h>
#include "pixel.h"


Pixel* pixel_new(int qty)
{
    Pixel* arrayPixel = NULL;
    arrayPixel = malloc(sizeof(Pixel) * qty);
    return arrayPixel;
}

void pixel_delete(Pixel* pPixel)
{
    if(pPixel != NULL)
        free(pPixel);
}



int pixel_setRgb(Pixel* pPixel,int index, int r, int g, int b)
{
    int retorno = -1;
    if(pPixel != NULL && index >= 0)
    {
        retorno = 0;
        (pPixel + index)->r = r;
        (pPixel + index)->g = g;
        (pPixel + index)->b = b;
    }
    return retorno;
}

Pixel* pixel_getRgb(Pixel* pPixel,int index)
{

    return pPixel+index;
}


Pixel pixel_getPixel(Pixel* pPixel,int index)
{

    return *(pPixel+index);
}
