
#include <iostream>
#include <math.h>
#include <fstream>

#include "tuple.hpp"
#include "vector.hpp"
#include "point.hpp"
#include "matrix.hpp"
#include "canvas.hpp"
#include "canon.hpp"

int main(int argc, char * argv[]) 
{
  Canvas canv(400, 400);

  Tuple Center(0, 0, 0, 1);
  Point middle(canv.GetHeight() / 2, canv.GetWidth() / 2, 0);

  const float_t pi = atan(1) * 4;
  Matrix r = r.RotateY(pi/ 6);
  Point twelve(0, 0, 1);
  Color dotColor(1, 0, 0);

  unsigned short x = twelve.GetX() * 100;
  unsigned short y = twelve.GetZ() * 100;

  canv.WritePixel(x + 200, y + 200, dotColor);

  Tuple currentHour = twelve;
  for (int i = 0; i < 12; i++)
  {
    currentHour = r * currentHour;
    x = currentHour.GetX() * 100;
    y = currentHour.GetZ() * 100;

    canv.WritePixel(x + 200, y + 200, dotColor);
  }

  std::ofstream file;
  file.open("clock.ppm");
  file << canv.CanvasToPPM();
  file.close();
}