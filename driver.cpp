#include <iostream>
#include <fstream>
#include "mathvector.h"
#include "mathmatrix.h"

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

  // Start going through file
  if(inputFile.is_open())
  {
    // Take in size
    inputFile >> num_rows >> num_columns;

    // Create matrix
    MathMatrix<double> matrix(num_rows, num_columns);

    // Load matrix
    inputFile >> matrix;

    MathMatrix<double> matrixTwo(num_rows, num_columns);
    for(int i = 0; i < num_rows; i++)
    {
      for(int j = 0; j < num_columns; j++)
      {
        matrixTwo[i].push(i + j);
      }
    }

    // Output matrix
    cout << matrix << endl;
    cout << matrixTwo << endl;
    cout << matrix + matrixTwo << endl;
    cout << 2 * matrix << endl;
  }

  return 0;
}