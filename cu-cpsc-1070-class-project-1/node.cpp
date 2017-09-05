/*
 * Name: Lukas Herman (lukash)
 * Date: March 10, 2017
 * File: node.cpp
 * Description: These are methods for the node class
 */
#include "node.h"

#include <cstring>

/*
 * Default Node constructor.
 * Hint: the member variables need to be initialized to NULL.
 */
Node::Node(){
   this->coef = 0.0;
   this->exp = 0;
   next = NULL;
}

/*
 * Specialized constructor.
 * Hint: still need to initialize member variables, but one of them
 *       will be set to the constructor argument.
 */
Node::Node(double coef, int exp){
   this->coef = coef;
   this->exp = exp;
   next = NULL;
}

/*
 * Node Destructor
 */
Node::~Node()
{
    // left blank intentionally.
}

/*
 * Returns the next node.
 */
Node* Node::getNext(){
    return next;
}

/*
 * Returns the Node's coef.
 */
double Node::getCoef(){
    return coef;
}

/*
 * Returns the Node's exp.
 */
int Node::getExp(){
    return exp;
}

/*
 * Sets the Node's coef variable.
 */
void Node::setCoef(double coef){
   this->coef = coef;
}


/*
 * Sets the Node's exp variable.
 */
void Node::setExp(int exp){
   this->exp = exp;
}


/*
 * Sets the Node's next variable.
 */
void Node::setNext(Node* n){
   next = n;
}
