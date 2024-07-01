#pragma once

#include <vector>
class Object;

class Intersection
{
public:
  Intersection() {};
  Intersection(float t, Object* obj);

 
  float t;
  // this needs to be generic object but looks like we are working with spheres for a bit
  Object *obj;
};

// Utility functions, could be part of the Intersection class but having it outside makes code a litle more readable
std::vector<Intersection> Intersections(Intersection* i1, Intersection* i2, Intersection* i3 = nullptr, Intersection* i4 = nullptr);
Intersection Hit(std::vector<Intersection> Intersections);
bool LesserCompare(Intersection i1, Intersection i2);

