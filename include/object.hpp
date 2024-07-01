#pragma once

#include "material.hpp"
#include "matrix.hpp"
#include "intersection.hpp"
#include "ray.hpp"

class Object {
public:
  Object() {};

  virtual void SetMaterial(Material material);
  virtual void SetTransform(Matrix mx);

  virtual Matrix GetTransform();
  virtual Material GetMaterial();

  virtual std::vector<Intersection> Intersect(Ray r) = 0;
  virtual Vector NormalAt(Tuple p) = 0;

private:
  Matrix transform;
  Material material;
};