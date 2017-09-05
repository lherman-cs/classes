/*
   Lukas Herman (lukash)
   CPSC 1070 
   Lab 7
   odomoter.h

   This is just a header for Odometer class.
*/

#include <string>

using namespace std;

class Odometer
{
  public:
    
    Odometer();                 // default constructor
    Odometer(int initialMiles); // constructor 
    ~Odometer();                // destructor

   // public methods
   void setMiles(int initialMiles); 
   int getMiles();      
   void increment();
   void decrement();
   string warrantyInfo();
   void print();

  private:
    int miles;
};
