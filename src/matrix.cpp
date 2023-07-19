#include "matrix.hpp"

bool Matrix::operator==(const Matrix rhs)
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