/** hw2.c **/

/**  Test driver for homework 3

     Creates a new PPM image from an input PPM image
        that is tinted based upon inputted red, green, blue values.
    
     Usage:

        ./hw3 input_filename output_filename

**/
#include "image.h"
#include "readVals.h"

/** Main **/
int main(int argc, char *argv[]) {
   image_t *inImage;
   image_t *newImage;
   color_t tint;

   /* Test and fetch input parameters */
   if (argc != 3) {
      fprintf(stderr, "Usage: ./hw3 infile outfile\n");
      exit(1);
   }

   /* Input the source image */
   if ((inImage = getImage(argv[1])) == NULL) {
      fprintf(stderr, "getimage() failed\n");
      exit(1);
   }

   fprintf(stdout, "Enter tint value: ");
   tint = readColor(stdin);

   /* Create a new image in duotone based on tint value */
   newImage = duotone(inImage, tint);

   /* And output the image */
   outImage(argv[2], newImage);

   exit(0);
}
