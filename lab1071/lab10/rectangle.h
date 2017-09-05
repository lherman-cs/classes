#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape 
{
  public:
    Rectangle();
    Rectangle(double length, double width);
    double computeArea();
    double computePerimeter();
    void print();

  protected:
    double length;
    double width; 
};

#endif
