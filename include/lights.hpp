#pragma once

#include "color.hpp"
#include "point.hpp"

class PointLight {
public:

  PointLight(){}

  PointLight(Color intensity, Point position)
  {
    this->intensitiy = intensity;
    this->position = position;
  }

  Color GetIntensity();
  Point GetPosition();

  void SetIntensity(Color c);
  void SetPosition(Point p);

private:
  Color intensitiy;
  Point position;

};