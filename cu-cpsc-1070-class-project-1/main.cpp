
/*
  This program is for testing the Polynomial class.
*/

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <cstdlib>
#include "polynomial.h"

using namespace std;

int main(int argc, char *argv[])
{
    /*  veryify sufficient command-line arguments */
    assert(argc >= 2);

	ifstream  input;
    input.open(argv[1]);
    if(!input.is_open())
    {
       cout << "could not open " << argv[1] << ".  exiting. \n";
       exit(1);
    }

	double value;
	double x;

    /* instantiate polynomials  */
    Polynomial p1(input);
    Polynomial p2(input);
    Polynomial p3(input);
    Polynomial *p4 = new Polynomial(input);
    Polynomial p5;

    // print each polynomial
    p1.print();
    cout << endl;
    p2.print();
    cout << endl;
    p3.print();
    cout << endl;
    p4->print();
    cout << endl;

	// // test the add method
	// p5 = p1.add(p2);
	// cout << "p1 + p2 =  ";
  //   p5.print ( );
  //   cout << endl;
  //
	// //  test the subtract method and the getDegree method
	// p5 = p1.subtract(p2);
	// cout << "p1 - p2 =  ";
  //   p5.print();
  //   cout << endl;
  //
    cout <<  "The degree of p2 is " << p2.getDegree( ) << endl;
  //
	// // test the evaluate method
	// x = 3.0;
	// value = p3.evaluate (x);
	// cout <<  "p3(" <<  x  << ") = " << value << endl;

    return 0;
}
