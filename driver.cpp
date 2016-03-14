#include <iostream>
#include <fstream>
#include <cmath>
#include "mathvector.h"
#include "mathmatrix.h"
#include "gaussian_solver.h"

using namespace std;

int main(int argc, char* argv[])
{
  // If no file from arg commands
  if(argc < 2)
  {
    cout << "No file given." << endl;
    return 1;
  }

  // Declare variables
  ifstream inputFile(argv[1]);
  int matrix_size;
  GaussianSolver gs;
  long double temp_x, temp_y;

  // Start going through file
  if(inputFile.is_open())
  {
    // Take in size
    inputFile >> matrix_size;
    cout << matrix_size << endl;

    // Create matrix
    MathMatrix<long double> X(matrix_size, matrix_size);
    MathMatrix<long double> Y(matrix_size, 1);

    for(int i = 0; i < matrix_size; i++)
    {
      // load x
      inputFile >> temp_x;
      // load y
      inputFile >> temp_y;
      Y[i].push(temp_y);
      for(int j = 0; j < matrix_size; j++)
      {
        X[i].push(pow(temp_x, j));
      }
    }

    // Output matrix
    cout << X << endl;
    cout << X.transpose() << endl << endl;
    cout << X * X.transpose() << endl << endl;
    cout << endl << Y << endl;

    MathVector<long double> a = gs(X, Y);
    cout << a << endl;
  }

  return 0;
}