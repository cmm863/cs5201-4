//////////////////////////////////////////////////////////////////////
/// @file gaussian_solver.h
/// @author Connor McBride
/// @brief Contains the declaration information for the GaussianSolver class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class GaussianSolver
/// @brief Is a function class to implement Gaussian Solution
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Matrix<T> operator ()(const MathMatrix<T>& m, const MathMatrix<T>& s)
/// @brief Overloads the () operator to act as a function class.
/// @pre Matrix m needs to have a valid solution with matrix s
/// @post Returns MathVector of solutions
/// @param m holds the reference of a MathMatrix with type T << the square matrix A in Ax = b
/// @param s holds the reference of a MathMatrix with type T << the b matrix in Ax = b
/// @return Returns the solution of Ax = b
//////////////////////////////////////////////////////////////////////

#ifndef GAUSSIAN_SOLVER_H
#define GAUSSIAN_SOLVER_H

#include "mathmatrix.h"
#include <vector>

class GaussianSolver
{
public:
  template <typename T>
  MathVector<T> operator ()(const MathMatrix<T>& m, const MathMatrix<T>& s);
};

#include "gaussian_solver.hpp"

#endif //GAUSSIAN_SOLVER_H
