//
// Created by Connor McBride on 2/28/16.
//

#ifndef MATHMATRIX_HPP
#define MATHMATRIX_HPP

#include <iostream>
#include "mathmatrix.h"
#include "mathvector.h"

using namespace std;

template <typename T>
MathMatrix<T>::MathMatrix()
{
  this->m_columns = 2;
  this->m_rows = 2;
  this->m_vectors = new MathVector<T>[this->m_rows];
}

template <typename T>
MathMatrix<T>::MathMatrix(unsigned long m, unsigned long n)
{
  this->m_rows = m;
  this->m_columns = n;
  this->m_vectors = new MathVector<T>[this->m_rows];
}

template <typename T>
MathMatrix<T>::MathMatrix(const MathMatrix<T>& other)
{
  // Standard sets
  this->m_columns = other.m_columns;
  this->m_rows = other.m_rows;

  // Set vectors equal
  this->m_vectors = new MathVector<T>[this->m_rows];
  for(unsigned long i = 0; i < this->m_rows; i++)
  {
    this->m_vectors[i] = other.m_vectors[i];
  }
}

template <typename T>
MathMatrix<T>::MathMatrix(MathMatrix<T>&& other)
{
  this->m_rows = other.m_rows;
  this->m_columns = other.m_columns;
  this->m_vectors = other.m_vectors;
  other.m_vectors = nullptr;
}

template <typename T>
MathMatrix<T>::~MathMatrix()
{
  delete[] this->m_vectors;
}

template <typename T>
unsigned long MathMatrix<T>::rows() const
{
  return this->m_rows;
}

template <typename T>
unsigned long MathMatrix<T>::columns() const
{
  return this->m_columns;
}

template <typename T>
MathVector<T>& MathMatrix<T>::operator[](unsigned long index)
{
  if(index < 0 || index >= this->m_rows)
  {
    cerr << "Out of Range" << endl;
  }
  return this->m_vectors[index];
}

template <typename T>
MathMatrix<T>& MathMatrix<T>::operator =(MathMatrix<T> other)
{
  mm_swap(*this, other);

  return *this;
}

template <typename T>
void mm_swap(MathMatrix<T>& lhs, MathMatrix<T>& rhs)
{
  swap(lhs.m_rows, rhs.m_rows);
  swap(lhs.m_columns, rhs.m_columns);
  swap(lhs.m_vectors, rhs.m_vectors);
}

#endif //MATHMATRIX_HPP
