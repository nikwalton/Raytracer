#pragma once

#include "color.hpp"
#include "point.hpp"

class Light {
public:
  Light() {}

  Light(Color intensity, Point position)
  {
    this->intensity = intensity;
    this->position = position;
  }

  virtual Color GetIntensity();
  virtual Point GetPosition();

  virtual void SetIntensity(Color c);
  virtual void SetPosition(Point p);
private:
  Color intensity;
  Point position;
};


class PointLight : public Light {
public:
  PointLight () {}

  PointLight(Color intensity, Point position)
  {
    this->SetIntensity(intensity);
    this->SetPosition(position);
  }
};