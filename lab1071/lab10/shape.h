#ifndef SHAPE_H
#define SHAPE_H

#include <string>

using namespace std;

class Shape 
{
  public:
    Shape();
    Shape(string type);
    string getType();

    virtual double computeArea() = 0;
    virtual double computePerimeter() = 0;
    virtual void print();

  protected:
    string type;

  private:
    int id;
};

#endif
