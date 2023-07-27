#include "matrix.hpp"

bool Matrix::operator== (const Matrix rhs)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (this->matrix[i][j] == rhs.matrix[i][j])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

// Kinda bad implementation
// probably should replace this with Strassen later we'll see

/// @brief Multiplies the full 4x4 matrix on the lhs with the 4x4 matrix on the rhs
/// @param rhs the matrix to be multiplied. B in the example A x B
/// @return a new matrix of the result
Matrix Matrix::operator* (const Matrix rhs)
{
      Matrix result;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            result.matrix[i][j] = this->matrix[i][0] * rhs.matrix[0][j] +
                                  this->matrix[i][1] * rhs.matrix[1][j] +
                                  this->matrix[i][2] * rhs.matrix[2][j] +
                                  this->matrix[i][3] * rhs.matrix[3][j];
        }
    }

    return result;
}

Tuple Matrix::operator* (Tuple rhs)
{
    Tuple result;
    float x, y, z, w;

    x = this->matrix[0][0] * rhs.GetX() + this->matrix[0][1] * rhs.GetY() + 
        this->matrix[0][2] * rhs.GetZ() + this->matrix[0][3] * rhs.GetW();

    y = this->matrix[1][0] * rhs.GetX() + this->matrix[1][1] * rhs.GetY() + 
        this->matrix[1][2] * rhs.GetZ() + this->matrix[1][3] * rhs.GetW();

    z = this->matrix[2][0] * rhs.GetX() + this->matrix[2][1] * rhs.GetY() + 
        this->matrix[2][2] * rhs.GetZ() + this->matrix[2][3] * rhs.GetW();

    w = this->matrix[3][0] * rhs.GetX() + this->matrix[3][1] * rhs.GetY() + 
        this->matrix[3][2] * rhs.GetZ() + this->matrix[3][3] * rhs.GetW();


    result.SetX(x);
    result.SetY(y);
    result.SetZ(z);
    result.SetW(w);
    return result;
}

Matrix Matrix::identity()
{
    Matrix result;
    return result;
}

Matrix Matrix::transpose()
{
    Matrix result;
    return result;
}

Matrix Matrix::determinant()
{
    Matrix result;
    return result;
}