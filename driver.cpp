#include <iostream>
#include <fstream>
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
  int num_rows, num_columns;
  GaussianSolver gs;

  // Start going through file
  if(inputFile.is_open())
  {
    // Take in size
    inputFile >> num_rows >> num_columns;

    // Create matrix
    MathMatrix<double> matrix(num_rows, num_columns);
    MathMatrix<double> matrix_b(3, 1);

    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 1; j++)
      {
        matrix_b[i].push(1);
      }
    }

    // Load matrix
    inputFile >> matrix;

    // Output matrix
    cout << matrix << endl;
    
    MathVector<double> x = gs(matrix, matrix_b);
    cout << x << endl;
  }

  return 0;
}