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
  cout << test2 * test << endl;
  MathVector<int> test3 = MathVector<int>(2);
  for(int i = 0; i < 10; i++)
  {
    test3.push(i);
  }
  cout << test2 << endl;
  cout << "Size: " << test3.size() << endl;
  cout << "Capacity: " << test3.capacity() << endl;
  cout << test3 << endl;
  test3 = test2 + test;
  cout << "Size: " << test3.size() << endl;
  cout << "Capacity: " << test3.capacity() << endl;
  cout << test3 << endl;
  test3 = 3 * test3;
  cout << test3 << endl;
  test3[0] = 2;
  cout << test3 << endl;


  return 0;
}