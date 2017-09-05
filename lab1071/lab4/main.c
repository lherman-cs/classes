/**
 * Name		: Lukas Herman
 * Course	: 2070-001
 * Assignment #	: 4
 * Due Date	: February 11, 2017
 * Description	: This assignment is to learn how to turn on/off
 *		  the debugger.
*/

#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1
#define ARGS 3
#define INPUT 1
#define POS_OUT 2
#define NEG_OUT 3

/*  function prototypes                                   */
void process_pos(FILE *outfile, int value, int *pos_count);
void process_neg(FILE *outfile, int value, int *neg_count);

int main(int argc, char *argv[])
{
   int n;
   int value;
   int pos_count = 0;
   int neg_count = 0;

   FILE *input;
   FILE *posFile;
   FILE *negFile;

   /* verify sufficient command-line arguments */
   if(argc < ARGS)
   {
       fprintf(stderr, "Usage: ./hw2 infile pos_file, neg_file. ");
       fprintf(stderr, "Exiting\n");
       exit(1);
   }

   /* open file for reading and verify success */
   input = fopen(argv[INPUT], "r");
   if(input == NULL)
   {
      fprintf(stderr, "input file %s does not exist. Exiting. \n", 
              argv[INPUT]);
      exit(1);
   }

   /* open files for writing  */
   posFile = fopen(argv[POS_OUT], "w");
   negFile = fopen(argv[NEG_OUT], "w");
 
   n = fscanf(input, "%d", &value);
   while(n == 1)
   {
      if(value > 0){
         process_pos(posFile, value, &pos_count);
         #if DEBUG
            fprintf(stderr, "%d\n", value);
            fprintf(stderr, "%d is positive.  count = %d\n\n", value, pos_count);
         #endif
      }

      else if(value < 0){
         process_neg(negFile, value, &neg_count);
         #if DEBUG
            fprintf(stderr, "%d\n", value);
            fprintf(stderr, "%d is negative.  count = %d\n\n", value, neg_count);
         #endif
      }

      n = fscanf(input, "%d", &value);
   }

   /*  print totals  */
   fprintf(posFile, "\npositive count is %d\n", pos_count);
   fprintf(negFile, "\nnegative count is %d\n", neg_count);

   return 0;
}
