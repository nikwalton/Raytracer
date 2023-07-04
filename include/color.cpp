#include "color.h"

Color::Color(float r, float g, float b)
{
    this->SetX(r);
    this->SetY(g);
    this->SetZ(b);
}

float Color::GetRed()
{
    return this->GetX();
}

float Color::GetGreen()
{
    return this->GetY();
}

float Color::GetBlue()
{
    return this->GetZ();
}

void Color::SetRed(float newR)
{
    this->SetX(newR);
}

void Color::SetGreen(float newG)
{
    this->SetY(newG);
}

void Color::SetBlue(float newB)
{
   this->SetZ(newB);
}

Color Color::operator+(Color &rhs)
{
    Color result;

    result.SetX(this->GetRed() + rhs.GetRed());
    result.SetY(this->GetGreen() + rhs.GetGreen());
    result.SetZ(this->GetBlue() + rhs.GetBlue());
    
    return result;
}

Color Color::operator-(Color &rhs)
{
    Color result;

    result.SetX(this->GetRed() - rhs.GetRed());
    result.SetY(this->GetGreen() - rhs.GetGreen());
    result.SetZ(this->GetBlue() - rhs.GetBlue());
    
    return result;
}

Color Color::operator*(Color &rhs)
{
    Color result;

    result.SetX(this->GetRed() * rhs.GetRed());
    result.SetY(this->GetGreen() * rhs.GetGreen());
    result.SetZ(this->GetBlue() * rhs.GetBlue());
    
    return result;
}

Color Color::operator*(const float rhs)
{
    //From Tuple.h
    Color result;

    result.SetRed(this->GetRed() * rhs);
    result.SetGreen(this->GetGreen() * rhs);
    result.SetBlue(this->GetBlue() * rhs);

    return result;
}