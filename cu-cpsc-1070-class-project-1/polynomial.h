#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <fstream>
#include "list.h"

using namespace std;

class Polynomial{
public:
  Polynomial();
  Polynomial(ifstream &input);
  Polynomial(const Polynomial &polynomial);
  ~Polynomial();

  Polynomial add(const Polynomial &polynomial);
  bool equals(const Polynomial &polynomial);
  int getDegree();
  void print();

  List* getList();

private:
  List *list;
};

#endif
