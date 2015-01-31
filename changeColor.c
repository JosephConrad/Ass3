#include "zad3.h"

void changeColour(Pixel *img, int x, int y)
{
    int i;
    for(i=0; i< x * y; i++){
        int val = (img[i].red*77) + (img[i].green*151) + (img[i].blue*28);
        img[i].red = val / 256;
        img[i].green = val / 256;
        img[i].blue = val / 256;
    }
}
