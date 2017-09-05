/*
	Name		: Lukas Herman (lukash)
	Course Number	: CPSC 1070-001 
	Assignment #	: 1
	Due Date	: 01/26/2017   
	
	Description	: The program will classify numbers: positive and
			  negative. Also, it will count the frequency of 
			  the positive numbers and negative numbers.
*/

#include<stdio.h>
#include<assert.h>

int main(int argc, char *argv[]){
   FILE *inFilePtr;
   FILE *posFilePtr;
   FILE *negFilePtr;

   int num;
   int numPos = 0;
   int numNeg = 0;

   inFilePtr = fopen(argv[1], "r");
   /* Verify if the input file exists and can be opened */
   assert(inFilePtr != NULL);

   posFilePtr = fopen(argv[2], "w");
   /* Verify if the file can be opened */
   assert(posFilePtr != NULL);

   negFilePtr = fopen(argv[3], "w");
   /* Verify if the file can be opened */
   assert(negFilePtr != NULL);

   // Will scan all the numbers from the input file and classify them
   // according to the sign of the number
   while(fscanf(inFilePtr, "%d", &num) == 1){
      if(num > 0){
         numPos++;
         fprintf(posFilePtr, "%d\n", num);
      }
      else if(num < 0){
         numNeg++;
         fprintf(negFilePtr, "%d\n", num);
      }

   }


   // Give the counts
   fprintf(posFilePtr, "\nThere are %d positive numbers\n", numPos);
   fprintf(negFilePtr, "\nThere are %d negative numbers\n", numNeg);

   // Close all the file pointers
   fclose(inFilePtr);
   fclose(posFilePtr);
   fclose(negFilePtr);

   return 0;
}
