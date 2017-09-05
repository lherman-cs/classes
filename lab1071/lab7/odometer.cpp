/*
   Lukas Herman (lukash)
   CPSC 1070
   Lab 7
   odomoter.h

   These contain class functions and constructors.
*/

#include <iostream>
#include <string>
#include "odometer.h"

using namespace std;

/**
  The default constructor and the destructor have been
  implemented for you.  You must implement all other methods.
  Be sure to use the scope resolution operator ::
**/

// Default constructor
Odometer::Odometer()
{
   miles = 0;
}

// Parameterized constructor
Odometer::Odometer(int initialMiles)
{
   miles = initialMiles;
}

// destructor
Odometer::~Odometer()
{
   cout << "In the destructor.\n";
}

// Set miles to initialMiles
void Odometer::setMiles(int initialMiles)
{
   miles = initialMiles;
}

// Get miles value and return it
int Odometer::getMiles()
{
   return miles;
}

// Increase miles value by 1
void Odometer::increment()
{
   miles++;
}

// Decrease miles value by 1
void Odometer::decrement()
{
   miles--;
}

// Return the warranty info based on miles traveled
string Odometer::warrantyInfo()
{
   /*  declare a string using the keyword "string".
       you can assign a quoted string to the string variable
       e.g.
       string  str;
       str = "Go Tigers";
   */
   string info;
   if(miles >= 100000)
      info = "All warranties expired";
   else if(miles >= 75000)
      info = "Warranty valid: A/C";
   else if(miles >= 50000)
      info = "Warranties valid: A/C, body, brakes";
   else if(miles >= 25000)
      info = "Warranties valid: A/C, body, brakes, electric, paint, abs";
   else
      info = "All parts under warranty";
   return info;
}

// Print the number of miles traveled
void Odometer::print()
{
   cout << "miles traveled: " << miles << endl;
}
