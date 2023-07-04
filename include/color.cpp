#include "color.h"

Color::Color(float r, float g, float b)
{

}

float Color::GetRed()
{
    return 0.0;
}

float Color::GetGreen()
{
    return 0.0;
}

float Color::GetBlue()
{
    return 0.0;
}

void Color::SetRed(float newR)
{
    
}

void Color::SetGreen(float newG)
{
 
}

void Color::SetBlue(float newB)
{
   
}

Color Color::operator*(Color &rhs)
{
    Color result;
    return result;
}

Tuple Color::operator*(const float rhs)
{
    //From Tuple.h
    Tuple tuple;

    tuple.SetX(this->GetRed() * rhs);
    tuple.SetY(this->GetBlue() * rhs);
    tuple.SetZ(this->GetGreen() * rhs);

    return tuple;
}