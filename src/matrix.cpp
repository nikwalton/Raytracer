
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
/// @return new Matrix obj of the resulting multiplication
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

/// <summary>
/// initalizes and returns a 4x4 identity matrix
/// </summary>
/// <returns>new 4x4 Matrix obj that is an identity matrix</returns>
Matrix Matrix::Identity()
{
  Matrix result;
  //return a 4x4 identiy matrix
  result.matrix[0][0] = 1;
  result.matrix[0][1] = 0;
  result.matrix[0][2] = 0;
  result.matrix[0][3] = 0;

  result.matrix[1][0] = 0;
  result.matrix[1][1] = 1;
  result.matrix[1][2] = 0;
  result.matrix[1][3] = 0;

  result.matrix[2][0] = 0;
  result.matrix[2][1] = 0;
  result.matrix[2][2] = 1;
  result.matrix[2][3] = 0;

  result.matrix[3][0] = 0;
  result.matrix[3][1] = 0;
  result.matrix[3][2] = 0;
  result.matrix[3][3] = 1;

  return result;
}

/// <summary>
/// Tansposes the matrix by replacing rows with respective columns, and columns with respective rows
/// </summary>
/// <returns>Transposed matrix as a new Matrix obj</returns>
Matrix Matrix::Transpose()
{
  Matrix result;
  //row to column, columns to rows

  result.matrix[0][0] = this->matrix[0][0];
  result.matrix[0][1] = this->matrix[1][0];
  result.matrix[0][2] = this->matrix[2][0];
  result.matrix[0][3] = this->matrix[3][0];

  result.matrix[1][0] = this->matrix[0][1];
  result.matrix[1][1] = this->matrix[1][1];
  result.matrix[1][2] = this->matrix[2][1];
  result.matrix[1][3] = this->matrix[3][1];

  result.matrix[2][0] = this->matrix[0][2];
  result.matrix[2][1] = this->matrix[1][2];
  result.matrix[2][2] = this->matrix[2][2];
  result.matrix[2][3] = this->matrix[3][2];

  result.matrix[3][0] = this->matrix[0][3];
  result.matrix[3][1] = this->matrix[1][3];
  result.matrix[3][2] = this->matrix[2][3];
  result.matrix[3][3] = this->matrix[3][3];

  return result;
}

/// <summary>
/// Calculates the determinant for 2x2, 3x3, or 4x4 matricies based on values in the current matrix
/// </summary>
float Matrix::Determinant()
{
  float det = 0;
  // we *should* always have square matrices so just check if matrix[0][2] is initialized to see if its bigger than 2x2
  if (this->matrix[0][2] == -107374176)
  {
    return this->matrix[0][0] * this->matrix[1][1] - this->matrix[0][1] * this->matrix[1][0];
  }
  else if (this->matrix[0][2] != -107374176 && this->matrix[0][3] == -107374176)
  {
    for (int col = 0; col < 3; col++)
    {
       det = det + this->matrix[0][col] * this->Cofactor(0, col);
    }
    return det;
  }
  else //4x4 matrix
  {
    for (int col = 0; col < 4; col++)
    {
      det = det + this->matrix[0][col] * this->Cofactor(0, col);
    }
    return det;
  }
}

/// <summary>
/// Cacluates the submatrix of the current matrix
/// </summary>
/// <param name="row">the row to be deleted from the matrix</param>
/// <param name="col">the column to be deleted from the matrix</param>
/// <returns>the resulting submatrix in a new Matrix obj</returns>
Matrix Matrix::Submatrix(int row, int col)
{
  Matrix result;
  int subRow = 0;
  int subCol = 0;

  for (int i = 0; i < 4; i++)
  {
    if (i == row)
      continue;

    for (int j = 0; j < 4; j++)
    {
      if (j == col && j + 1 < 4)
      {
        j++;
      }
      else if (j == col)
      {
        break;
      }


      result.matrix[subRow][subCol] = this->matrix[i][j];
      subCol++;
    }

    if (subCol != 0)
    {
      subRow++;
      subCol = 0;
    }
  }
  return result;
}

float Matrix::Minor(int row, int col)
{
  Matrix sub = this->Submatrix(row, col);
  float result = sub.Determinant();
  return result;
}
/// <summary>
/// Calculates the cofactor for this matrix
/// </summary>
/// <param name="row">the row to be deleted for the submatrix</param>
/// <param name="col">the column to be deleted for the submatrix</param>
/// <returns>A new Matrix obj with the cofactor result</returns>
float Matrix::Cofactor(int row, int col)
{

  Matrix sub = this->Submatrix(row, col);

  // if (row + col) is odd, negate
  return (row + col) % 2 == 0 ? sub.Determinant() : -1 * sub.Determinant();
}

/// <summary>
/// Check to see if this matrix is invertable
/// </summary>
/// <returns>True - Invertable, False - Non-Invertable</returns>
bool Matrix::Invertable()
{
  float det = this->Determinant();
  return det != 0? true : false;
}

/// <summary>
/// Calculates the inverse of this matrix
/// </summary>
/// <returns>The inverse of the current matrix as a new Matrix obj</returns>
Matrix Matrix::Inverse()
{
  Matrix M2;

  try {
    if (this->Invertable() == false)
    {
      throw(false);
    }
    else 
    {
      for (int row = 0; row < 4; row++)
      {
        for (int col = 0; col < 4; col++)
        {
          float c = this->Cofactor(row, col);
          M2.matrix[col][row] = c / this->Determinant();
        }
      }
    }
  }
  catch (bool invertable)
  {
    std::cout << "The matrix at " << this << "is not a invertable matrix\n";
  }
  return M2;
}

Matrix Matrix::Translation(float x, float y, float z)
{
  Matrix result = result.Identity();
  result.matrix[0][3] = x;
  result.matrix[1][3] = y;
  result.matrix[2][3] = z;

  return result;
}

Matrix Matrix::Scaling(float x, float y, float z)
{
  Matrix result = result.Identity();
  result.matrix[0][0] = x;
  result.matrix[1][1] = y;
  result.matrix[2][2] = z;

  return result;
}

Matrix Matrix::Shearing(float x_y, float x_z, float y_x, float y_z, float z_x, float z_y)
{
  Matrix shear = shear.Identity();

  shear.matrix[0][1] = x_y;
  shear.matrix[0][2] = x_z;
  shear.matrix[1][0] = y_x;
  shear.matrix[1][2] = y_z;
  shear.matrix[2][0] = z_x;
  shear.matrix[2][1] = z_y;

  return shear;
}

Matrix Matrix::RotateX(float radians) 
{
  Matrix rotation = rotation.Identity();
  rotation.matrix[1][1] = cos(radians);
  rotation.matrix[1][2] = -sin(radians);
  rotation.matrix[2][1] = sin(radians);
  rotation.matrix[2][2] = cos(radians);

  return rotation;
}

Matrix Matrix::RotateY(float radians)
{
  Matrix rotation = rotation.Identity();
  rotation.matrix[0][0] = cos(radians);
  rotation.matrix[0][2] = sin(radians);
  rotation.matrix[2][0] = -sin(radians);
  rotation.matrix[2][2] = cos(radians);

  return rotation;
}

Matrix Matrix::RotateZ(float radians)
{
  Matrix rotation = rotation.Identity();
  rotation.matrix[0][0] = cos(radians);
  rotation.matrix[0][1] = -sin(radians);
  rotation.matrix[1][0] = sin(radians);
  rotation.matrix[1][1] = cos(radians);

  return rotation;
}

/// <summary>
/// Provides a transformation matrix using the given diretional inputs
/// </summary>
/// <param name="from">A Point which is the point you wish to have the "eye" in the scene</param>
/// <param name="to">A Point which is the point you wish to look at</param>
/// <param name="up">A Vector that indicates which way is up</param>
/// <returns></returns>
Matrix Matrix::ViewTransform(Tuple from, Tuple to, Tuple up)
{
  Matrix orientation;

  Tuple forward = (to - from).Normalize();

  Tuple normalizedUp = up.Normalize();

  Tuple left = forward.Cross(normalizedUp);

  //allows original up be approximate. Better for framing.
  Tuple trueUp = left.Cross(forward);

  //constructing final matrix
  orientation.matrix[0][0] = left.GetX();
  orientation.matrix[0][1] = left.GetY();
  orientation.matrix[0][2] = left.GetZ();
  orientation.matrix[0][3] = 0;

  orientation.matrix[1][0] = trueUp.GetX();
  orientation.matrix[1][1] = trueUp.GetY();
  orientation.matrix[1][2] = trueUp.GetZ();
  orientation.matrix[1][3] = 0;

  orientation.matrix[2][0] = -forward.GetX();
  orientation.matrix[2][1] = -forward.GetY();
  orientation.matrix[2][2] = -forward.GetZ();
  orientation.matrix[2][3] = 0;

  orientation.matrix[3][0] = 0;
  orientation.matrix[3][1] = 0;
  orientation.matrix[3][2] = 0;
  orientation.matrix[3][3] = 1;

  //we need to appened the translation to this orientation to move the scene before orientating it in the way described above
  Matrix move = move.Translation(-from.GetX(), -from.GetY(), -from.GetZ());

  return orientation * move;
}