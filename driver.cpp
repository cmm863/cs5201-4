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

    // Output matrix
    cout << matrix;
  }

  return 0;
}