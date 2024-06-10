#include "lights.hpp"

Color Light::GetIntensity()
{
  return this->intensity;
}

Point Light::GetPosition()
{
  return this->position;
}

void Light::SetIntensity(Color c)
{
  this->intensity = c;
}

void Light::SetPosition(Point p)
{
  this->position = p;
}
