#include "world.hpp"
#include "sphere.hpp"
#include "matrix.hpp"


World::World() {
  this->objs = {};
  this->lights = {};
}

std::vector<Object> World::GetObjects()
{
  return this->objs;
}

std::vector<Light> World::GetLights()
{
  return this->lights;
}

void World::AddLight(Light newLight)
{
  this->lights.push_back(newLight);
}

void World::AddObject(Object obj)
{
  this->objs.push_back(obj);
}

World World::DefaultWorld() {
  PointLight p;
  p.SetIntensity(Color(1.0, 1.0, 1.0));
  p.SetPosition(Point(-10.0, 10.0, -10.0));
  World w;

  Material m;
  m.SetColor(Color(0.8, 1.0, 0.6));
  m.SetDiffuse(0.7);
  m.SetSpecular(0.2);

  Sphere s1;
  s1.SetMaterial(m);

  Matrix mx;
  mx = mx.Scaling(0.5, 0.5, 0.5);
  
  Sphere s2;
  s2.SetTransform(mx);

  w.AddLight(p);
  w.AddObject(s1);
  w.AddObject(s2);
  return w;
}