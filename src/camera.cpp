#include <math.h>

#include "camera.hpp"

unsigned short int Camera::GetHSize()
{
  return this->hsize;
}

unsigned short int Camera::GetVSize()
{
  return this->vsize;
}

float Camera::GetFOV()
{
  return this->fov;
}

Matrix Camera::GetTransform()
{
  return this->transform;
}

float Camera::GetPixelSize()
{
  return this->pixelsize;
}

float Camera::GetHalfWidth()
{
  return this->halfwidth;
}

float Camera::GetHalfHeight()
{
  return this->halfheight;
}

void Camera::SetHSize(unsigned short int newHSize)
{
  this->hsize = newHSize;
}

void Camera::SetVSize(unsigned short int newVSize)
{
  this->vsize = newVSize;
}

void Camera::SetFOV(float newFOV)
{
  this->fov = newFOV;
}

void Camera::SetTransform(Matrix newTransform)
{
  this->transform = newTransform;
}

void Camera::CalculatePixelSize()
{

  float tFOV = this->GetFOV();
  int tHSize = this->GetHSize();
  int tVSize = this->GetVSize();

  float halfView = tan(tFOV / 2);

  // cast the pixel sizes to float to avoid integer division problems
  float aspectRatio = (float)tHSize / (float)tVSize;

  if (aspectRatio >= 1)
  {
    this->halfwidth = halfView;
    this->halfheight = halfView / aspectRatio;
  }
  else
  {
    this->halfwidth = halfView * aspectRatio;
    this->halfheight = halfView;
  }

  this->pixelsize = (this->halfwidth * 2) / this->hsize;
}

Ray Camera::RayForPixel(unsigned short int x, unsigned short int y)
{
  Ray r;
  return r;
}