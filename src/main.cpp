
#include <iostream>
#include <math.h>
#include <fstream>

#include "tuple.hpp"
#include "vector.hpp"
#include "point.hpp"
#include "matrix.hpp"
#include "canvas.hpp"
#include "canon.hpp"
#include "sphere.hpp"
#include "intersection.hpp"


int main(int argc, char * argv[]) 
{
  float wallSize = 7.0;
  float canvasPixels = 100;
  Canvas canv(canvasPixels, canvasPixels);

  float pixelSize = wallSize / canvasPixels;
  float half = wallSize / 2;

  float wallZ = 10;
  Point rayOrigin(0, 0, -5);

  Color red(1, 0, 0);
  Sphere s;

  for (int y = 0; y < canvasPixels; y++)
  {
    float worldY = half - pixelSize * y;
    
    for (int x = 0; x < canvasPixels; x++)
    {
      float worldX = -half + pixelSize * x;

      Point pos(worldX, worldY, wallZ);

      Tuple temp = (pos - rayOrigin).Normalize();
      Vector dir(temp.GetX(), temp.GetY(), temp.GetZ());

      Ray r(rayOrigin, dir);

      std::vector<Intersection> xs = s.intersect(r);

      Intersection empty;
      Intersection hit = Hit(xs);

      if (hit.t != empty.t && hit.obj != empty.obj)
      {
        canv.WritePixel(x, y, red);
      }

    }
  }



  std::ofstream file;
  file.open("sphere.ppm");
  file << canv.CanvasToPPM();
  file.close();
}