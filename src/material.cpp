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

Color Material::Lighting(PointLight light, Point point, Vector eyeVec, Vector normal)
{
  Color c;

  // combine surface color with lights color and intensity
  Color effectiveColor = this->GetColor() * light.GetIntensity();

  // find light direction
  Tuple lightTup = (light.GetPosition() - point).Normalize();

  // compute ambient contribution to lighting
  Color ambientContribution = effectiveColor * this->ambient;

  // initalize the other contributions
  Color diffuseContribution = Color(0, 0, 0);
  Color specularContribution = Color(0, 0, 0);

  // lightDotNormal is the cosine of the angle between light and normal vectors. Negative nums mean light is behind the surface
  float lightDotNormal = lightTup.Dot(normal);

  if (lightDotNormal < 0)
  {
    // we dont want to change the material values for this, just let the lighting function know things should be black
    diffuseContribution = Color(0, 0, 0);
    specularContribution = Color(0, 0, 0);
  }
  else
  {
    // compute diffuse contribution
    diffuseContribution = effectiveColor * this->GetDiffuse() * lightDotNormal;

    // reflectDotEye is the cosine of the angle beween reflection and eye vectors. Negative number means light is reflecting away from the eye

    //TODO: Get rid of this vector conversion
    Vector lightVec(-lightTup.GetX(), -lightTup.GetY(), -lightTup.GetZ());

    Tuple reflectVec = Reflect(lightVec, normal);
    float reflectDotEye = reflectVec.Dot(eyeVec);

    if (reflectDotEye < 0)
    {
      Color specularContribution = Color(0, 0, 0);
    }
    else
    {
      //
      float factor = pow(reflectDotEye, this->GetShininess());
      specularContribution = light.GetIntensity() * this->specular * factor;
    }
  }

  return ambientContribution + diffuseContribution + specularContribution;
}