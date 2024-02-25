#include "lights.hpp"


Color PointLight::GetIntensity()
{
  return this->intensitiy;
}

Point PointLight::GetPosition()
{
  return this->position;
}

void PointLight::SetIntensity(Color c)
{
  this->intensitiy = c;
}

void PointLight::SetPosition(Point p)
{
  this->position = p;
}