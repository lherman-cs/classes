/*
	Lukas Herman
	CS1071-001
	lab 3
	February 3, 2017

	Description: This program contains custom string libraries:
		     strlen(), strupper(), and strcmp()
*/ 

/** CpSc 2100

    Sample solution to lab 3.

    String functions:
       mystrlen()
       mystrupper()
       mystrcmp()
**/

#include <stdio.h>
#include <stdlib.h>
#include "mystrings.h"

/** mystrlen **/
int mystrlen(char *s1)
{
   /** STUBBED -- insert new code here **/
   int counter = 0;
   while(*s1 != '\0'){
      counter++;
      s1++;
   }

   return counter;
}

/** mystrupper **/
char *mystrupper(char *s1)
{
   /** STUBBED -- insert new code here **/
   char *strPtr = s1;
   while(*strPtr != '\0'){
      if(*strPtr >= 'a' && *strPtr <= 'z'){
         *strPtr -= 32;
      }
      strPtr++;
   }

   return s1;
}

/** mystrcmp **/
int mystrcmp(char *s1, char *s2)
{
   /** STUBBED -- insert new code here **/
   while(((*s1 != '\0') || (*s2 != '\0')) && (*s1 == *s2)){
      s1++;
      s2++;
   }

   return *s1 - *s2;
}
