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
  }
  std::vector<Intersection> intersect(Sphere s, Ray r);

  float getRadius();
  void setRadius(float newRadius);
  
private:
  float radius;
  // if we need to we can add a ID system as the book suggests, but we can probably just get away using each objects location in memory as it's ID
};