/**
 * Lukas Herman (lukash)
 * CPSC1071-001
 * #6
 * 02/26/2017
 * These are the list and iterator functions.
 */

/* List functions */
#include "list.h"

/** 
  newList -- create a new list 
**/
list_t *newList() 
{
      /** STUBBED  **/
    list_t *newList = (list_t*) malloc(sizeof(list_t));
    newList->head = NULL;
    return newList;  // update this
}


/** 
   l_add -- add an object to the front of the linked list 
**/
void l_add(list_t *list, void *objPtr) 
{
    /** STUBBED  **/
   node_t *node = (node_t *) malloc(sizeof(node_t));
   node->objPtr = objPtr;
   
   if(list->head != NULL){
      node->next = list->head;
   }
   list->head = node;
}


/** 
   newIterator -- create a new iterator and associate it with the
   specified list
**/
iterator_t *newIterator(list_t *list) 
{

   /** STUBBED  **/
   iterator_t *newIterator = (iterator_t*) malloc(sizeof(iterator_t));
   newIterator->list = list;
   newIterator->position = list->head;

   return(newIterator);   // update this 
}

/**
   l_reset -- 
**/
void l_reset(iterator_t *iter) 
{
   /** STUBBED  **/ 
   iter->position = iter->list->head;
}

/** 
    l_hasnext -- returns 1 if the list is not empty; return 0 otherwise 
**/
int l_hasnext(iterator_t *iter) 
{
   /** STUBBED  **/
   if(iter->position == NULL)
      return 0;
   return 1;    // update this
}

/**
   l_getnext -- return a pointer the data and advance the position pointer
**/
void *l_getnext(iterator_t *iter) 
{
   /** STUBBED  **/
   if(l_hasnext(iter) == 0)
      return NULL;
   void *nextObj = iter->position->objPtr;
   iter->position = iter->position->next;
   return nextObj;     // update this
}

