//
// Created by Connor McBride on 2/28/16.
//

#ifndef MATHVECTOR_H
#define MATHVECTOR_H

template <typename T>
class MathVector;

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
  MathVector(const MathVector& other); // Rule of 3
  MathVector(MathVector&& other); // Rule of 4 1/2
  ~MathVector(); // Rule of 3

  // Helpers
  unsigned long size() const;
  unsigned long capacity() const;

  // Functions
  void push(T element);

  // Operators
  T& operator [](int index);
  MathVector& operator =(MathVector other); // Rule of 3

  // Friends
  friend void mv_swap <>(MathVector& lhs, MathVector& rhs); // Rule of 3 1/2
};

#include "mathvector.hpp"

#endif // MATHVECTOR_H
