#include <iostream>

class Tuple {
public:
  Tuple(){}
  Tuple(float x, float y, float z, bool isVector) {

  }
  ~Tuple() {}

  float GetX();
  float GetY();
  float GetZ();
  bool IsPoint();

  Tuple Point(float x, float y, float z);
  Tuple Vector(float x, float y, float z);
private:
  float x, y, z;
  bool isVector;
};