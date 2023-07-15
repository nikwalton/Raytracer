#include "tuple.hpp"
#ifndef VECTOR_HPP
#define VECTOR_HPP

class Vector : public Tuple
{
public:
    Vector(){}
    Vector(float x, float y, float z)
    {
        this->SetX(x);
        this->SetY(y);
        this->SetZ(z);
    }
};

#endif