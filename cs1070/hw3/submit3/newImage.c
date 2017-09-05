/**
 * Lukas Herman (lukash)
 * CPSC1070-001
 * #3
 * March 6, 2017
 *
 * This function creates and initializes a new image_t.
*/


#include "image.h"

/** newImage 

    Create and initialize a new image_t.

    Prototype:
       image_t *newImage(int columns, int rows, int brightness);
 
    where
       columns: number of pixel columns in new PPM image
       rows:    number of pixel rows in new PPM image
       brightness:  pixel brightness (0-255)

    Return value:
       Pointer to newly allocated and initialized image_t
**/
image_t *newImage(int columns, int rows, int brightness) 
{
   image_t *newImg = (image_t*) malloc(sizeof(image_t));
   color_t *pixel = (color_t*) calloc(columns * rows, sizeof(color_t));

   newImg->image = pixel;   
   newImg->columns = columns;
   newImg->rows = rows;
   newImg->brightness = brightness;   

   return(newImg);
}
