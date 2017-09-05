#include <iostream>
#include <string.h>
#include <assert.h>
#include "stringset.h"

using namespace std;

/* Return a hash for the string s in the range 0..table_size-1 */
int hash(string s, int table_size)
{
  unsigned int i, h = 0;
  for (i=0; i<s.length(); i++)
    h = (h * 2917 + (unsigned int)s[i]) % table_size;
  return h;
}

/* Allocate a table of pointers to nodes, all initialized to NULL */
Node **allocate_table(int size)
{
  Node **table = new Node *[size];
  for (int i=0; i<size; i++)
    table[i] = NULL;
  return table;
}

Stringset::Stringset()
{
  size = 4; // initial size of table
  table = allocate_table(size);
  num_elems = 0;
}

Stringset::~Stringset()
{
  for (int i=0; i<size; i++) {
    while (table[i] != NULL) {
      Node *temp = table[i];
      table[i] = table[i]->next;
      delete temp;
    }
  }
  delete[] table;
}

/* Return true if key is in the set */
bool Stringset::find(string key)
{
  int h = hash(key, size);
  Node *n = table[h];
  while (n != NULL) {
    if (n->key == key) return true;
    n = n->next;
  }
  return false;
}

/* Inserts a new key.  It is an error if key is already in the set. */
void Stringset::insert(string key)
{
  assert (!find(key));
  num_elems++;

  if (num_elems == size) {
    // TBD: Expand table -- allocate new table of twice the size,
    // re-insert all keys into new table, and de-allocate old table.
    // (you may want to wait and add this code last, once everything
    // else is working, since the class will still function properly,
    // albeit slowly, without this part)

    // Allocate new table that's twice the size
    Node **newTable = allocate_table(size * 2);
    for(int i = 0; i < size; i++){
      // re-insert all keys into the new table
      Node *n = table[i];
      while(n != NULL){
        int h = hash(n->key, size * 2);
        newTable[h] = new Node(n->key, newTable[h]);

        Node *del = n;
        n = n->next;
        delete del;
      }
    }
    delete []table;
    table = newTable;
    size *= 2;
  }

  // TBD: Insert new element
  int h = hash(key, size);
  table[h] = new Node(key, table[h]);
}

/* Removes a key.  It is an error if key isn't in the set */
void Stringset::remove(string key)
{
  assert (find(key));
  num_elems--;

  // TBD: Delete element
  int h = hash(key, size);
  Node *target = table[h];
  Node *before = target;
  while (target->key != key) {
    before = target;
    target = target->next;
  }

  // If the target is the node that is pointer by head, just adjust head
  if (target == table[h])
    table[h] = target->next;
  else
    before->next = target->next;

  delete target;
}

void Stringset::print(void)
{
  // TBD: Print contents of table
  for(int i = 0; i < size; i++){
    Node *n = table[i];
    while(n != NULL){
      cout << n->key << " ";
      n = n->next;
    }
    cout << endl;
  }
}
