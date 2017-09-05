/**
  Lukas Herman (lukash)
  CPSC 1071 - Lab 10
  April 8, 2017
  This is just a suit test
**/

#include <iostream>
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
int main()
{
    // creating a rectangle with lenght and width 3.0 and 4.0
    Rectangle r(3.0, 4.0);

    r.print();
 
    std::cout << "\nRectangle's perimeter: " 
              << r.computePerimeter() << std::endl;
    std::cout << "Rectangle's area:      " 
              << r.computeArea() << std::endl;

    Circle c(3.0);

    c.print();
    std::cout << "\nCircle's area: " << c.computeArea() << std::endl;
    std::cout << "Circle's circumference: " << c.computePerimeter()
              << std::endl;
    // TODO: test your triangle code here.
    // instantiate a Triangle class with 3.0, 4.0, and 5.0 as its sides
    // then invoke the print() method to print the triangle.
    Triangle tri(3.0, 4.0, 5.0);

    tri.print();
    std::cout << "\nTriangle's area: " << tri.computeArea() << std::endl;
    std::cout << "Triangle's perimeter: " << tri.computePerimeter() 
              << std::endl;

    return 0;
}
