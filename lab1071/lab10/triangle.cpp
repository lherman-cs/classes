/**
  Lukas Herman (lukash)
  CPSC 1071 - Lab 10
  April 8, 2017
  Triangle class implementation.
**/

#include <iostream>
#include <cmath>
#include "triangle.h"

using namespace std;

Triangle::Triangle():
   Shape(){
   
}

Triangle::Triangle(double a, double b, double c):
   Shape("Triangle"){
 
   this->a = a;
   this->b = b;
   this->c = c;
}


double Triangle::computeArea(){
   double s = (a + b + c)/2;
   return sqrt(s*(s-a)*(s-b)*(s-c));
}

double Triangle::computePerimeter(){
   return a + b + c;
}

void Triangle::print(){
   Shape::print();
   cout << "Side 1: " << a << endl
        << "Side 2: " << b << endl
        << "Side 3: " << c << endl;
}
