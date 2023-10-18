#include <iostream>
#include <cmath>

#include "tuple.hpp"

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

bool Tuple::operator==(const Tuple& rhs)
{
  if (this->x == rhs.x && this->y == rhs.y && this->z == rhs.z && this->w == rhs.w)
  {
    return true;
  }
  return false;
}

Tuple Tuple::operator+(const Tuple& rhs)
{
  Tuple tuple;

  tuple.SetX(this->x + rhs.x);
  tuple.SetY(this->y + rhs.y);
  tuple.SetZ(this->z + rhs.z);
  tuple.SetW(this->w + rhs.w);

  return tuple;
}
Tuple Tuple::operator-(const Tuple& rhs)
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
  else if (this->w == 1 && rhs.w == 0)
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

  tuple.SetX(this->x * rhs);
  tuple.SetY(this->y * rhs);
  tuple.SetZ(this->z * rhs);
  tuple.SetW(this->w * rhs);

  return tuple;
}

Tuple Tuple::operator/(const float rhs) {
  Tuple tuple;

  tuple.SetX(this->x / rhs);
  tuple.SetY(this->y / rhs);
  tuple.SetZ(this->z / rhs);
  tuple.SetW(this->w / rhs);

  return tuple;
}

float Tuple::Magnitude()
{
  return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

Tuple Tuple::Normalize()
{
  Tuple tuple;
  float mag = this->Magnitude();

  tuple.SetX(this->x / mag);
  tuple.SetY(this->y / mag);
  tuple.SetZ(this->z / mag);

  return tuple;
}

float Tuple::Dot(Tuple tupleB)
{
  return this->x * tupleB.GetX() + this->y * tupleB.GetY() + this->z * tupleB.GetZ();
}

Tuple Tuple::Cross(Tuple tupleB)
{
  Tuple tuple;

  tuple.SetX((this->y * tupleB.GetZ()) - (this->z * tupleB.GetY()));
  tuple.SetY((this->z * tupleB.GetX()) - (this->x * tupleB.GetZ()));
  tuple.SetZ((this->x * tupleB.GetY()) - (this->y * tupleB.GetX()));

  return tuple;
}
