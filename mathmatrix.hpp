//
// Created by Connor McBride on 2/28/16.
//

#ifndef MATHMATRIX_HPP
#define MATHMATRIX_HPP

#include <iostream>
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
void MathMatrix<T>::addRow(MathVector<T> row)
{
  // Create temp ptr
  MathVector<T> * temp = nullptr;

  // Increase rows
  this->m_rows++;

  // Allocate new size & old data to temp ptr
  temp = new MathVector<T>[this->m_rows];
  for(unsigned long i = 0; i < this->m_rows - 1; i++)
  {
    temp[i] = this->m_vectors[i];
  }

  // Delete old data
  delete [] this->m_vectors;

  // Swap ptr
  this->m_vectors = nullptr;
  swap(this->m_vectors, temp);

  // Add element
  this->m_vectors[this->m_rows - 1] = row;
}

template <typename T>
MathMatrix<T> MathMatrix<T>::transpose()
{
  MathMatrix m(this->m_columns, this->m_rows);
  for(unsigned long i = 0; i < m.m_rows; i++)
  {
    for(unsigned long j = 0; j < m.m_columns; j++)
    {
      m[i].push((*this)[j][i]);
    }
  }

  return m;
}

template <typename T>
MathVector<T>& MathMatrix<T>::operator[](unsigned long index) const
{
  if(index < 0 || index >= this->m_rows)
  {
    cerr << "Out of Range" << endl;
  }
  return this->m_vectors[index];
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
MathMatrix<T>& MathMatrix<T>::operator +=(const MathMatrix<T>& rhs)
{
  if(this->m_columns != rhs.m_columns || this->m_rows != rhs.m_rows)
  {
    cerr << "Sizes not equal" << endl;
  }
  for(unsigned long i = 0; i < this->m_rows; i++)
  {
    (*this)[i] += rhs[i];
  }

  return (*this);
}

template <typename T>
MathMatrix<T>& MathMatrix<T>::operator-=(const MathMatrix<T>& rhs)
{
  return (*this) += -1 * rhs;
}

template <typename T>
MathMatrix<T> operator +(const MathMatrix<T>& lhs, const MathMatrix<T>& rhs)
{
  MathMatrix<T> m(lhs);
  return m += rhs;
}

template <typename T>
MathMatrix<T> operator -(const MathMatrix<T>& lhs, const MathMatrix<T>& rhs)
{
  MathMatrix<T> m(lhs);
  return m -= rhs;
}

template <typename T>
MathMatrix<T> operator *(double c, const MathMatrix<T>& rhs)
{
  MathMatrix<T> m(rhs);
  for(unsigned long i = 0; i < m.rows(); i++)
  {
    m[i] = c * m[i];
  }

  return m;
}

template <typename T>
MathMatrix<T> operator *(const MathMatrix<T>& lhs, const MathMatrix<T>& rhs)
{
  MathMatrix<T> m(lhs.m_rows, rhs.m_columns);
  for(unsigned long i = 0; i < m.m_rows; i++)
  {
    for(unsigned long j = 0; j < m.m_columns; j++)
    {
      m[i].push(0);
    }
  }

  for(unsigned long i = 0; i < m.m_rows; i++)
  {
    for(unsigned long j = 0; j < m.m_columns; j++)
    {
      for(unsigned long k = 0; k < lhs.m_columns; k++)
      {
        m[i][j] += lhs[i][k] * rhs[k][j];
      }
    }
  }

  return m;
}

template <typename T>
void mm_swap(MathMatrix<T>& lhs, MathMatrix<T>& rhs)
{
  swap(lhs.m_rows, rhs.m_rows);
  swap(lhs.m_columns, rhs.m_columns);
  swap(lhs.m_vectors, rhs.m_vectors);
}

template <typename T>
ostream& operator <<(ostream& out, const MathMatrix<T>& rhs)
{
  for(unsigned long i = 0; i < rhs.m_rows; i++)
  {
    for(unsigned long j = 0; j < rhs.m_columns; j++)
    {
      out << rhs[i][j] << " ";
    }
    if(i < rhs.m_rows - 1)
    {
      out << endl;
    }
  }

  return out;
}

template <typename T>
istream& operator >>(istream& in, MathMatrix<T>& rhs)
{
  T temp;
  for(unsigned long i = 0; i < rhs.m_rows; i++)
  {
    for(unsigned long j = 0; j < rhs.m_columns; j++)
    {
      in >> temp;
      rhs[i].push(temp);
    }
  }

  return in;
}

#endif //MATHMATRIX_HPP
