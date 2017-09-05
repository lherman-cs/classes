#ifndef LIST_H
#define LIST_H

#include "node.h"

class List {
public:
    List();
    ~List();

    void addFirst(double coef, int exp);
    void add(double coef, int exp);
    void reset();
    bool isEmpty();
    Node* getCurrent();
    Node* getHead();
    Node* getTail();

private:
    Node* head;
    Node* tail;
    Node* current;
};

#endif
