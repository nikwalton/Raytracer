#pragma once

#include "matrix.hpp"
#include "material.hpp"

class Shape {
public:
  virtual Matrix GetTransformation() { return transformation; }
  virtual void SetTransformation(Matrix newTransform) { transformation = newTransform; }

  virtual Material GetMaterial() { return material; }
  virtual void SetMaterial(Material newMat) { material = newMat; }
private:
  Matrix transformation;
  Material material;
};

class TestShape : public Shape {
public:
  TestShape() { transformation = transformation.Identity();}

  Matrix GetTransformation() { return transformation; }
  void SetTransformation(Matrix newTransform) { transformation = newTransform; }


  Material GetMaterial() { return material; }
  void SetMaterial(Material newMat) { material = newMat; }

private:
  Matrix transformation;
  Material material;
};

TestShape test_shape() {
  TestShape s;
  return s;
}