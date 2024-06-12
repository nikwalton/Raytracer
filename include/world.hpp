#pragma once

#include <vector>
#include <algorithm>

#include "object.hpp"
#include "lights.hpp"
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

  std::vector<Intersection> IntersectWorld(Ray r);

private:
  std::vector<Object*> objs;
  std::vector<Light> lights;
};