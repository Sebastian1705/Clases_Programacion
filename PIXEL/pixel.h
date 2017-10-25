#ifndef __PIXEL
#define __PIXEL
typedef struct
{
    int r;
    int g;
    int b;
}Pixel;
#endif

Pixel* pixel_new(int qty);
int pixel_setRgb(Pixel* pPixel,int index, int r, int g, int b);
Pixel* pixel_getRgb(Pixel* pPixel,int index);
Pixel pixel_getPixel(Pixel* pPixel,int index);
