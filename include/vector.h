#include "tuple.h"
#ifndef VECTOR_H
#define VECTOR_H

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