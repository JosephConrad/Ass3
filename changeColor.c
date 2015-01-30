#include "zad3.h"

void changeColor(Image *img)
{
    int i;
    if(img){
         for(i=0; i< img->x * img->y; i++){
              int x = (img->data[i].red*77) + (img->data[i].green*151) + (img->data[i].blue*28);
              img->data[i].red = x / (RGB_COMPONENT_COLOR+1);
              img->data[i].green = x / (RGB_COMPONENT_COLOR+1);
              img->data[i].blue = x / (RGB_COMPONENT_COLOR+1);
         }
    }
}
