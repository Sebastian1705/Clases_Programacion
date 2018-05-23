#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Entidad_1.h"

int pixel_setRgb(Pixel* pPixel, int indexPixel, int r, int g, int b)
{
    int retorno = -1;
    if(pPixel != NULL && indexPixel >=0)
    {
        (pPixel+indexPixel)->r = r; //(pPixel+indexPixel).r = r; ES LO MISMO//
        (pPixel+indexPixel)->g = g;
        (pPixel+indexPixel)->b = b;
        return 0;
    }
    return retorno;
}

Pixel* pixel_getRgb(Pixel* pPixel, int indexPixel)
{
    return pPixel+indexPixel;
}

Pixel pixel_getPixel(Pixel* pPixel, int indexPixel)
{
    return *(pPixel+indexPixel);
}

Pixel* pixel_new(int qty)
{
    Pixel* pPixel = NULL;
    pPixel = malloc(sizeof(Pixel)*qty);
    return pPixel;
}

void picel_delete(Pixel* pPixel)
{
    if(pPixel != NULL)
    {
        free(pPixel);
    }
}


