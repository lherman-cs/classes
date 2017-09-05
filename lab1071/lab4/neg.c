#include <stdio.h>
#include <stdlib.h>

void process_neg(FILE *outfile, int value, int *negCount)
{
   *negCount += 1;
   fprintf(outfile, "%d\n", value);
}
