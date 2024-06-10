#pragma once

#include "material.hpp"
#include "matrix.hpp"
class Object {
public:
  Object() {};

  virtual void SetMaterial(Material material);
  virtual void SetTransform(Matrix mx);

  virtual Matrix GetTransform();
  virtual Material GetMaterial();

private:
  Matrix transform;
  Material material;
};