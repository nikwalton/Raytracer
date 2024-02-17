#include "intersection.hpp"
#include <algorithm>

Intersection::Intersection(float t, Sphere* obj)
{
  this->t = t;
  this->obj = obj;
}


std::vector<Intersection> Intersections(Intersection* i1, Intersection* i2, Intersection* i3, Intersection* i4)
{
  //theres probably a more elegant way of doing this
  std::vector<Intersection> result = {};
  if (i3 != nullptr && i4 == nullptr)
  {
    result.push_back(*i1);
    result.push_back(*i2);
    result.push_back(*i3);
    return result;
  }
  else if (i3 != nullptr && i4 != nullptr)
  {
    result.push_back(*i1);
    result.push_back(*i2);
    result.push_back(*i3);
    result.push_back(*i4);
    return result;
  }
  else
  {
    result.push_back(*i1);
    result.push_back(*i2);
    return result;
  }
  return {};
}

// return the lowest non-negative intersection in the collection of intersections
Intersection Hit(std::vector<Intersection> Intersections)
{
  float lowest = FLT_MAX;
  Intersection def;
  Intersection res;
  for (Intersection xs : Intersections)
  {
    if (xs.t > 0)
    {
       int newLow = std::min(lowest, xs.t);
       
       if (newLow != lowest)
       {
         lowest = newLow;
         res = xs;
       }
    }
  }
  return res;
}
