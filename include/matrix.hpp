#pragma once
#include <math.h>

#include "tuple.hpp"



/// @brief A implementation for a 4x4 matrix that can be used as a 2x2 and 3x3 matrix
class Matrix
{
public:
    Matrix(){}

    bool operator== (const Matrix rhs);
    Matrix operator* (const Matrix rhs);
    Tuple operator* (Tuple rhs);
   
    Matrix Identity();
    Matrix Transpose();
    Matrix Submatrix(int row, int col);
    

    float Determinant();
    float Minor(int row, int col);
    float Cofactor(int row, int col);

    bool Invertable();
    Matrix Inverse();
    
    //Tansformations
    Matrix Translation(float x, float y, float z);
    Matrix Scaling(float x, float y, float z);
    Matrix Shearing(float x_y, float x_z, float y_x, float y_z, float z_x, float z_y);

    Matrix RotateX(float radians);
    Matrix RotateY(float radians);
    Matrix RotateZ(float radians);

    Matrix ViewTransform(Tuple from, Tuple to, Tuple up);
 
//we want these matrixes to be fast
//making the data privated creates more abstraction we dont need and will introduce some slow down
    float matrix[4][4];
};