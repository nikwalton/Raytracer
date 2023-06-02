#include <iostream>

class Tuple {
public:
  Tuple(){}
  Tuple(float newX, float newY, float newZ, bool newW) {
    x = newX;
    y = newY;
    z = newZ;
    w = newW;
  }

  ~Tuple() {
  }

  float GetX();
  float GetY();
  float GetZ();

  void SetX(float newX);
  void SetY(float newY);
  void SetZ(float newZ);

  bool IsPoint();

  Tuple Point(float x, float y, float z);
  Tuple Vector(float x, float y, float z);
private:
  float x, y, z;
  uint8_t w; // 1 is point 0 is vector
};