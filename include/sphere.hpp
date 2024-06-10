#pragma once

#include <vector>

#include "object.hpp"
#include "ray.hpp"
#include "intersection.hpp"
#include "material.hpp"

class Sphere : public Object
{
public:
  Sphere()
  {
    this->radius = 1;
    Matrix m;
    this->SetTransform(m.Identity());
    this->SetMaterial(Material());
  }

  std::vector<Intersection> intersect(Ray r);

  void SetRadius(float newRadius);

  Vector NormalAt(Point worldPoint);
  
private:
  float radius;

  
};