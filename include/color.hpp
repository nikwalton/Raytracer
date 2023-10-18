#include "tuple.hpp"

#pragma once

class Color : public Tuple
{
public:
  Color() {}
  Color(float r, float g, float b);

  float GetRed();
  float GetGreen();
  float GetBlue();

  void SetRed(float newR);
  void SetGreen(float newG);
  void SetBlue(float newB);

  //some overrides for readibility, can just you Tuple class for most of these tbh
  Color operator+ (Color& rhs);
  Color operator- (Color& rhs);
  Color operator*(Color& rhs);
  Color operator*(const float rhs);
};

