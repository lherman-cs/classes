#include <iostream>
#include "shape.h"

Shape::Shape() :
   type("")
{ }

Shape::Shape(string t) :
    type(t)
{}

string Shape::getType()
{
    return type;
}

void Shape::print()
{
   std::cout << "\ntype: " << type << std::endl;
}
            
