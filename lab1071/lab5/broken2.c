/** broken2 -- run time error in code **/
#include <stdio.h>
#include <stdlib.h>

/** readmax **/
int readmax(int array[], int len) 
{
   int max;
   int ndx;
   int n;
   n = scanf("%d", &array[0]);
   if(n == 1)
   {
      max = array[0];
   }

   while ((ndx < len) && ((n = scanf("%d", &array[ndx])) == 1)) 
   {
      if(array[ndx] > max) 
      {
         max = array[ndx];
      }
      ndx++;
   }

   return(max);
}
   
/** main **/
int main() 
{
    int array[10] = {-100000, -200000, -300000, -400000, -500000,
                     -600000, -700000, -800000, -900000, -999999};
    int max;

    max = readmax(array, 10);
    printf("max = %d\n", max);

    return 0;
}
