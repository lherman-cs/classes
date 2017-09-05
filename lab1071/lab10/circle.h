#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape 
{
  public:
    Circle();
    Circle(double r);
    double computeArea();
    double computePerimeter();  // typically circumference
    void print();

  protected:
    double radius;
};

#endif
