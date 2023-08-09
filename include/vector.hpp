#include "tuple.hpp"
#pragma once

class Vector : public Tuple
{
public:
    Vector(){}
    Vector(float x, float y, float z)
    {
        this->SetX(x);
        this->SetY(y);
        this->SetZ(z);
        this->SetW(0);
    }
};
