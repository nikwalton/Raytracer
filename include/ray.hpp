#pragma once

#include "vector.hpp"
#include "point.hpp"
#include "matrix.hpp"

class Ray {
public:
  Ray();
  Ray(Point origin, Vector direction);

  Point GetOrigin();
  Vector GetDirection();

  Tuple Position(float t);
  Ray Transform(Matrix mx);


  void SetOrigin(Point newOrigin);
  void SetDirection(Vector newDirection);
private:
  Point origin;
  Vector direction;
};