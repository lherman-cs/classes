/** CPSC 1070

    Test driver for readColor() routine for homework 2

    Usage:  ./tester test_file_name

**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rgb.h"

int main(int argc, char *argv[]) {
    FILE *infp;
    color_t color;

    /* Test the number of command line arguements */
    if (argc != 2) {
       fprintf(stderr, "Usage: ./tester input_file_name\n");
       exit(1);
    }

    /* Open the test file */
    if ((infp = fopen(argv[1], "r")) == NULL) {
       fprintf(stderr, "Could not open input file %s\n", argv[1]);
       exit(1);
    }

    /* Run the readColor() test */
    color = readColor(infp);
    printf("readColor complete: value = %d %d %d (0x%x)\n", 
              color.r, color.g, color.b,
              color.r*256*256 + color.g*256 + color.b);

    return 0;
}

