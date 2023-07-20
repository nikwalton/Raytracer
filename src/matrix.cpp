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

Matrix Matrix::operator* (const Matrix rhs)
{
    Matrix result;
    return result;
}

Tuple Matrix::operator* (const Tuple rhs)
{
    Tuple result;
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