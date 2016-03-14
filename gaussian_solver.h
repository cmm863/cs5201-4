//
// Created by Connor McBride on 3/14/16.
//

#ifndef GAUSSIAN_SOLVER_H
#define GAUSSIAN_SOLVER_H

#include "mathmatrix.h"
#include <vector>

class GaussianSolver
{
public:
  template <typename T>
  MathVector<T> operator ()(const MathMatrix<T> m, const MathMatrix<T> s);
};

#include "gaussian_solver.hpp"

#endif //GAUSSIAN_SOLVER_H
