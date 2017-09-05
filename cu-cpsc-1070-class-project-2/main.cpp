#include <iostream>
#include <cassert>
#include <cstdlib>
#include "recursiveFun.h"

using namespace std;

int main(int argc, char *argv[]){
  assert(argc == 2);
  int n = atoi(argv[1]);
  if(bears(n))
    cout << n << ": True" << endl;
  else
    cout << n << ": False" << endl;

  return 0;
}
