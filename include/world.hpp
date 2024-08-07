#pragma once

#include <vector>
#include <algorithm>

#include "object.hpp"
#include "lights.hpp"
#include "color.hpp"
#include "computation.hpp"
#include "intersection.hpp"
#include "ray.hpp"


class World {
public:
  World();

  World DefaultWorld();

  std::vector<Object*> GetObjects();
  std::vector<Light> GetLights();

  void AddLight(Light newLight);
  void AddObject(Object* newObj);

  void clearLights();
  void clearObjects();

  std::vector<Intersection> IntersectWorld(Ray r);

  Color ShadeHit(Computations comps);
  Color ColorAt(Ray r);

  bool IsShadowed(Point p);

private:
  std::vector<Object*> objs;
  std::vector<Light> lights;
};