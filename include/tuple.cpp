#include <iostream>
#include "tuple.h"

// getters

float Tuple::GetX()
{
    return this->x;
}

float Tuple::GetY()
{
    return this->y;
}

float Tuple::GetZ()
{
    return this->z;
}

float Tuple::GetW() 
{
    return this->w;
}

// setters

void Tuple::SetX(float newX)
{
    this->x = newX;
}

void Tuple::SetY(float newY)
{
    this->y = newY;
}

void Tuple::SetZ(float newZ)
{
    this->z = newZ;
}

void Tuple::SetW(float newW)
{
    this->w = newW;
}

// utils

bool Tuple::IsPoint()
{
    if (this->w == 1)
    {
        return true;
    }
    return false;
}

Tuple Tuple::Point(float x, float y, float z)
{
    Tuple tuple(x, y, z, 1);
    return tuple;
}

Tuple Tuple::Vector(float x, float y, float z)
{
    Tuple tuple(x, y, z, 0);
    return tuple;
}

bool Tuple::operator==(const Tuple &rhs)
{
    return false;
}

Tuple Tuple::operator+(const Tuple &rhs)
{
    Tuple tuple;
    return tuple;
}
Tuple Tuple::operator-(const Tuple &rhs)
{
    Tuple tuple;
    return tuple;
}

Tuple Tuple::operator-() {
    Tuple tuple;
    return tuple;
}

Tuple Tuple::operator*(const float rhs)
{
    Tuple tuple;
    return tuple;
}

Tuple Tuple::operator/(const float rhs) {
    Tuple tuple;
    return tuple;
}