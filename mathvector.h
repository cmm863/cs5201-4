//
// Created by Connor McBride on 2/28/16.
//

#ifndef MATHVECTOR_H
#define MATHVECTOR_H

#include <iostream>

using namespace std;

template <typename T>
class MathVector;

template <typename T>
MathVector<T> operator +(const MathVector<T>& lhs, const MathVector<T>& rhs);

template <typename T>
MathVector<T> operator *(double c, const MathVector<T>& rhs);

template <typename T>
T operator *(const MathVector<T>& lhs, const MathVector<T>& rhs);

template <typename T>
ostream& operator <<(ostream& out, const MathVector<T>& rhs);

template <typename T>
void mv_swap(MathVector<T>& lhs, MathVector<T>& rhs);


template <typename T>
class MathVector
{
private:
  T * m_elements;
  unsigned long m_size;
  unsigned long m_capacity;
public:
  // Constructors
  MathVector();
  MathVector(unsigned long capacity);
  MathVector(const MathVector& other); // Rule of 3
  MathVector(MathVector&& other); // Rule of 4 1/2
  ~MathVector(); // Rule of 3

  // Getters
  unsigned long size() const;
  unsigned long capacity() const;

  // Functions
  void push(T element);

  // Operators
  T& operator [](unsigned long index);
  MathVector& operator =(MathVector other); // Rule of 3
  MathVector& operator +=(const MathVector& rhs);
  friend MathVector operator + <>(const MathVector& lhs, const MathVector& rhs);
  friend MathVector operator * <>(double c, const MathVector& rhs);
  friend T operator * <>(const MathVector& lhs, const MathVector& rhs);
  friend ostream& operator << <>(ostream& out, const MathVector& rhs);

  // Friends
  friend void mv_swap <>(MathVector& lhs, MathVector& rhs); // Rule of 3 1/2
};

#include "mathvector.hpp"

#endif // MATHVECTOR_H
