#pragma once

#include "object.hpp"
#include "point.hpp"
#include "vector.hpp"

// we really just need this to act like a struct but I want the ability to easily define
// this as a return type if I wanted to
class Computations {
public:
  float t;
  Object* obj;
  Tuple point;
  Tuple overPoint;
  Tuple eyev;
  Tuple normalv;
  bool inside;
};

//global helper functions
Computations PrepareComputations(Intersection xs, Ray r);