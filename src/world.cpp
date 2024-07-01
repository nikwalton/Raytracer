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

void World::clearLights()
{
  this->lights = {};
}

void World::clearObjects()
{
  this->objs = {};
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


Color World::ShadeHit(Computations comps)
{
  Object* o = comps.obj;

  Material m = o->GetMaterial();
  
  Color c(0, 0, 0);

  for (Light l : this->lights)
  {
    Color temp = m.Lighting(l, comps.point, comps.eyev, comps.normalv);
    c = c + temp;
  }
  return c;
}

Color World::ColorAt(Ray r)
{
  Color c(0, 0, 0);
  std::vector<Intersection> xs = this->IntersectWorld(r);
  Intersection hit = Hit(xs);
  Intersection empty; // TODO: get rid of this, kinda hacky should be able to just check if its empty 

  if (hit.t != empty.t && hit.obj != empty.obj)
  {
    Computations comps = PrepareComputations(hit, r);
    c = this->ShadeHit(comps);
    return c;
  }

  return c;
}