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
  Tuple eyev;
  Tuple normalv;
  bool inside;
};

//global helper functions

Computations PrepareComputations(Intersection xs, Ray r)
{
  Computations comps;

  

  comps.t = xs.t;
  comps.obj = xs.obj;
  comps.point = r.Position(comps.t);
  // TODO: Hacky, fix later
  Tuple dir = r.GetDirection();
  comps.eyev = -dir;
  comps.normalv = comps.obj->NormalAt(comps.point);
  
  return comps;
}