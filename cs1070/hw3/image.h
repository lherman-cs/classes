/** image.h **/
#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** color_t definition **/
typedef struct colorType {
   unsigned char r;  // Red value
   unsigned char g;  // Green value
   unsigned char b;  // Blue value
} color_t;

/** image_t defintion **/
typedef struct imageType {
   color_t *image;   // Pointer to PPM image binary data
   int     columns;  // Number of pixel columns
   int     rows;     // Number of pixel rows
   int     brightness; // Image brightness
} image_t;

/** Prototype statements **/
image_t *getImage(char *inFileName);
image_t *newImage(int columns, int rows, int brightness);
void    outImage(char *fileName, image_t *outImage);
image_t *duotone(image_t *inImage, color_t tint);

#endif