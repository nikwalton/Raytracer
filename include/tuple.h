#include <iostream>

class Tuple {
public:
  Tuple();
  Tuple(float x, float y, float z, bool isVector) {

  }
  float GetX();
  float GetY();
  float GetZ();
  bool IsVector();

  ~Tuple() {}
private:
  float x, y, z;
  bool isVector;
};