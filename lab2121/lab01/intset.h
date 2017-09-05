#ifndef INTSET_H /* Prevent multiple inclusion... */
#define INTSET_H

struct Node {
  Node *next;
  int value;
  Node(Node *next, int value) {
    this->next = next;
    this->value = value;
  }
};

class Intset {

private:
  Node *head;

public:
  Intset();
  ~Intset();
  bool find(int key);
  void insert(int key);
  void remove(int key);
  void print(void);
};

#endif
