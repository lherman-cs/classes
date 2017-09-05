/**
  Lukas Herman (lukash)
  CPSC 1071 - Lab 10
  April 8, 2017
  Triangle class header.
**/


#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public Shape{
   public:
      Triangle();
      Triangle(double a, double b, double c);
      double computeArea();
      double computePerimeter();
      void print();

   protected:
      double a;
      double b;
      double c;
};

#endif
