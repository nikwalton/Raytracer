#include "object.hpp"
#include "object.hpp"


void Object::SetMaterial(Material material)
{
  this->material = material;
}

void Object::SetTransform(Matrix mx)
{
  this->transform = mx;
}

Matrix Object::GetTransform()
{
  return this->transform;
}

Material Object::GetMaterial()
{
  return this->material;
}

