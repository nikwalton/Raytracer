#pragma once

#include <vector>

#include "ray.hpp"
#include "intersection.hpp"

class Sphere
{
public:
  Sphere()
  {
    this->radius = 1;
    this->transform = transform.Identity();
  }
  std::vector<Intersection> intersect(Ray r);

  float GetRadius();
  void SetRadius(float newRadius);

  Matrix GetTransform();
  void SetTransform(Matrix mx);

 // Vector NormalAt(Point p);
  Vector NormalAt(Point worldPoint);
  
private:
  float radius;
  Matrix transform;
  // if we need to we can add a ID system as the book suggests, but we can probably just get away using each objects location in memory as it's ID
};