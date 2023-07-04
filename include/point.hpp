#include "tuple.hpp"

#ifndef POINT_HPP
#define POINT_HPP

class Point : public Tuple
{
public:
    Point(){}
    Point(float x, float y, float z)
    {
        this->SetX(x);
        this->SetY(y);
        this->SetZ(z);
        this->SetW(1);
    }
};

#endif