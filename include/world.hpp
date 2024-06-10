#include <vector>

#include "object.hpp"
#include "lights.hpp"

class World {
public:
  World();

  World DefaultWorld();

  std::vector<Object> GetObjects();
  std::vector<Light> GetLights();

  void AddLight(Light newLight);
  void AddObject(Object obj);

private:
  std::vector<Object> objs;
  std::vector<Light> lights;
};