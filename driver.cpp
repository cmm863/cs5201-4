#include <iostream>
#include "mathvector.h"

using namespace std;

int main()
{
  MathVector<int> test;
  test.push(5);
  test.push(7);
  MathVector<int> test2;
  test2 = test;
  cout << "Hello, World!" << endl;
  for(unsigned long i = 0; i < test2.size(); i++)
  {
    cout << test2[i] << endl;
  }


  return 0;
}