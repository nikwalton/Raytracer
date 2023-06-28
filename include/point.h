#include "tuple.h"

#ifndef POINT_H
#define POINT_H

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