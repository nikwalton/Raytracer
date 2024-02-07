#pragma once

#include <vector>

#include"ray.hpp"

class Sphere
{
public:
  Sphere(){}
  std::vector<float> intersects(Sphere s, Ray r);

  float getRadius();
  void setRadius(float newRadius);
  
private:
  float radius;
};