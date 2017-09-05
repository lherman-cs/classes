/** listtest.c  lab 6 **/
/**
 * Lukas Herman (lukash)
 * CPSC1071-001
 * #6
 * 02/26/2017
 * This program is just a test for the linked list
 */


/** Test program for CPSC 1071 lab 6 **/
#include "list.h"

typedef struct vehicle_type 
{
   int vin;
   char *make;
   char *model;
   int year;
} veh_t;

int main() 
{
   int data[] = {5, 10, 15, 20, 25};
 
   char *fruit[] = {"apple", "orange", "peach", "banana"};

   veh_t vehicles[] = { {23456, "Ford", "Mustang", 2009},
                        {32168, "Honda", "Accord", 2010},
                        {32565, "Toyota", "Camry", 2010},
                        {15677, "Jeep", "Cherokee", 2004},
                        {34257, "Chevrolet", "Impala", 2007},
                        {54387, "Nissan", "Altima", 2006},
                        {34577, "Dodge", "Caravan", 2003}};

   int index;
   int size;

   int   *ptr1;
   char  *ptr2;
   veh_t *ptr3;

   list_t *list1;
   list_t *list2;
   list_t *list3;

   iterator_t *iter1;
   iterator_t *iter2;
   iterator_t *iter3;
                        
   /** Create the lists **/
   list1 = newList();
   list2 = newList();
   list3 = newList();

   /*  Populate the lists  */
   size = sizeof(data)/sizeof(int);
   for(index = 0; index < size; index++) 
   {
      l_add(list1, &data[index]);
   }

   size = sizeof(fruit)/sizeof(char *);
   for(index = 0; index < size; index++) 
   {
      l_add(list2, fruit[index]);
   }
   
   size = sizeof(vehicles)/sizeof(veh_t);
   for(index = 0; index < size; index++) 
   {
      l_add(list3, &vehicles[index]);
   }

   /** Retrieve data from lists **/
   fprintf(stdout, "\nList 1: ");
   iter1 = newIterator(list1);
   while(l_hasnext(iter1)) 
   {
      ptr1 = l_getnext(iter1);
      fprintf(stdout, "%d, ", *ptr1);
   }
   fprintf(stdout, "\n\n");
   fprintf(stdout, "\nTest l_reset() function: ");
   l_reset(iter1);
   ptr1 = l_getnext(iter1);
   fprintf(stdout, "First value = %d\n", *ptr1);

   fprintf(stdout, "\nList 2: ");
   /** STUBBED **/
   iter2 = newIterator(list2);
   while(l_hasnext(iter2)){
      ptr2 = l_getnext(iter2);
      fprintf(stdout, "%s, ", ptr2);
   }
    
   fprintf(stdout, "\n\n");

   fprintf(stdout, "\nList 3:\n");
   /** STUBBED **/
   iter3 = newIterator(list3);
   while(l_hasnext(iter3)){
      ptr3 = l_getnext(iter3);
      fprintf(stdout, "   [%d %s %s %d],\n", 
              ptr3->vin, ptr3->make, ptr3->model, ptr3->year);
   }

   fprintf(stdout, "\n");

   return 0;
}
