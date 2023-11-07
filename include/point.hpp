#pragma once
#include "tuple.hpp"


class Point : public Tuple
{
public:
  Point() {}
  Point(float x, float y, float z)
  {
    this->SetX(x);
    this->SetY(y);
    this->SetZ(z);
    this->SetW(1);
  }
};
