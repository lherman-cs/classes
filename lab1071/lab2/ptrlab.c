/*
    CPSC 1071
    Lab 2
    Pointers
*/

#include <stdio.h>

int main()
{
   char c = 'a';
   int x = 25;
   float f = 7.537;
   double d = 297.8355;

   char *cptr = &c;
   int *xptr = &x;
   float *fptr = &f;
   double *dptr = &d;

   printf("\nPrinting addresses:\n");
   printf("&c = %p \n&x = %p \n&f = %p \n&d = %p\n", &c, &x, &f, &d);
   printf("&cptr = %p \n&xptr = %p \n&fptr = %p \n$dptr = %p\n",
           &cptr, &xptr, &fptr, &dptr); 

   printf("\nPrinting content:\n"); 
   printf("\nc = %c,  cptr = %p\n", c, cptr);
   printf("x = %d,  xptr = %p\n", x, xptr);
   printf("f = %.2f,  fptr = %p\n", f, fptr);
   printf("d = %.2lf,  dptr = %p\n", d, dptr);
   
   printf("\nPrinting val and *val:\n");
   printf("c = %c,  *cptr = %c\n", c, *cptr);
   printf("x = %d,  *xptr = %d\n", x, *xptr);
   printf("f = %f,  *fptr = %f\n", f, *fptr);
   printf("d = %.2lf,  *dptr = %.2lf\n", d, *dptr);

   /**    DO THIS                   

         write code to modify the values of c, x, and d 
         via the pointers
    */
   
   *cptr = 'a';
   *xptr = 10;
   *fptr = 10.5;
   *dptr = 10.55;

  
   printf("\nPrinting modified values:\n");
   printf("c = %c,  *cptr = %c\n", c, *cptr);   
   printf("x = %d,  *xptr = %d\n", x, *xptr);
   printf("d = %.2lf,  *dptr = %.2lf\n\n", d, *dptr);


   /**** incrementing (*xptr)
         note that the address stored in xptr does not change
    */   
   (*xptr)++;
   printf("*xptr = %d,  xptr = %p\n", *xptr, xptr);

  printf("\npointers before increment:\n");
  printf("cptr = %p\n", cptr);
  printf("xptr = %p\n", xptr);
  printf("fptr = %p\n", fptr);
  printf("dptr = %p\n", dptr);

  /**  incrementing the pointers
       note how the addresses stored in the pointers change
       do not dereference the pointers, since they may not
       point to valid addresses for this program.
    */   

  cptr++;
  xptr++;
  fptr++;
  dptr++;

  printf("\npointers after increment:\n");
  printf("cptr = %p\n", cptr);
  printf("xptr = %p\n", xptr);
  printf("fptr = %p\n", fptr);
  printf("dptr = %p\n", dptr);

  return 0;

}

