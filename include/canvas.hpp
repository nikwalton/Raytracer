#include "color.hpp"
#include <vector>
#include <sstream>
#include <string>
#include <cmath>

#pragma once

class Canvas
{
public:
  Canvas() {}
  Canvas(unsigned short int height, unsigned short int width);

  unsigned short int GetHeight();
  unsigned short int GetWidth();
  std::vector<std::vector<Color>> GetPixels();

  Color PixelAt(unsigned short int x, unsigned short int y);

  void SetHeight(unsigned short int newHeight);
  void SetWidth(unsigned short int newWidth);
  void SetPixels(std::vector<std::vector<Color>> newPixels);


  void WritePixel(unsigned short int y, unsigned short int x, Color pixel);

  std::string CanvasToPPM();
  int NormalizePixel(float value);

private:
  //if you need more than 60k pixels height and width wise idk what to tell you
  //i'd honestly be more impressed than anything
  unsigned short int width;
  unsigned short int height;

  std::vector<std::vector<Color>> pixels;
};
