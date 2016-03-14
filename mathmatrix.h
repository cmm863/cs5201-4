//////////////////////////////////////////////////////////////////////
/// @file mathmatrix.h
/// @author Connor McBride
/// @brief Contains the declaration information for the MathMatrix class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class MathMatrix
/// @brief Is a template class that is a container for a matrix.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn MathMatrix<T>::MathMatrix()
/// @brief Explicit definition of the default constructor.
/// @pre None
/// @post A MathMatrix class of type T is created with m_size 0
/// @return Returns MathMatrix object instantiated
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn MathMatrix<T>::MathMatrix(unsigned long m, unsigned long n)
/// @brief Overload of constructor which takes an ints for size
/// @pre None
/// @post A MathMatrix class of type T is created with m, n size
/// @return Returns MathMatrix object instantiated
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn MathMatrix<T>::~MathMatrix()
/// @brief Overload of the destructor
/// @pre None.
/// @post All m_vectors of the calling object are cleared.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn unsigned long T::rows() const
/// @brief Get function for m_rows.
/// @pre None.
/// @post Returns rows num of MathMatrix.
/// @return Returns m_rows of the called object.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn unsigned long T::columns() const
/// @brief Get function for m_columns.
/// @pre None.
/// @post Returns num columns of MathMatrix.
/// @return Returns m_columns of the called object.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn MathVector MathMatrix<T>::operator [](int index) const
/// @brief Returns a returns element at passed index.
/// @pre Index needs to be less than the number of elements.
/// @post Returns a returns element at passed index.
/// @param1 Index of the term to be returned.
/// @return Returns a returns element at passed index.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn friend MathMatrix<T> operator +(const MathMatrix<T>& lhs, const MathMatrix<T>& rhs)
/// @brief Adds two MathMatrixs together.
/// @pre MathMatrix need to be of the same size. T type must have += operator.
/// @post Returns sum of lhs and rhs
/// @param1 MathMatrix 1 to be added
/// @param2 MathMatrix 2 to be added
/// @return Sum of lhs and rhs
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn friend MathMatrix<T> operator -(const MathMatrix<T>& lhs, const MathMatrix<T>& rhs)
/// @brief Subtracts rhs MathMatrix from lhs.
/// @pre MathMatrixs need to be of the same size. T type must have -= operator.
/// @post Returns difference of lhs and rhs
/// @param1 MathMatrix 1 to be subracted from
/// @param2 MathMatrix 2 to be subracted
/// @return Difference of lhs and rhs
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn friend T operator *(const MathMatrix<T>& lhs, const MathMatrix<T>& rhs)
/// @brief Dot product of rhs and lhs.
/// @pre T needs to have += operator and * operator.
/// @post Return dot product of rhs & lhs.
/// @param1 MathMatrix 1
/// @param2 MathMatrix 2
/// @return Dot of rhs from lhs
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn friend MathMatrix<T> operator *(double c, const MathMatrix<T>& rhs)
/// @brief Multiplication c by each element of rhs.
/// @pre T type must have *= operator.
/// @post Returns rhs with each element multiplied by c
/// @param1 constant c to be multiplied
/// @param2 MathMatrix to be scaled
/// @return Rhs with each element multiplied by c
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn ostream& operator <<(ostream& out, const MathMatrix<T>& rhs)
/// @brief Outputs rhs to ostream.
/// @pre None.
/// @post ostream is appended with information on rhs.
/// @param1 ostream operator to be changed.
/// @param2 MathMatrix whose info is to be output.
/// @return ostream& with debug string for MathMatrix information added to the stream.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn istream& operator >>(istream& in, MathMatrix<T>& rhs)
/// @brief Takes in istream and fills MathMatrix.
/// @pre None.
/// @post Rhs is filled with appropriate information. istream in gets returned.
/// @param1 istream operator to be returned.
/// @param2 MathMatrix whose info is to be input.
/// @return istream& in.
//////////////////////////////////////////////////////////////////////

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
