#include "material.hpp"

Color Material::GetColor()
{
  return this->color;
}

float Material::GetAmbient()
{
  return this->ambient;
}

float Material::GetDiffuse()
{
  return this->diffuse;
}

float Material::GetSpecular()
{
  return this->specular;
}

float Material::GetShininess()
{
  return this->shininess;
}

void Material::SetColor(Color color)
{
  this->color = color;
}

void Material::SetAmbient(float ambient)
{
  this->ambient = ambient;
}

void Material::SetDiffuse(float diffuse)
{
  this->diffuse = diffuse;
}

void Material::SetSpecular(float specular)
{
  this->specular = specular;
}

void Material::SetShininess(float shininess)
{
  this->shininess = shininess;
}