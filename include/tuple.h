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
  float GetW();

  void SetX(float newX);
  void SetY(float newY);
  void SetZ(float newZ);
  void SetW(float newW);

 

  Tuple Point(float x, float y, float z);
  Tuple Vector(float x, float y, float z);

  bool IsPoint();

  bool operator== (const Tuple& rhs);
  Tuple operator+ (const Tuple& rhs);
  Tuple operator- (const Tuple& rhs);
  Tuple operator- ();
  Tuple operator* (const float rhs);
  Tuple operator/ (const float rhs);

private:
  float x, y, z;
  float w; // 1 is point 0 is vector
};