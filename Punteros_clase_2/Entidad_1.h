#ifndef ENTIDAD_1_H_INCLUDED
#define ENTIDAD_1_H_INCLUDED

typedef struct
{
    int r;
    int g;
    int b;

}Pixel;

#endif // ENTIDAD_1_H_INCLUDED
#define MAX 1024

int pixel_setRgb(Pixel* pPixel, int indexPixel, int r, int g, int b);
Pixel* pixel_new(int qty);
Pixel* pixel_getRgb(Pixel* pPixel, int indexPixel);
Pixel pixel_getPixel(Pixel* pPixel, int indexPixel);
void picel_delete(Pixel* pPixel);
Pixel* pixel_resize(Pixel* pPixel, int newQty);
