#include <iostream>
#include "mathvector.h"
#include "mathmatrix.h"

using namespace std;

int main()
{
  MathMatrix<int> testMatrix(1, 2);
  cout << "m: " << testMatrix.rows() << endl;
  cout << "n: " << testMatrix.columns() << endl;
  testMatrix[0].push(4);
  MathMatrix<int> testM2;
  testM2 = testMatrix;
  cout << "Row 1: " << testM2[0] << endl;
  cout << "Row 1: " << testMatrix[0] << endl;
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
  cout << test3 - test << endl;
  test3[0] = 2;
  cout << test3 << endl;


  return 0;
}