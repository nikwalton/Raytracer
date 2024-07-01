#pragma once

#include "matrix.hpp"
#include "ray.hpp"
#include "canvas.hpp"
#include "world.hpp"

class Camera
{
public:
  Camera() {};
  Camera(unsigned short int hSize, unsigned short int vSize, float FOV)
  {
    this->hsize = hSize;
    this->vsize = vSize;
    this->fov = FOV;
    this->transform = transform.Identity();
    this->CalculatePixelSize();
  }

  unsigned short int GetHSize();
  unsigned short int GetVSize();

  float GetFOV();
  Matrix GetTransform();
  float GetPixelSize();
  float GetHalfHeight();
  float GetHalfWidth();

  void SetHSize(unsigned short int newHSize);
  void SetVSize(unsigned short int newVSize);
  void SetFOV(float newFOV);
  void SetTransform(Matrix newTransform);

  // probably dont want the user to be able to manually set pixel size,
  // so calculate it for them
  void CalculatePixelSize();
  Ray RayForPixel(unsigned short int x, unsigned short int y);

  Canvas Render(World world);

private:
  // unsigned shorts to match our canvas limits
  unsigned short int hsize;
  unsigned short int vsize;

  float fov;
  Matrix transform;

  float pixelsize;

  float halfheight;
  float halfwidth;
};