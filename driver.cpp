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
  MathVector<int> test3 = MathVector<int>(2);
  for(int i = 0; i < 10; i++)
  {
    test3.push(i);
  }
  cout << "Hello, World!" << endl;
  for(unsigned long i = 0; i < test2.size(); i++)
  {
    cout << test2[i] << endl;
  }
  cout << "Size: " << test3.size() << endl;
  cout << "Capacity: " << test3.capacity() << endl;
  for(unsigned long i = 0; i < test3.size(); i++)
  {
    cout << test3[i] << endl;
  }
  test3 = test2 + test;
  cout << "Size: " << test3.size() << endl;
  cout << "Capacity: " << test3.capacity() << endl;
  for(unsigned long i = 0; i < test3.size(); i++)
  {
    cout << test3[i] << endl;
  }


  return 0;
}