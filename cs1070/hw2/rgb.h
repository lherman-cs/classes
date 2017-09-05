#ifndef RGB_H
#define RGB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** color definition **/
typedef struct color {
   unsigned char r;
   unsigned char g;
   unsigned char b;
} color_t;

/** prototype statement **/
color_t readColor(FILE *fp);

#endif
