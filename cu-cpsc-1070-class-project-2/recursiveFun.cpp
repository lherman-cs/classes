/**
 * Lukas Herman (lukash)
 * Homework 5
 * April 26, 2017
 *
 * Recursive function to solve the bear problem
 */

#include "recursiveFun.h"

bool bears(int numOfBears){
   // Base Cases
   if(numOfBears == 42)
      return true;
   else if(numOfBears < 42)
      return false;

   else{
      if(numOfBears % 2 == 0 && bears(numOfBears/2))
         return true;

      if(numOfBears % 3 == 0 || numOfBears % 4 == 0){
         int tmp = (numOfBears / 10) * (numOfBears % 10);
         if(tmp != 0 && bears(numOfBears - tmp))
            return true;
      }

      if(numOfBears % 5 == 0 && bears(numOfBears - 42))
         return true;

      return false;
   }
}
