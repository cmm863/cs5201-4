//////////////////////////////////////////////////////////////////////
/// @file driver.cpp
/// @author Connor McBride
/// @brief Main class file for Assignment 4 CS5201
//////////////////////////////////////////////////////////////////////

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
    cout << "Vandermonde Matrix" << endl << endl;
    cout << X << endl;
    cout << endl << "A transpose: " << endl;
    cout << X.transpose() << endl << endl;
    cout << "Vandermonde times its transpose" << endl;
    cout << X * X.transpose() << endl << endl;

    cout << "Using partial pivoting" << endl;
    MathVector<long double> a = gs(X, Y);
    cout << "< " << a << " >" << endl;
  }

  return 0;
}