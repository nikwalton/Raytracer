#pragma once

#include "matrix.hpp"
#include "material.hpp"

class Shape {
public:
   Matrix GetTransform() { return transformation; }
   void SetTransform(Matrix newTransform) { transformation = newTransform; }

   Material GetMaterial() { return material; }
   void SetMaterial(Material newMat) { material = newMat; }

   virtual std::vector<Intersection> Intersect(Ray r) { return {}; };

protected:
  Matrix transformation;
  Material material;
};

class TestShape : public Shape {
public:
  TestShape() { transformation = transformation.Identity();}
};

TestShape test_shape() {
  TestShape s;
  return s;
}