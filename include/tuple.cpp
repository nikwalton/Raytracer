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
    if (this->x == rhs.x &&this->y == rhs.y &&this->z == rhs.z && this->w == rhs.w)
    {
        return true;
    }
    return false;
}

Tuple Tuple::operator+(const Tuple &rhs)
{
    Tuple tuple;

    tuple.SetX(this->x + rhs.x);
    tuple.SetY(this->y + rhs.y);
    tuple.SetZ(this->z + rhs.z);
    tuple.SetW(this->w + rhs.w);

    return tuple;
}
Tuple Tuple::operator-(const Tuple &rhs)
{
    Tuple tuple;

    //two points subtracted makes a vector
    if (this->w == 1 && rhs.w == 1) 
    {
        tuple.SetX(this->x - rhs.x);
        tuple.SetY(this->y - rhs.y);
        tuple.SetZ(this->z - rhs.z);
        tuple.SetW(0); // vector
        return tuple;
    }
    //vector subtracted from a point makes a point
    else if (this-> w == 1 && rhs.w == 0) 
    {
        tuple.SetX(this->x - rhs.x);
        tuple.SetY(this->y - rhs.y);
        tuple.SetZ(this->z - rhs.z);
        tuple.SetW(1); // point
        return tuple;
    }

    //if above cases arent there (w isnt 1 or 0), just subtract everything as usual
    tuple.SetX(this->x - rhs.x);
    tuple.SetY(this->y - rhs.y);
    tuple.SetZ(this->z - rhs.z);
    tuple.SetW(this->w - rhs.w);
    return tuple;
}

Tuple Tuple::operator-() {
    Tuple tuple;

    tuple.SetX(-1 * this->x);
    tuple.SetY(-1 * this->y);
    tuple.SetZ(-1 * this->z);
    tuple.SetW(-1 * this->w);
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

float Tuple::Magnitude ()
{
    return 0.0;
}

Tuple Tuple::Normalize()
{
    Tuple returnTuple;
    return returnTuple;
}

float Tuple::Dot(Tuple tupleB)
{
    return 0.0;
}

Tuple Tuple::Cross(Tuple tupleB)
{
    Tuple returnTuple;
    return returnTuple;
}
