/*
 * Name: Lukas Herman (lukash)
 * Date: March 10, 2017
 * File: list.cpp
 * Description: These are methods for the list class
 */
#include "list.h"
#include <iostream>
#include <cstring>

/*
 * Default List constructor.
 * Hint: set member variables to NULL.
 */
List::List(){
   head = NULL;
   tail = NULL;
   current = NULL;
}

/*
 * Destructor for the List.
 * This has already been implemented.
 */
List::~List()
{
    if(head != NULL) {
        Node* cur = head;
        while(cur != NULL) {
            Node* tmp = cur->getNext();
            delete cur;
            cur = tmp;
        }
    }
}

/*
 * Add a new Node to the head of the list.
 * Hint: same concept as the C version.
 */
void List::addFirst(double coef, int exp){
   Node *node = new Node(coef, exp);
   if(head == NULL && tail == NULL){
      tail = node;
   }
   else{
     node->setNext(head);
   }
   head = node;
}

/*
 * Add a new Node to the tail of the list.
 * Hint: same concept as the C version.
 */
void List::add(double coef, int exp){
   Node *node = new Node(coef, exp);
   if(head == NULL && tail == NULL){
     head = node;
   }
   else{
      tail->setNext(node);
   }
   tail = node;
}

/*
 * Resets the current to the head.
 * Hint: same concept as the C version.
 */
void List::reset(){
   current = head;
}

// Return true if empty
bool List::isEmpty(){
  return head == NULL;
}

/*
 * Retruns the current Node's data.
 */
Node* List::getCurrent()
{
    return current;
}

/*
 * Returns the head.
 */
Node* List::getHead()
{
    return head;
}

/*
 * Returns the tail.
 */
Node* List::getTail()
{
    return tail;
}
