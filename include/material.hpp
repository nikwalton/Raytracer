#pragma once

#include "color.hpp"
#include "lights.hpp"
#include "vector.hpp"

class Material
{
public:

  Material()
  {
    this->color = Color(1, 1, 1);
    this->ambient = 0.1;
    this->diffuse = 0.9;
    this->specular = 0.9;
    this->shininess = 200.0;
  }

  Material(float ambient, float diffuse, float specular, float shininess)
  {
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
    this->shininess = shininess;
  }

  Color GetColor();
  float GetAmbient();
  float GetDiffuse();
  float GetSpecular();
  float GetShininess();

  void SetColor(Color color);
  void SetAmbient(float ambient);
  void SetDiffuse(float diffuse);
  void SetSpecular(float specular);
  void SetShininess(float shininess);

  Color Lighting(Light light, Tuple point, Tuple eyevec, Tuple normal);


private:
  Color color;
  float ambient;
  float diffuse;
  float specular;
  float shininess;
};