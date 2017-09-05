#include <iostream>
#include "circle.h"

#include <cmath>

Circle::Circle() :
    Shape()
{}

Circle::Circle(double radius) :
    Shape("Circle")
{
   this->radius = radius;
}

double Circle::computeArea() 
{
    return M_PI * (radius * radius);
}

double Circle::computePerimeter()
{
    return 2 * M_PI * radius;
}

void Circle::print()
{
   Shape::print();
   std::cout << "radius: " << radius << std::endl;
}

