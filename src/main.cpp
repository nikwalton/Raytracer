
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
#include "material.hpp"
#include "lights.hpp"

int main(int argc, char * argv[]) 
{
  float wallSize = 7.0;
  float canvasPixels = 200;
  Canvas canv(canvasPixels, canvasPixels);

  float pixelSize = wallSize / canvasPixels;
  float half = wallSize / 2;

  float wallZ = 10;
  Point rayOrigin(0, 0, -5);

  Color red(1, 0, 0);
  Sphere s;

  Material m;
  m.SetColor(Color(1, 0.2, 1));
  s.SetMaterial(m);

 PointLight light(Color(1, 1, 1), Point(-10, 10, -10));

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

      std::vector<Intersection> xs = s.Intersect(r);

      Intersection empty;
      Intersection hit = Hit(xs);

      if (hit.t != empty.t && hit.obj != empty.obj)
      {
        Tuple hitTup = r.Position(hit.t);
        //TODO: get rid of this conversion
        Point hitPoint(hitTup.GetX(), hitTup.GetY(), hitTup.GetZ());

        Vector normal = hit.obj->NormalAt(hitPoint);
        //TODO: get rid of this conversion
        Tuple eyeTup = -r.GetDirection();

        Vector eye(eyeTup.GetX(), eyeTup.GetY(), eyeTup.GetZ());
        Color color = m.Lighting(light, hitPoint, eye, normal);
        canv.WritePixel(x, y, color);
      }
    }
  }



  std::ofstream file;
  file.open("sphereShaded.ppm");
  file << canv.CanvasToPPM();
  file.close();
}