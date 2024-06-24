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
  }
  else
  {
    comps.inside = false;
  }

  return comps;
}