//////////////////////////////////////////////////////////////////////
/// @file gaussian_solver.hpp
/// @author Connor McBride
/// @brief Contains the GaussianSolver class implementation information
//////////////////////////////////////////////////////////////////////

#ifndef GAUSSIAN_SOLVER_HPP
#define GAUSSIAN_SOLVER_HPP

#include "mathmatrix.h"
#include "mathvector.h"
#include <vector>
#include <cmath>

template <typename T>
MathVector<T> GaussianSolver::operator()(const MathMatrix<T>& m, const MathMatrix<T>& s)
{
  int n = m.rows();
  MathMatrix<T> A(n, n+1);

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n + 1; j++)
    {
      if(j == n)
      {
        A[i].push(s[i][0]);
      }
      else
      {
        A[i].push(m[i][j]);
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    T largest = abs(A[i][i]);
    int largestRow = i;
    for (int j = i+1; j < n; j++)
    {
      if (abs(A[j][i]) > largest)
      {
        largest = abs(A[j][i]);
        largestRow = j;
      }
    }

    for (int j = i; j < n+1; j++)
    {
      T tmp = A[largestRow][j];
      A[largestRow][j] = A[i][j];
      A[i][j] = tmp;
    }

    for (int j = i+1; j < n; j++)
    {
      T c = -A[j][i] / A[i][i];
      for (int k = i; k < n+1; k++)
      {
        if (i == k)
        {
          A[j][k] = 0;
        } else
        {
          A[j][k] += c * A[i][k];
        }
      }
    }
  }

  MathVector<T> x(n);
  for(unsigned long i = 0; i < x.capacity(); i++)
  {
    x.push(0);
  }

  for (int i = n-1; i >= 0; i--)
  {
    x[i] = A[i][n] / A[i][i];
    for (int j = i-1; j >= 0; j--)
    {
      A[j][n] -= A[j][i] * x[i];
    }
  }
  return x;
}

#endif //GAUSSIAN_SOLVER_HPP
