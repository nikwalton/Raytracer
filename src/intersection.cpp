#include "intersection.hpp"

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
