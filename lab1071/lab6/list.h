/** list.h  **/
#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/** 
   List node  
**/
typedef struct node_type
{
   void *objPtr;             /* Pointer to associated object  */
   struct node_type *next;   /* Pointer to next node          */
} node_t;

typedef struct list_type
{
   node_t *head;             /* Head of list pointer          */
} list_t;

/** 
    Iterator 
**/
typedef struct list_iterator
{
   list_t *list;             /* List iterator is associated with  */
   node_t *position;         /* Current position in list          */
} iterator_t;

/** Function prototypes **/
list_t *newList();                 /* Create and initialize list object */
void   l_add(list_t *list, void *objPtr); /*add to the head of thelist  */


iterator_t *newIterator(list_t *list);
void   l_reset(iterator_t *iter);       /* Reset current to front of list   */
void   *l_getnext(iterator_t *iter);    /* Get object from list             */
int    l_hasnext(iterator_t *iter);     /* Test if at end of list           */

#endif
