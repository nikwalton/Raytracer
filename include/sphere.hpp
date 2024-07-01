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

  virtual std::vector<Intersection> Intersect(Ray r) override;

  void SetRadius(float newRadius);

  virtual Vector NormalAt(Tuple worldPoint) override;
  
private:
  float radius;
};