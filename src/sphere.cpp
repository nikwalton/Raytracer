#include "sphere.hpp"

std::vector<Intersection> Sphere::intersect(Sphere s, Ray r)
{
  Tuple sphereToRay = r.GetOrigin() - Point(0, 0, 0);
  
  float a = r.GetDirection().Dot(r.GetDirection());
  float b = 2 * r.GetDirection().Dot(sphereToRay);
  float c = sphereToRay.Dot(sphereToRay) - 1;

  float discriminant = pow(b, 2) - 4 * a * c;

  if (discriminant < 0)
  {
    return {};
  }
  else
  {
    float t1 = (-b - sqrt(discriminant)) / (2 * a);
    float t2 = (-b + sqrt(discriminant)) / (2 * a);

    Intersection i1(t1, this);
    Intersection i2(t2, this);

    return { i1, i2 };
  }
  return {};
}


float Sphere::getRadius()
{
  return this->radius;
}

void Sphere::setRadius(float newRadius)
{
  this->radius = newRadius;
}