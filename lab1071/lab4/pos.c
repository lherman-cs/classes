#include <stdio.h>
#include <stdlib.h>

void process_pos(FILE *outfile, int value, int *posCount)
{
   *posCount += 1;
   fprintf(outfile, "%d\n", value);
}
