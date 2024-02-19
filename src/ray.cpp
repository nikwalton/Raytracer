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

Ray Ray::Transform(Matrix mx)
{
  Point origin = this->origin;
  Vector dir = this->direction;

  //TODO: make it so i dont have to recast these to Point and Vector
  Tuple newOrigin = mx * origin;
  Tuple newDir = mx * dir;

  Point p(newOrigin.GetX(), newOrigin.GetY(), newOrigin.GetZ());
  Vector d(newDir.GetX(), newDir.GetY(), newDir.GetZ());
  
  Ray r(p, d);
  
  return r;
}