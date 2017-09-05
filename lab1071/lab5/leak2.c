#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "leak.h"

#define N 5
#define ARGS 3
#define INFILE 1
#define VALUES 2

void fill(FILE *in, int *mydata, int numVals);

int main(int argc, char *argv[])
{
   int i;
   int numVals;
   int *data = NULL;
   FILE *input = NULL;

   // verify sufficient command-line arguments
   if(argc < ARGS)
   {
      fprintf(stderr, "\nExpecting:  ./leak infile datacount\n");
      fprintf(stderr, "Exiting\n");
      exit(1);
   }

   // open file and verify success
   input = fopen(argv[INFILE], "r");
   assert(input != NULL);
   
   // convert value string to int
   numVals = atoi(argv[VALUES]);

   // dynamically allocate memory for numVals integers and verify success
   data = (int *)malloc(numVals * sizeof(int));
   assert(data != NULL);
   free(data);

   // invoke fill to read data
   fill(input, data, numVals);
   fclose(input);

   // print data
   for(i = 0; i < numVals; i++)
      printf("%d\n", *(data + i));

   // for debugging purposes
   int *x = (int *)malloc(N * sizeof(int));
   free(x);
   x = &i;
   printf("\nx = %d\n", *x);
   
   return 0;
}

/* 
   reads the input file and stores values into the mydata array 
*/
void fill(FILE *in, int *mydata, int numVals)
{
   int i;
   int *temp = (int *)malloc(numVals *sizeof(int));
   assert(temp != NULL);
   
   free(temp);
   temp = mydata;

   for(i = 0; i < numVals; i++)
      fscanf(in, "%d\n", (mydata + i));

}

