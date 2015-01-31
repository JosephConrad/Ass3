#include <stdio.h>
#include <stdlib.h>
#include "zad3.h"


//#include "changeColor.c"
extern void changeColour(Pixel *img, int x, int y);

static Image *readImage(const char *filename)
{

}

void writeImage(const char *filename, Image *img)
{
    FILE *fp;
    //open file for output
    fp = fopen(filename, "wb");
    if (!fp) {
         fprintf(stderr, "Unable to open file '%s'\n", filename);
         exit(1);
    }
    //write the header file
    //image format
    fprintf(fp, "P6\n");
    //comments
    fprintf(fp, "# Created by %s\n",CREATOR);
    //image size
    fprintf(fp, "%d %d\n",img->x,img->y);
    // rgb component depth
    fprintf(fp, "%d\n",RGB_COMPONENT_COLOR);
    // pixel data
    fwrite(img->data, 3 * img->x, img->y, fp);
    fclose(fp);
}

int main(int argc, char *argv[]){

    if (argc != 2) { 
        printf( "usage: %s filename\n", argv[0]);
        return 0;
    }

    char buff[16];
    Image *img;
    FILE *fp;
    int c, rgb_comp_color;
    char *filename = argv[1];
     
    fp = fopen(filename, "rb");
    if (!fp) {
         fprintf(stderr, "Unable to open file '%s'\n", filename);
        exit(1);
    } 
    //read image format
    if (!fgets(buff, sizeof(buff), fp)) {
        perror(filename);
        exit(1);
    } 
    //check the image format
    if (buff[0] != 'P' || buff[1] != '6') {
         fprintf(stderr, "Invalid image format (must be 'P6')\n");
         exit(1);
    } 
    //alloc memory form image
    img = (Image *)malloc(sizeof(Image));
    if (!img) {
         fprintf(stderr, "Unable to allocate memory\n");
         exit(1);
    }
    //check for comments
    c = getc(fp);
    while (c == '#') {
    while (getc(fp) != '\n') ;
         c = getc(fp);
    }
    ungetc(c, fp);
    //read image size information
    if (fscanf(fp, "%d %d", &img->x, &img->y) != 2) {
         fprintf(stderr, "Invalid image size (error loading '%s')\n", filename);
         exit(1);
    }

    //read rgb component
    if (fscanf(fp, "%d", &rgb_comp_color) != 1) {
         fprintf(stderr, "Invalid rgb component (error loading '%s')\n", filename);
         exit(1);
    }
    //check rgb component depth
    if (rgb_comp_color!= RGB_COMPONENT_COLOR) {
         fprintf(stderr, "'%s' does not have 8-bits components\n", filename);
         exit(1);
    }
    while (fgetc(fp) != '\n') ;
    //memory allocation for pixel data
    img->data = (Pixel*)malloc(img->x * img->y * sizeof(Pixel));
    if (!img) {
         fprintf(stderr, "Unable to allocate memory\n");
         exit(1);
    }
    //read pixel data from file
    if (fread(img->data, 3 * img->x, img->y, fp) != img->y) {
         fprintf(stderr, "Error loading image '%s'\n", filename);
         exit(1);
    }
    fclose(fp); 

    printf("Before reading...\n");
    changeColour(img->data, img->x, img->y);
    printf("After reading.\nBefore writing...\nWriting to grayscale.ppm...\n");
    writeImage("grayscale.ppm",img);
    printf("Written...\n");
}
