/*
   Lukas Herman (lukash)
   CPSC 1070 
   Lab 7
   odomoter.h
 
   This is a test suit for testing all classes and functions.
*/

#include <iostream>  
#include <string>
#include "odometer.h"

using namespace std;

int main(int argc, char *argv[]) 
{

   Odometer car1;   // note the absence of the parentheses
   Odometer car2(75000);
   Odometer *car3 = new Odometer(25000);

   cout << "car1 ";
   car1.print();
   cout << "car2 ";
   car2.print();
   cout << "car3 ";
   car3->print();

   /**   ADD CODE TO TEST ALL OTHER METHODS OF THE CLASS  
         In particular:
           - set the miles to 50000 for car1
           -  add 1 to the miles traveled for car2
           - subtract 1 form the miles traveled for car3
           - print the info for each car
           - use cout to print the miles for
             car2 by invoking the getMiles() method.
           - declare a string for the warranty info for car2,
             assign the string returned by warrantyInfo() to 
             the string you declared, and use cout to
             print the string, followed by a newline. e.g.
                Warranty for car2:  warranty-string
           - use cout to print the warranty info
             for car3 with the same label; however, invoke
             the warrantyInfo() method instead of first assigning
             the warranty information to a string.  Warranty
             information should be followed by a newline.
           - make sure that your code tests all warranty categories,
             even if you have to create additional cars.
   **/
   car1.setMiles(50000);
   car2.increment();
   car3->decrement();
   
   cout << "car1 "; car1.print();
   cout << "car2 "; car2.print();
   cout << "car3 "; car3->print();
   
   cout << "car2 miles traveled: " << car2.getMiles() << endl;

   string car2Info = car2.warrantyInfo();
   cout << "Warranty info for car2: " << car2Info << endl;

   cout << "Warranty info for car3: " << car3->warrantyInfo() << endl;

   /* Custom cases */
   car3->setMiles(100000);
   cout << car3->warrantyInfo() << endl;

   car3->setMiles(99999);
   cout << car3->warrantyInfo() << endl;

   car3->setMiles(74999);
   cout << car3->warrantyInfo() << endl;

   car3->setMiles(25000);
   cout << car3->warrantyInfo() << endl;

   car3->setMiles(-292);
   cout << car3->warrantyInfo() << endl;

   return 0;
}
