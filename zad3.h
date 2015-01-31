#ifndef ZAD3_H
#define ZAD3_H

#define CREATOR "KONRAD_LISIECKI_291649"
#define RGB_COMPONENT_COLOR 255

typedef struct {
     unsigned char red,green,blue;
} Pixel;

typedef struct {
     int x, y;
     Pixel *data;
} Image;

#endif