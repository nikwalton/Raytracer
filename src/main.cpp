
#include <iostream>
#include <math.h>
#define _USE_MATH_DEFINES
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
#include "world.hpp"
#include "camera.hpp"

int main(int argc, char* argv[])
{
  Matrix transformation;
  Matrix clear;
  Material mat;

  World w;

  Sphere* floor = new Sphere();

  //make a big flat sphere
  transformation = transformation.Scaling(10, 0.01, 10);
  floor->SetTransform(transformation);
  mat.SetColor(Color(1, 0.9, 0.9));
  mat.SetSpecular(0);
  floor->SetMaterial(mat);

  w.AddObject(floor);
  //same thing for walls but rotate it 
  Sphere* leftWall = new Sphere();
  transformation = clear;
  transformation = transformation.Translation(0, 0, 5) * transformation.RotateY(-M_PI_4) * transformation.RotateX(M_PI_2) * transformation.Scaling(10, 0.01, 10);
  leftWall->SetTransform(transformation);
  leftWall->SetMaterial(mat);

  w.AddObject(leftWall);

  Sphere* rightWall = new Sphere();
  transformation = clear;
  transformation = transformation.Translation(0, 0, 5) * transformation.RotateY(M_PI_4) * transformation.RotateX(M_PI_2) * transformation.Scaling(10, 0.01, 10);
  rightWall->SetTransform(transformation);
  rightWall->SetMaterial(mat);

  w.AddObject(rightWall);

  // stuff in the middle of the scene
  Sphere* middle = new Sphere();
  transformation = clear;
  transformation = transformation.Translation(-0.5, 1, 0.5);
  middle->SetTransform(transformation);

  mat.SetColor(Color(0.1, 1, 0.5));
  mat.SetDiffuse(0.7);
  mat.SetSpecular(0.3);
  middle->SetMaterial(mat);

  w.AddObject(middle);

  Sphere* right = new Sphere();

  transformation = clear;
  transformation = transformation.Translation(1.5, 0.5, -0.5) * transformation.Scaling(0.5, 0.5, 0.5);
  right->SetTransform(transformation);

  mat.SetColor(Color(0.5, 1, 0.1));
  right->SetMaterial(mat);

  w.AddObject(right);

  Sphere* left = new Sphere();
  transformation = clear;
  transformation = transformation.Translation(-1.5, 0.33, -0.75) * transformation.Scaling(0.33, 0.33, 0.33);
  left->SetTransform(transformation);

  mat.SetColor(Color(1, 0.8, 0.1));
  left->SetMaterial(mat);

  w.AddObject(left);

  PointLight light(Color(1, 1, 1), Point(-10, 10, -10));

  w.AddLight(light);

  Camera cam(300, 150, M_PI / 3);
  Matrix viewTransform = viewTransform.ViewTransform(Point(0, 1.5, -5), Point(0, 1, 0), Vector(0, 1, 0));
  cam.SetTransform(viewTransform);
  Canvas canvas = cam.Render(w);
  
  std::ofstream file;
  file.open("Scene.ppm");
  file << canvas.CanvasToPPM();
  file.close();
}