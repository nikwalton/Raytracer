#include "ray.hpp"


Ray::Ray()
{
}

Ray::Ray(Point origin, Vector direction)
{
  this->origin = origin;
  this->direction = direction;
}

Point Ray::GetOrigin()
{
  return this->origin;
}

Vector Ray::GetDirection()
{
  return this->direction;
}

void Ray::SetOrigin(Point newOrigin)
{
  this->origin = newOrigin;
}

void Ray::SetDirection(Vector newDirection)
{
  this->direction = newDirection;
}

Tuple Ray::Position(float t)
{
  Tuple p = this->origin + this->direction * t;
  return p;
}