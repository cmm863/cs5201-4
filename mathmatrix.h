//
// Created by Connor McBride on 2/28/16.
//

#ifndef MATHMATRIX_H
#define MATHMATRIX_H

#include <iostream>
#include "mathvector.h"

using namespace std;

template <typename T>
class MathMatrix;

template <typename T>
MathMatrix<T> operator +(const MathMatrix<T>& lhs, const MathMatrix<T>& rhs);

template <typename T>
MathMatrix<T> operator -(const MathMatrix<T>& lhs, const MathMatrix<T>& rhs);

template <typename T>
MathMatrix<T> operator *(double c, const MathMatrix<T>& rhs);

template <typename T>
MathMatrix<T> operator *(const MathMatrix<T>& lhs, const MathMatrix<T>& rhs);

template <typename T>
void mm_swap(MathMatrix<T>& lhs, MathMatrix<T>& rhs);

template <typename T>
ostream& operator <<(ostream& out, const MathMatrix<T>& rhs);

template <typename T>
istream& operator >>(istream& in, MathMatrix<T>& rhs);

template <typename T>
class MathMatrix
{
private:
  MathVector<T> * m_vectors;
  unsigned long m_rows;
  unsigned long m_columns;
public:
  // Constructors
  MathMatrix();
  MathMatrix(unsigned long m, unsigned long n);
  MathMatrix(const MathMatrix& other); // Rule of 3
  MathMatrix(MathMatrix&& other); // Rule of 4 1/2
  ~MathMatrix(); // Rule of 3

  // Getters
  unsigned long rows() const;
  unsigned long columns() const;

  // Function
  void addRow(MathVector<T> row);
  MathMatrix<T> transpose();

  // Operators
  MathVector<T>& operator [](unsigned long index) const;
  MathVector<T>& operator [](unsigned long index);
  MathMatrix& operator =(MathMatrix other); // Rule of 3
  MathMatrix& operator +=(const MathMatrix& rhs);
  MathMatrix& operator -=(const MathMatrix& rhs);

  // Friends
  friend MathMatrix operator + <>(const MathMatrix& lhs, const MathMatrix& rhs);
  friend MathMatrix operator - <>(const MathMatrix& lhs, const MathMatrix& rhs);
  friend MathMatrix operator * <>(double c, const MathMatrix& rhs);
  friend MathMatrix operator * <>(const MathMatrix& lhs, const MathMatrix& rhs);
  friend void mm_swap <>(MathMatrix& lhs, MathMatrix& rhs); // Rule of 3 1/2
  friend ostream& operator << <>(ostream& out, const MathMatrix<T>& rhs);
  friend istream& operator >> <>(istream& in, MathMatrix<T>& rhs);
};

#include "mathmatrix.hpp"

#endif //MATHMATRIX_H
