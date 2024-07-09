#include "computation.hpp"

Computations PrepareComputations(Intersection xs, Ray r)
{
  Computations comps;

  comps.t = xs.t;
  comps.obj = xs.obj;
  comps.point = r.Position(comps.t);
  // TODO: Hacky, fix later, should just use Point / Vector
  Tuple dir = r.GetDirection();
  comps.eyev = -dir;
  comps.normalv = comps.obj->NormalAt(comps.point);

  if (comps.normalv.Dot(comps.eyev) < 0)
  {
    comps.inside = true;
    comps.normalv = -comps.normalv;
    // In the book 0.00001 is referenced as EPSILON, which is about how precise we really need to be for rendering context
    // In rendering context, I render with "acne" at 0.00001 - 0.001 but none at 0.002
    comps.overPoint = comps.point + comps.normalv * 0.002;
  }
  else
  {
    comps.inside = false;
    comps.overPoint = comps.point + comps.normalv * 0.002;
  }

  return comps;
}