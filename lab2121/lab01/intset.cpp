#include "intset.h"
#include <assert.h>
#include <iostream>

using namespace std;

Intset::Intset() { head = NULL; }

Intset::~Intset() {
  if (head != NULL) {
    Node *cur = head;
    while (cur != NULL) {
      Node *tmp = cur->next;
      delete cur;
      cur = tmp;
    }
  }
}

/* Return true if key is in the set */
bool Intset::find(int key) {
  Node *cur = head;
  while (cur != NULL && cur->value != key)
    cur = cur->next;
  return cur != NULL;
}

/* Inserts a new key.  It is an error if key is already in the set. */
void Intset::insert(int key) {
  assert(!find(key));

  if (!(head == NULL || head->value > key)) {
    // Sorted in ascending order
    Node *before = head;
    while (before->next != NULL && before->next->value < key)
      before = before->next;

    before->next = new Node(before->next, key);
  } else
    head = head == NULL ? new Node(NULL, key) : new Node(head, key);
}

/* Removes a key.  It is an error if key isn't in the set */
void Intset::remove(int key) {
  assert(find(key));

  Node *target = head;
  Node *before = target;
  while (target->value != key) {
    before = target;
    target = target->next;
  }

  if (target == head)
    head = target->next;
  else
    before->next = target->next;

  delete target;
}

void Intset::print(void) {
  Node *cur = head;
  while (cur != NULL) {
    cout << cur->value << "\n";
    cur = cur->next;
  }
}
