#include <iostream>
#include "rectangle.h"

Rectangle::Rectangle() :
    Shape()
{}

Rectangle::Rectangle(double length, double width) :
    Shape("Rectangle")
{
   this->length = length;
   this->width = width; 
}

double Rectangle::computeArea()
{
    return length * width;
}

double Rectangle::computePerimeter()
{
    return 2 * (length + width);
}

void Rectangle::print()
{
   Shape::print();
   std::cout << "length: " << length
             << "  width: " << width << std::endl; 
}

