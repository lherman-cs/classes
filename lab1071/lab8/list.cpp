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
            std::cout << "removing list item" << std::endl;
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
void List::addFirst(void* obj){
   Node *node = new Node(obj);
   if(head != NULL){
      node->setNext(head);
   }
   head = node;
}

/*
 * Resets the current to the head.
 * Hint: same concept as the C version.
 */
void List::reset(){
   current = head;
}

/*
 * Retruns the current Node's data.
 */
void* List::getCurItem()
{
    return current->getItem();
}

/*
 * Returns the head.
 */
Node* List::getHead()
{
    return head;
}
