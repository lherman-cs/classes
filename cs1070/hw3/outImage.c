/**
 * Lukas Herman (lukash)
 * CPSC1070-001
 * #3
 * March 6, 2017
 *
 * This function outputs a PPM image to a specified file name.
*/

/** outImage.c

    Output a PPM image to a specified file name.

    Prototype:
       void outImage(char *fileName, image_t *tintedImage);

    where
       fileName:    pointer to name of output file to create,
       tintedImage: pointer to the image_t of the image to write.

**/
#include "image.h"
#include <assert.h>

/** outImage **/
void outImage(char *fileName, image_t *tintedImage) 
{
   FILE *fileObj = fopen(fileName, "w");
   assert(fileObj != NULL);


   fprintf(fileObj, "P6 %d %d %d\n", tintedImage->columns, tintedImage->rows, tintedImage->brightness);
   fwrite(tintedImage->image, sizeof(color_t), tintedImage->columns * tintedImage->rows, fileObj);
   fclose(fileObj);
}

