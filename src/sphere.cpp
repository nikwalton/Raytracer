#include "sphere.hpp"

std::vector<float> Sphere::intersects(Sphere s, Ray r)
{
  std::vector<float> result = {};

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
    return { t1, t2 };
  }
  return result;
}


float Sphere::getRadius()
{
  return this->radius;
}

void Sphere::setRadius(float newRadius)
{
  this->radius = newRadius;
}