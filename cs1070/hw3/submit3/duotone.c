/** 
 * Lukas Herman (lukash)
 * CPSC1070-001
 * #3
 * March 6, 2017
 *
 * This function converts an input PPM image to a duotone
*/


/** duotone.c 

    Convert an input PPM image to a duotone 

    Prototype:
       image_t *duotone(image_t *inImage, pixel_t tint);

       where
          inImage: pointer to the image_t of the input image,
          tint: red, green, blue values for the tint

       Return value: 
          Pointer to newly created image_t for the output image.

**/
#include "image.h"

image_t *duotone(image_t *inImage, color_t tint) 
{
   int columns = inImage->columns;
   int rows = inImage->rows;
   int brightness = inImage->brightness;

   int i;

   image_t *newImg = newImage(columns, rows, brightness);           
   color_t *newClrPtr = newImg->image;

   color_t *inClrPtr = inImage->image; 

   // Find the max intensity
   double max = tint.r;
   if(tint.g > max)
      max = tint.g;
   if(tint.b > max)
      max = tint.b;

   // RGB proportions respectively
   double proportions[] = {tint.r / max, tint.g / max, tint.b / max};

   for(i = 0; i < columns * rows; i++){
      (newClrPtr + i)->r = (double)(inClrPtr + i)->r * proportions[0];
      (newClrPtr + i)->g = (double)(inClrPtr + i)->g * proportions[1];
      (newClrPtr + i)->b = (double)(inClrPtr + i)->b * proportions[2];
   }

   return(newImg);
}

