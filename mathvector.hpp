//
// Created by Connor McBride on 2/28/16.
//

#ifndef MATHVECTOR_HPP
#define MATHVECTOR_HPP

#include "mathvector.h"

template <typename T>
MathVector<T>::MathVector()
{
  this->m_size = 0;
  this->m_capacity = 10;
}

template <typename T>
unsigned long MathVector<T>::size() const
{
  return this->m_size;
}

template <typename T>
unsigned long MathVector<T>::capacity() const
{
  return this->m_capacity;
}

#endif //MATHVECTOR_HPP
