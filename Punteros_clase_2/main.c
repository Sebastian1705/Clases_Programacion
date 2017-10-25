#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Entidad_1.h"

int main()
{
    Pixel *pPixel;
    Pixel *pAuxPixel;


    pPixel = pixel_new(10);

    if(pixel_setRgb(pPixel, 10, 100, 100, 100)== -1)
    {
        printf("Error\n");
    }

    pAuxPixel = pixel_getRgb(pPixel, 10);
    if(pAuxPixel != NULL)
    {
        printf("ROJO: %d\tVERDE: %d\tBLANCO: %d\n",pAuxPixel->r, pAuxPixel->g, pAuxPixel->b);
    }


    return 0;
}
