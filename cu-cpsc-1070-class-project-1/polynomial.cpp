#include <iostream>
#include "polynomial.h"
#include "iterator.h"

using namespace std;

// Default constructor
Polynomial::Polynomial(){
  list = new List();
}

// Constructor with input stream
Polynomial::Polynomial(ifstream &input){
  list = new List();
  double coef;
  int exp;

  input >> coef;
  while(coef != -9999.99){
    input >> exp;
    // Add the coef and exp to the list
    list->add(coef, exp);

    input >> coef;
  }
}

// Copy constructor
Polynomial::Polynomial(const Polynomial &polynomial){
  list = new List();
  Iterator it(polynomial.list);
  while(it.hasNext()){
    Node* curNode = it.get();
    list->add(curNode->getCoef(), curNode->getExp());
    it.advance();
  }
}

// Destructor
Polynomial::~Polynomial(){
  Iterator it(list);
  while(it.hasNext()){
    delete it.get();
    it.advance();
  }
}

/* TODO
// Return the sum of the two polynomials
Polynomial Polynomial::add(const Polynomial &polynomial){

  if(list->isEmpty() && polynomial.list->isEmpty()){
    Polynomial result;
    return result;
  }
  else{
    Polynomial result;
    List* resultList = result.list;
    Iterator it1(list);
    Iterator it2(polynomial.list); // iterator for the adder


    return result;
    }
  }
}
*/

bool Polynomial::equals(const Polynomial &polynomial){
  Iterator it1(list);
  Iterator it2(polynomial.list);
  while(it1.hasNext() && it2.hasNext()){
    Node* node1 = it1.get();
    Node* node2 = it2.get();

    if(node1->getCoef() != node2->getCoef() ||
        node1->getExp() != node2->getExp())
      return false;

    it1.advance();
    it2.advance();
  }

  if(!it1.hasNext() && !it2.hasNext())
    return true;
  return false;
}

int Polynomial::getDegree(){
  Iterator it(list);
  int max = it.get()->getExp();
  it.advance();
  while(it.hasNext()){
    int exp = it.get()->getExp();
    if(exp > max)
      max = exp;
    it.advance();
  }
  return max;
}

void Polynomial::print(){
  double coef;
  int exp;
  bool first = true;
  Iterator it(list);
  while(it.hasNext()){
    Node* curNode = it.get();
    coef = curNode->getCoef();
    exp = curNode->getExp();

    if(!first){
      if(coef > 0)
        cout << "+";
    }
    else
      first = false;


    if(coef != 0 && coef != 1)
      cout << coef;

    if(exp < 0)
      cout << "-";

    if(exp != 0){
      cout << "x^";
      cout << exp;
    }

    it.advance();
  }
}
