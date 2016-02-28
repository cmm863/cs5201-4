//
// Created by Connor McBride on 2/28/16.
//

#ifndef MATHVECTOR_HPP
#define MATHVECTOR_HPP

#include "mathvector.h"
#include <iostream>


using namespace std;

template <typename T>
MathVector<T>::MathVector()
{
  this->m_size = 0;
  this->m_capacity = 10;
  this->m_elements = new T[this->m_capacity]();
}

template <typename T>
MathVector<T>::MathVector(unsigned long capacity)
{
  this->m_size = 0;
  this->m_capacity = capacity;
  this->m_elements = new T[this->m_capacity];
}

template <typename T>
MathVector<T>::MathVector(const MathVector& other)
{
  // Standard sets
  this->m_size = other.m_size;
  this->m_capacity = other.m_capacity;

  // Set arrays equal
  this->m_elements = new T[this->m_capacity]();
  for(unsigned long i = 0; i < this->m_size; i++)
  {
    this->m_elements[i] = other.m_elements[i];
  }
}

template <typename T>
MathVector<T>::MathVector(MathVector<T> &&other)
{
  this->m_size = other.m_size;
  this->m_capacity = other.m_capacity;
  this->m_elements = other.m_elements;
  other.m_elements = nullptr;
}

template <typename T>
MathVector<T>::~MathVector()
{
  delete[] this->m_elements;
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

template <typename T>
void MathVector<T>::push(T element)
{
  if(this->m_size == this->m_capacity)
  {
    // Create temp ptr
    T * temp = nullptr;

    // Increase capacity
    this->m_capacity *= 2;

    // Allocate new size & old data to temp ptr
    temp = new T[this->m_capacity]();
    for(unsigned long i = 0; i < this->m_size; i++)
    {
      temp[i] = this->m_elements[i];
    }

    // Delete old data
    delete [] this->m_elements;

    // Swap ptr
    this->m_elements = nullptr;
    swap(this->m_elements, temp);
  }

  // Add element
  this->m_elements[this->m_size] = element;
  this->m_size++;
}

template <typename T>
T& MathVector<T>::operator[](int index)
{
  if(index < 0 || index >= this->m_size)
  {
    cerr << "Out of Range" << endl;
  }
  return this->m_elements[index];
}

template <typename T>
MathVector<T>& MathVector<T>::operator =(MathVector<T> other)
{
  mv_swap(*this, other);

  return *this;
}

template <typename T>
MathVector<T>& MathVector<T>::operator +=(const MathVector<T> &rhs)
{
  if(this->m_size != rhs.m_size)
  {
    cerr << "Sizes not equal + operator" << endl;
  }
  for(unsigned long i = 0; i < this->m_size; i++)
  {
    this->m_elements[i] += rhs.m_elements[i];
  }

  return *this;
}

template <typename T>
MathVector<T> operator +(const MathVector<T> &lhs, const MathVector<T> &rhs)
{
  MathVector<T> ret(lhs);
  return ret += rhs;
}

template <typename T>
void mv_swap(MathVector<T>& lhs, MathVector<T>& rhs)
{
  swap(lhs.m_size, rhs.m_size);
  swap(lhs.m_capacity, rhs.m_capacity);
  swap(lhs.m_elements, rhs.m_elements);
}

#endif //MATHVECTOR_HPP
