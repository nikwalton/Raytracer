#pragma once

#include "vector.hpp"
#include "point.hpp"

class Ray {
public:
  Ray();
  Ray(Point origin, Vector direction);

  Point GetOrigin();
  Vector GetDirection();

  Tuple Position(float t);


  void SetOrigin(Point newOrigin);
  void SetDirection(Vector newDirection);
private:
  Point origin;
  Vector direction;
};