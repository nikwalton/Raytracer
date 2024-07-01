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

  float xOffset = ((float)x + 0.5) * this->GetPixelSize();
  float yOffset = ((float)y + 0.5) * this->GetPixelSize();

  float worldX = this->GetHalfWidth() - xOffset;
  float worldY = this->GetHalfHeight() - yOffset;

  Tuple pixel = (this->GetTransform().Inverse() * Point(worldX, worldY, -1));
  Tuple origin = (this->GetTransform().Inverse() * Point(0, 0, 0));
  Tuple direction = (pixel - origin).Normalize();

  // TODO: Get rid of the conversion below for the return
  Point returnOrigin(origin.GetX(), origin.GetY(), origin.GetZ());
  Vector returnVector(direction.GetX(), direction.GetY(), direction.GetZ());

  return Ray(returnOrigin, returnVector);
}

Canvas Camera::Render(World world)
{
  int hSize = this->GetHSize();
  int vSize = this->GetVSize();

  Canvas image(hSize, vSize);

  for (int y = 0; y <= vSize - 1; y++)
  {
    for (int x = 0; x <= hSize - 1; x++)
    {
      Ray ray = this->RayForPixel(x, y);
      Color color = world.ColorAt(ray);
      image.WritePixel(x, y, color);
    }
  }

  return image;
}