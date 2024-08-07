#include "sphere.hpp"

std::vector<Intersection> Sphere::Intersect(Ray r) 
{
  Ray r2 = r.Transform(GetTransform().Inverse());

  Tuple sphereToRay = r2.GetOrigin() - Point(0, 0, 0);
  
  float a = r2.GetDirection().Dot(r2.GetDirection());
  float b = 2 * r2.GetDirection().Dot(sphereToRay);
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

void Sphere::SetRadius(float newRadius)
{
  this->radius = newRadius;
}

Vector Sphere::NormalAt(Tuple WorldPoint)
{
  Tuple objPoint = this->GetTransform().Inverse() * WorldPoint;
  Tuple objNormal = objPoint - Point(0, 0, 0);

  Tuple worldNormal = this->GetTransform().Inverse().Transpose() * objNormal;
  worldNormal.SetW(0);

  Tuple normal = worldNormal.Normalize();

  Vector n(normal.GetX(), normal.GetY(), normal.GetZ());
  return n;
}