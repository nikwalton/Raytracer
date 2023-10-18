#include "tuple.hpp"

#pragma once

/// @brief A implementation for a 4x4 matrix
class Matrix
{
public:
    Matrix(){}

    bool operator== (const Matrix rhs);
    Matrix operator* (const Matrix rhs);
    Tuple operator* (Tuple rhs);

    Matrix identity();
    Matrix transpose();
    Matrix submatrix(int row, int col);
    

    float determinant();
    float minor(int row, int col);
    float cofactor(int row, int col);
    
 
//we want these matrixes to be fast
//making the data privated creates more abstraction we dont need and will introduce some slow down
    float matrix[4][4];
};