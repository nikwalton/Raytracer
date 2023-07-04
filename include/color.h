#include "tuple.h"

#ifndef COLOR_H
#define COLOR_H

class Color : public Tuple
{
public:
    Color(){}
    Color(float r, float g, float b);

    float GetRed();
    float GetGreen();
    float GetBlue();

    void SetRed(float newR);
    void SetGreen(float newG);
    void SetBlue(float newB);

    Color operator*(Color &rhs);
    Tuple operator*(const float rhs);
};

#endif