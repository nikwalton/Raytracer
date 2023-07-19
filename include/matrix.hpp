#include "tuple.hpp"

#pragma once

/// @brief A implementation for a 4x4 matrix
class Matrix
{
public:
    Matrix(){}

    bool operator== (const Matrix rhs);
    bool operator* (const Matrix rhs);
    bool operator* (const Tuple rhs);

    void identity();
    void transpose();
    void determinant();
    
 
//we want these matrixes to be fast
//making the data privated creates more abstraction we dont need and will introduce some slow down
    float matrix[4][4];
};