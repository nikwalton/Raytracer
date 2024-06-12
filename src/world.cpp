#include "world.hpp"
#include "sphere.hpp"
#include "matrix.hpp"


World::World() {
  this->objs = {};
  this->lights = {};
}

std::vector<Object*> World::GetObjects()
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

void World::AddObject(Object *newObj)
{
  this->objs.push_back(newObj);
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

  Sphere *s1 = new Sphere();
  s1->SetMaterial(m);

  Matrix mx;
  mx = mx.Scaling(0.5, 0.5, 0.5);
  
  Sphere *s2 = new Sphere;
  s2->SetTransform(mx);

  w.AddLight(p);
  w.AddObject(s1);
  w.AddObject(s2);
  return w;
}

std::vector<Intersection> World::IntersectWorld(Ray r)
{
  std::vector<Intersection> list = {};

  std::vector<Object*> objList = this->GetObjects();

  for (auto obj : objList)
  {
    if (obj != nullptr)
    {
      std::vector<Intersection> xs = obj->Intersect(r);

      for (Intersection i : xs)
      {
        list.push_back(i);
      }
    }
  }

  sort(list.begin(), list.end(), LesserCompare);

  return list;
}