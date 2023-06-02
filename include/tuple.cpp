#include <iostream>
#include "tuple.h"

//getters

float Tuple::GetX() {
    return this->x;
}

float Tuple::GetY() {
    return this->y;
}

float Tuple::GetZ() {
    return this->z;
}

//setters

void Tuple::SetX(float newX) {
    this->x = newX;
}

void Tuple::SetY(float newY) {
    this->y = newY;
}

void Tuple::SetZ(float newZ) {
    this->z = newZ;
}

//utils

bool Tuple::IsPoint() {
    if (this->w == 1) {
        return true;
    }
    return false;
}

Tuple Tuple::Point(float x, float y, float z) {
    Tuple tuple(x, y, z, 1);
    return tuple;
}

Tuple Tuple::Vector(float x, float y, float z) {
    Tuple tuple(x, y, z, 0);
    return tuple;
}