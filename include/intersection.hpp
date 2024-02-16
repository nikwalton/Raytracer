#pragma once

#include <vector>
class Sphere;

class Intersection
{
public:
  Intersection(float t, Sphere* obj);
 
  float t;
  // this needs to be generic object but looks like we are working with spheres for a bit
  Sphere *obj;
};

std::vector<Intersection> Intersections(Intersection* i1, Intersection* i2, Intersection* i3 = nullptr, Intersection* i4 = nullptr);

