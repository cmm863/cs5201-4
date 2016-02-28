//
// Created by Connor McBride on 2/28/16.
//

#ifndef MATHVECTOR_H
#define MATHVECTOR_H

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

  // Helpers
  unsigned long size() const;
  unsigned long capacity() const;
};

#include "mathvector.hpp"

#endif // MATHVECTOR_H
