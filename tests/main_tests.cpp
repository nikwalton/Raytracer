#include <gtest/gtest.h>

#include<math.h>
#include<string>
#include<sstream>

//My Lib includes
#include "tuple.hpp"
#include "vector.hpp"
#include "point.hpp"
#include "color.hpp"
#include "canvas.hpp"
#include "matrix.hpp"



 //START OF TUPLE, POINT, VECTOR TEST SUITE
TEST(TuplePointVectorTests, TupleCreationTest_IsVector) {
  Tuple tuple(4.3, -4.2, 3.1, 0);

  EXPECT_FLOAT_EQ(tuple.GetX(), 4.3);
  EXPECT_FLOAT_EQ(tuple.GetY(), -4.2);
  EXPECT_FLOAT_EQ(tuple.GetZ(), 3.1);
  EXPECT_FLOAT_EQ(tuple.IsPoint(), false);

}

TEST(TuplePointVectorTests, TupleCreationTest_IsPoint) {
  Tuple tuple(4.3, -4.2, 3.1, 1);

  EXPECT_FLOAT_EQ(tuple.GetX(), 4.3);
  EXPECT_FLOAT_EQ(tuple.GetY(), -4.2);
  EXPECT_FLOAT_EQ(tuple.GetZ(), 3.1);
  EXPECT_FLOAT_EQ(tuple.IsPoint(), true);

}

TEST(TuplePointVectorTests, PointTest) {
  Point point(4, -4, 3);


  EXPECT_EQ(point.GetX(), 4);
  EXPECT_EQ(point.GetY(), -4);
  EXPECT_EQ(point.GetZ(), 3);
  EXPECT_EQ(point.IsPoint(), true);
}

TEST(TuplePointVectorTests, VectorFactoryTest) {
  Vector vector(4, -4, 3);

  EXPECT_EQ(vector.GetX(), 4);
  EXPECT_EQ(vector.GetY(), -4);
  EXPECT_EQ(vector.GetZ(), 3);
  EXPECT_EQ(vector.IsPoint(), 0);
}

TEST(TuplePointVectorTests, EqualOperatorTest) {
  Tuple tuple(4.3, -4.2, 3.1, 0);
  Tuple tuple2(4.3, -4.2, 3.1, 0);
  Tuple tuple3(3.2, 3.2, 3.2, 1);

  EXPECT_EQ(tuple == tuple2, true);
  EXPECT_EQ(tuple == tuple3, false);
}

TEST(TuplePointVectorTests, AddOperatorTest) {
  Tuple tuple(3, -2, 5, 1);
  Tuple tuple2(-2, 3, 1, 0);
  // solution (1, 1, 6, 1);
  Tuple attempt = tuple + tuple2;

  EXPECT_EQ(attempt.GetX(), 1);
  EXPECT_EQ(attempt.GetY(), 1);
  EXPECT_EQ(attempt.GetZ(), 6);
  EXPECT_EQ(attempt.IsPoint(), true);
}

TEST(TuplePointVectorTests, SubtractOperatorTest_PointFromPoint) {
  //subtracting two points result in a vector
  Point p1(3, 2, 1);
  Point p2(5, 6, 7);
  //solution Vector (-2, -4, -6);
  Tuple attempt = p1 - p2;


  EXPECT_EQ(attempt.GetX(), -2);
  EXPECT_EQ(attempt.GetY(), -4);
  EXPECT_EQ(attempt.GetZ(), -6);
  EXPECT_EQ(attempt.IsPoint(), false);
}

TEST(TuplePointVectorTests, SubtractOperatorTest_VecFromPoint) {
  //subtracting a vector from a point results in a point
  Point p(3, 2, 1);
  Vector v(5, 6, 7);
  // solution Point (-2, -4, -6);
  Tuple attempt = p - v;

  EXPECT_EQ(attempt.GetX(), -2);
  EXPECT_EQ(attempt.GetY(), -4);
  EXPECT_EQ(attempt.GetZ(), -6);
  EXPECT_EQ(attempt.IsPoint(), true);
}

TEST(TuplePointVectorTests, SubtractOperatorTest_VecFromVec) {
  Vector v1(3, 2, 1);
  Vector v2(5, 6, 7);
  //solution Vector (-2, -4, -6)
  Tuple attempt = v1 - v2;


  EXPECT_EQ(attempt.GetX(), -2);
  EXPECT_EQ(attempt.GetY(), -4);
  EXPECT_EQ(attempt.GetZ(), -6);
  EXPECT_EQ(attempt.IsPoint(), false);
}

TEST(TuplePointVectorTests, SubtractOperatorTest_ZeroFromVec) {
  Vector zero(0, 0, 0);
  Vector v(1, -2, 3);
  //solution Vector (-1, 2, -3);
  Tuple attempt = zero - v;


  EXPECT_EQ(attempt.GetX(), -1);
  EXPECT_EQ(attempt.GetY(), 2);
  EXPECT_EQ(attempt.GetZ(), -3);
  EXPECT_EQ(attempt.IsPoint(), false);
}

// following are general functions, so we dont really care what happens to w in terms of
// if its a vector or not

TEST(TuplePointVectorTests, NegationOperatorTest) {
  Tuple tuple(1, -2, 3, -4);
  Tuple attempt = -tuple;


  EXPECT_EQ(attempt.GetX(), -1);
  EXPECT_EQ(attempt.GetY(), 2);
  EXPECT_EQ(attempt.GetZ(), -3);
  EXPECT_EQ(attempt.GetW(), 4);
}

TEST(TuplePointVectorTests, ScalarMultiplicationTest_1) {
  Tuple tuple(1, -2, 3, -4);
  Tuple attempt = tuple * 3.5;

  EXPECT_EQ(attempt.GetX(), 3.5);
  EXPECT_EQ(attempt.GetY(), -7);
  EXPECT_EQ(attempt.GetZ(), 10.5);
  EXPECT_EQ(attempt.GetW(), -14);
}

TEST(TuplePointVectorTests, ScalarMultiplicationTest_2) {
  Tuple tuple(1, -2, 3, -4);
  Tuple attempt = tuple * 0.5;

  EXPECT_EQ(attempt.GetX(), 0.5);
  EXPECT_EQ(attempt.GetY(), -1);
  EXPECT_EQ(attempt.GetZ(), 1.5);
  EXPECT_EQ(attempt.GetW(), -2);
}

TEST(TuplePointVectorTests, ScalarDivisionTest) {
  Tuple tuple(1, -2, 3, -4);
  Tuple attempt = tuple / 2;

  EXPECT_EQ(attempt.GetX(), 0.5);
  EXPECT_EQ(attempt.GetY(), -1);
  EXPECT_EQ(attempt.GetZ(), 1.5);
  EXPECT_EQ(attempt.GetW(), -2);
}

TEST(TuplePointVectorTests, MagnitudeTest_1) {
  Vector vec(1, 0, 0);

  float attempt = vec.Magnitude();

  EXPECT_EQ(attempt, 1);
}

TEST(TuplePointVectorTests, MagnitudeTest_2) {
  Vector vec(0, 1, 0);

  float attempt = vec.Magnitude();

  EXPECT_EQ(attempt, 1);
}

TEST(TuplePointVectorTests, MagnitudeTest_3) {
  Vector vec(0, 0, 1);

  float attempt = vec.Magnitude();

  EXPECT_EQ(attempt, 1);
}

TEST(TuplePointVectorTests, MagnitudeTest_4) {
  Vector vec(1, 2, 3);

  float attempt = vec.Magnitude();

  //sqrt returns double, downcast to float
  EXPECT_FLOAT_EQ(attempt, sqrt(14));
}

TEST(TuplePointVectorTests, MagnitudeTest_5) {
  Vector vec(-1, -2, -3);

  float attempt = vec.Magnitude();

  //sqrt returns double, downcast to flaot
  EXPECT_FLOAT_EQ(attempt, sqrt(14));
}

// Following tests do depend on w correctly holding vector / not vector values in w

TEST(TuplePointVectorTests, NormalizeTest_1) {
  Vector vec(4, 0, 0);

  Tuple attempt = vec.Normalize();

  EXPECT_EQ(attempt.GetX(), 1);
  EXPECT_EQ(attempt.GetY(), 0);
  EXPECT_EQ(attempt.GetZ(), 0);
  EXPECT_EQ(attempt.IsPoint(), false);
}

TEST(TuplePointVectorTests, NormalizeTest_2) {
  Vector vec(1, 2, 3);

  Tuple attempt = vec.Normalize();

  EXPECT_FLOAT_EQ(attempt.GetX(), 1 / sqrt(14));
  EXPECT_FLOAT_EQ(attempt.GetY(), 2 / sqrt(14));
  EXPECT_FLOAT_EQ(attempt.GetZ(), 3 / sqrt(14));
  EXPECT_EQ(attempt.IsPoint(), false);
}

TEST(TuplePointVectorTests, MagnitudeOfNormalizedTest) {
  Vector vec(1, 2, 3);
  Tuple normalized = vec.Normalize();

  float attempt = normalized.Magnitude();

  EXPECT_FLOAT_EQ(attempt, 1);
}

TEST(TuplePointVectorTests, DotProductTest) {
  Vector vecA(1, 2, 3);
  Vector vecB(2, 3, 4);

  // vector A * vector B
  float attempt = vecA.Dot(vecB);

  EXPECT_EQ(attempt, 20);
}

TEST(TuplePointVectorTests, CrossProductTest) {
  Vector vecA(1, 2, 3);
  Vector vecB(2, 3, 4);
  //vectorA x vectorB
  Tuple attempt = vecA.Cross(vecB);

  EXPECT_EQ(attempt.GetX(), -1);
  EXPECT_EQ(attempt.GetY(), 2);
  EXPECT_EQ(attempt.GetZ(), -1);
  EXPECT_EQ(attempt.IsPoint(), false);

  // vectorB x vectorB;
  Tuple attempt2 = vecB.Cross(vecA);

  EXPECT_EQ(attempt2.GetX(), 1);
  EXPECT_EQ(attempt2.GetY(), -2);
  EXPECT_EQ(attempt2.GetZ(), 1);
  EXPECT_EQ(attempt2.IsPoint(), false);

}

// START OF COLOR TEST SUITE
TEST(ColorCanvasTests, ColorCreationTest) {
  Color color(-0.5, 0.4, 1.7);

  EXPECT_FLOAT_EQ(color.GetRed(), -0.5);
  EXPECT_FLOAT_EQ(color.GetGreen(), 0.4);
  EXPECT_FLOAT_EQ(color.GetBlue(), 1.7);
}

TEST(ColorCanvasTests, AddingColorsTest) {
  Color color1(0.9, 0.6, 0.75);
  Color color2(0.7, 0.1, 0.25);

  Tuple attempt = color1 + color2;

  EXPECT_FLOAT_EQ(attempt.GetX(), 1.6);
  EXPECT_FLOAT_EQ(attempt.GetY(), 0.7);
  EXPECT_FLOAT_EQ(attempt.GetZ(), 1.0);
}

TEST(ColorCanvasTests, SubtractingColorsTest) {
  Color color1(0.9, 0.6, 0.75);
  Color color2(0.7, 0.1, 0.25);

  Color attempt = color1 - color2;

  EXPECT_FLOAT_EQ(attempt.GetX(), 0.2);
  EXPECT_FLOAT_EQ(attempt.GetY(), 0.5);
  EXPECT_FLOAT_EQ(attempt.GetZ(), 0.5);
}

TEST(ColorCanvasTests, MultplyColorScalarTest) {
  Color color((float)0.2, (float)0.3, (float)0.4);

  Tuple attempt = color * 2;

  EXPECT_FLOAT_EQ(attempt.GetX(), 0.4);
  EXPECT_FLOAT_EQ(attempt.GetY(), 0.6);
  EXPECT_FLOAT_EQ(attempt.GetZ(), 0.8);
}

TEST(ColorCanvasTests, MultiplyTwoColorsTest) {
  Color color1(1, 0.2, 0.4);
  Color color2(0.9, 1, 0.1);

  Color attempt = color1 * color2;

  EXPECT_FLOAT_EQ(attempt.GetX(), 0.9);
  EXPECT_FLOAT_EQ(attempt.GetY(), 0.2);
  EXPECT_FLOAT_EQ(attempt.GetZ(), 0.04);
}

TEST(ColorCanvasTests, CreateCanvasTest) {
  Canvas canv(10, 20);
  EXPECT_EQ(canv.GetWidth(), 10);
  EXPECT_EQ(canv.GetHeight(), 20);

  std::vector<std::vector<Color>> pixels = canv.GetPixels();

  //iterate through each pixel make sure they are all rgb(0,0,0)
  for (auto x : pixels)
  {
    for (auto y : x)
    {
      EXPECT_EQ(y.GetRed(), 0);
      EXPECT_EQ(y.GetGreen(), 0);
      EXPECT_EQ(y.GetBlue(), 0);
    }
  }
}

TEST(ColorCanvasTests, WriteToCanvas) {
  Canvas canv(10, 20);
  Color red(1, 0, 0);

  canv.WritePixel(2, 3, red);

  Color attempt = canv.PixelAt(2, 3);

  EXPECT_EQ(red.GetRed(), attempt.GetRed());
  EXPECT_EQ(red.GetGreen(), attempt.GetGreen());
  EXPECT_EQ(red.GetBlue(), attempt.GetBlue());
}

TEST(ColorCanvasTests, CanvasToPPM_HeaderTest)
{
  Canvas canv(5, 3);

  std::istringstream ppm_file{ canv.CanvasToPPM() };

  std::string line;

  //first 3 lines is the header of the ppm file
  //line 1
  std::getline(ppm_file, line);
  EXPECT_EQ(line, "P3");
  //line 2
  std::getline(ppm_file, line);
  EXPECT_EQ(line, "5 3");
  //line 3
  std::getline(ppm_file, line);
  EXPECT_EQ(line, "255");
}

TEST(ColorCanvasTests, CanvasToPPM_BodyTest)
{
  Canvas canv(5, 3);
  Color c1(1.5, 0, 0);
  Color c2(0, 0.5, 0);
  Color c3(-0.5, 0, 1);

  canv.WritePixel(0, 0, c1);
  canv.WritePixel(2, 1, c2);
  canv.WritePixel(4, 2, c3);

  std::istringstream ppm_file{ canv.CanvasToPPM() };

  std::string line;
  //skip first 3 lines;
  for (int i = 0; i < 3; i++)
  {
    std::getline(ppm_file, line);
  }
  //lines 4-6 is where the body of the file begins
  //line 4
  std::getline(ppm_file, line);
  EXPECT_EQ(line, "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0");
  //line 5
  std::getline(ppm_file, line);
  EXPECT_EQ(line, "0 0 0 0 0 0 0 128 0 0 0 0 0 0 0");
  //line 6
  std::getline(ppm_file, line);
  EXPECT_EQ(line, "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255");
}

TEST(ColorCanvasTests, CanvasToPPM_BodyLineLengthTest) {
  //a line should be no more than 70 chars long

  Canvas canv(10, 2);
  Color fill(1, 0.8, 0.6);

  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      canv.WritePixel(j, i, fill);
    }
  }
  //need to get to rows 4-7 of the ppm file now
  std::istringstream ppm_file{ canv.CanvasToPPM() };

  std::string line;
  //skip first 3 lines;
  for (int i = 0; i < 3; i++)
  {
    std::getline(ppm_file, line);
  }
  //line 4
  std::getline(ppm_file, line);
  EXPECT_EQ(line, "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204");
  //line 5
  std::getline(ppm_file, line);
  EXPECT_EQ(line, "153 255 204 153 255 204 153 255 204 153 255 204 153");
  //line 6
  std::getline(ppm_file, line);
  EXPECT_EQ(line, "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204");
  //line 7
  std::getline(ppm_file, line);
  EXPECT_EQ(line, "153 255 204 153 255 204 153 255 204 153 255 204 153");
}

TEST(ColorCanvasTests, CanvasToPPM_EOF_NewLineTest) {
  Canvas canv(5, 3);
  std::string ppm_file = canv.CanvasToPPM();

  char attempt = ppm_file[ppm_file.length() - 1];

  EXPECT_EQ(attempt, '\n');
}


//Creation tests more striaght forward since we want lean matrix classes with 
//little barrier to entry
TEST(MatrixOperationsTests, Matrix2_CreationTest) {
  Matrix testMatrix;

  //matrix to be created
  // | -3 | 5 |
  // | 1 | -2 |

  testMatrix.matrix[0][0] = -3;
  testMatrix.matrix[0][1] = 5;
  testMatrix.matrix[1][0] = 1;
  testMatrix.matrix[1][1] = -2;

  EXPECT_FLOAT_EQ(testMatrix.matrix[0][0], -3);
  EXPECT_FLOAT_EQ(testMatrix.matrix[0][1], 5);
  EXPECT_FLOAT_EQ(testMatrix.matrix[1][0], 1);
  EXPECT_FLOAT_EQ(testMatrix.matrix[1][1], -2);
}

TEST(MatrixOperationsTests, Matrix3_CreationTest) {
  Matrix testMatrix;

  //matrix to be created
  // | -3 | 5 | 0 |
  // | 1 | -2 | -7 |
  // | 0 | 1 | 1 |

  testMatrix.matrix[0][0] = -3;
  testMatrix.matrix[0][1] = 5;
  testMatrix.matrix[0][2] = 0;
  testMatrix.matrix[1][0] = 1;
  testMatrix.matrix[1][1] = -2;
  testMatrix.matrix[1][2] = -7;
  testMatrix.matrix[2][0] = 0;
  testMatrix.matrix[2][1] = 1;
  testMatrix.matrix[2][2] = 1;

  EXPECT_FLOAT_EQ(testMatrix.matrix[0][0], -3);
  EXPECT_FLOAT_EQ(testMatrix.matrix[1][1], -2);
  EXPECT_FLOAT_EQ(testMatrix.matrix[2][2], 1);
}

TEST(MatrixOperationsTests, Matrix4_CreationTests) {
  Matrix testMatrix;

  // | 1|2|3|4|
  // | 5.5|6.5|7.5|8.5|
  // |10|11|12|13|
  // |14.5|15.5|16.5|17.5|

  testMatrix.matrix[0][0] = 1;
  testMatrix.matrix[0][1] = 2;
  testMatrix.matrix[0][2] = 3;
  testMatrix.matrix[0][3] = 4;
  testMatrix.matrix[1][0] = 5.5;
  testMatrix.matrix[1][1] = 6.5;
  testMatrix.matrix[1][2] = 7.5;
  testMatrix.matrix[1][3] = 8.5;
  testMatrix.matrix[2][0] = 10;
  testMatrix.matrix[2][1] = 11;
  testMatrix.matrix[2][2] = 12;
  testMatrix.matrix[2][3] = 13;
  testMatrix.matrix[3][0] = 14.5;
  testMatrix.matrix[3][1] = 15.5;
  testMatrix.matrix[3][2] = 16.5;
  testMatrix.matrix[3][3] = 17.5;

  EXPECT_EQ(testMatrix.matrix[0][0], 1);
  EXPECT_EQ(testMatrix.matrix[0][3], 4);
  EXPECT_FLOAT_EQ(testMatrix.matrix[1][0], 5.5);
  EXPECT_FLOAT_EQ(testMatrix.matrix[1][2], 7.5);
  EXPECT_EQ(testMatrix.matrix[2][2], 12);
  EXPECT_FLOAT_EQ(testMatrix.matrix[3][0], 14.5);
  EXPECT_FLOAT_EQ(testMatrix.matrix[3][2], 16.5);
}

//the following only needs to be tested once per matrix as the source code
//will be the same for Matrix3 and Matrix4
TEST(MatrixOperationsTests, Matrix_EqualityTest)
{
  Matrix testMatrix;
  testMatrix.matrix[0][0] = 1;
  testMatrix.matrix[0][1] = 2;
  testMatrix.matrix[0][2] = 3;
  testMatrix.matrix[0][3] = 4;
  testMatrix.matrix[1][0] = 5.5;
  testMatrix.matrix[1][1] = 6.5;
  testMatrix.matrix[1][2] = 7.5;
  testMatrix.matrix[1][3] = 8.5;
  testMatrix.matrix[2][0] = 10;
  testMatrix.matrix[2][1] = 11;
  testMatrix.matrix[2][2] = 12;
  testMatrix.matrix[2][3] = 13;
  testMatrix.matrix[3][0] = 14.5;
  testMatrix.matrix[3][1] = 15.5;
  testMatrix.matrix[3][2] = 16.5;
  testMatrix.matrix[3][3] = 17.5;

  Matrix otherMatrix;
  otherMatrix.matrix[0][0] = 1;
  otherMatrix.matrix[0][1] = 2;
  otherMatrix.matrix[0][2] = 3;
  otherMatrix.matrix[0][3] = 4;
  otherMatrix.matrix[1][0] = 5.5;
  otherMatrix.matrix[1][1] = 6.5;
  otherMatrix.matrix[1][2] = 7.5;
  otherMatrix.matrix[1][3] = 8.5;
  otherMatrix.matrix[2][0] = 10;
  otherMatrix.matrix[2][1] = 11;
  otherMatrix.matrix[2][2] = 12;
  otherMatrix.matrix[2][3] = 13;
  otherMatrix.matrix[3][0] = 14.5;
  otherMatrix.matrix[3][1] = 15.5;
  otherMatrix.matrix[3][2] = 16.5;
  otherMatrix.matrix[3][3] = 17.5;

  EXPECT_EQ(testMatrix == otherMatrix, true);

  //change other matrix to test false case

  otherMatrix.matrix[2][2] = 0;

  EXPECT_EQ(testMatrix == otherMatrix, false);
}

TEST(MatrixOperationsTests, MatrixtMultiplicationTest)
{
  Matrix matrixA;

  matrixA.matrix[0][0] = 1;
  matrixA.matrix[0][1] = 2;
  matrixA.matrix[0][2] = 3;
  matrixA.matrix[0][3] = 4;
  matrixA.matrix[1][0] = 5;
  matrixA.matrix[1][1] = 6;
  matrixA.matrix[1][2] = 7;
  matrixA.matrix[1][3] = 8;
  matrixA.matrix[2][0] = 9;
  matrixA.matrix[2][1] = 8;
  matrixA.matrix[2][2] = 7;
  matrixA.matrix[2][3] = 6;
  matrixA.matrix[3][0] = 5;
  matrixA.matrix[3][1] = 4;
  matrixA.matrix[3][2] = 3;
  matrixA.matrix[3][3] = 2;

  Matrix matrixB;

  matrixB.matrix[0][0] = -2;
  matrixB.matrix[0][1] = 1;
  matrixB.matrix[0][2] = 2;
  matrixB.matrix[0][3] = 3;
  matrixB.matrix[1][0] = 3;
  matrixB.matrix[1][1] = 2;
  matrixB.matrix[1][2] = 1;
  matrixB.matrix[1][3] = -1;
  matrixB.matrix[2][0] = 4;
  matrixB.matrix[2][1] = 3;
  matrixB.matrix[2][2] = 6;
  matrixB.matrix[2][3] = 5;
  matrixB.matrix[3][0] = 1;
  matrixB.matrix[3][1] = 2;
  matrixB.matrix[3][2] = 7;
  matrixB.matrix[3][3] = 8;

  Matrix attempt = matrixA * matrixB;

  EXPECT_EQ(attempt.matrix[0][0], 20);
  EXPECT_EQ(attempt.matrix[0][1], 22);
  EXPECT_EQ(attempt.matrix[0][2], 50);
  EXPECT_EQ(attempt.matrix[0][3], 48);
  EXPECT_EQ(attempt.matrix[1][0], 44);
  EXPECT_EQ(attempt.matrix[1][1], 54);
  EXPECT_EQ(attempt.matrix[1][2], 114);
  EXPECT_EQ(attempt.matrix[1][3], 108);
  EXPECT_EQ(attempt.matrix[2][0], 40);
  EXPECT_EQ(attempt.matrix[2][1], 58);
  EXPECT_EQ(attempt.matrix[2][2], 110);
  EXPECT_EQ(attempt.matrix[2][3], 102);
  EXPECT_EQ(attempt.matrix[3][0], 16);
  EXPECT_EQ(attempt.matrix[3][1], 26);
  EXPECT_EQ(attempt.matrix[3][2], 46);
  EXPECT_EQ(attempt.matrix[3][3], 42);
}


TEST(MatrixOperationsTests, TupleMultiplicationTest)
{
  Matrix testMatrix;

  testMatrix.matrix[0][0] = 1;
  testMatrix.matrix[0][1] = 2;
  testMatrix.matrix[0][2] = 3;
  testMatrix.matrix[0][3] = 4;
  testMatrix.matrix[1][0] = 2;
  testMatrix.matrix[1][1] = 4;
  testMatrix.matrix[1][2] = 4;
  testMatrix.matrix[1][3] = 2;
  testMatrix.matrix[2][0] = 8;
  testMatrix.matrix[2][1] = 6;
  testMatrix.matrix[2][2] = 4;
  testMatrix.matrix[2][3] = 1;
  testMatrix.matrix[3][0] = 0;
  testMatrix.matrix[3][1] = 0;
  testMatrix.matrix[3][2] = 0;
  testMatrix.matrix[3][3] = 1;

  Tuple tuple(1, 2, 3, 1);

  Tuple attempt = testMatrix * tuple;

  EXPECT_EQ(attempt.GetX(), 18);
  EXPECT_EQ(attempt.GetY(), 24);
  EXPECT_EQ(attempt.GetZ(), 33);
  EXPECT_EQ(attempt.GetW(), 1);
}

TEST(MatrixOperationsTests, IdentityMatrixTest)
{
  //multiplying a matrix A by an identity matrix should equal the same matrix

  Matrix A;
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 2;
  A.matrix[0][3] = 4;

  A.matrix[1][0] = 1;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 4;
  A.matrix[1][3] = 8;

  A.matrix[2][0] = 2;
  A.matrix[2][1] = 4;
  A.matrix[2][2] = 8;
  A.matrix[2][3] = 32;

  A.matrix[3][0] = 4;
  A.matrix[3][1] = 8;
  A.matrix[3][2] = 16;
  A.matrix[3][3] = 32;

  Matrix result = A * A.identity();

  //check if both matricies have the same value 
  EXPECT_EQ(result.matrix[0][0], A.matrix[0][0]);
  EXPECT_EQ(result.matrix[0][1], A.matrix[0][1]);
  EXPECT_EQ(result.matrix[0][2], A.matrix[0][2]);
  EXPECT_EQ(result.matrix[0][3], A.matrix[0][3]);

  EXPECT_EQ(result.matrix[1][0], A.matrix[1][0]);
  EXPECT_EQ(result.matrix[1][1], A.matrix[1][1]);
  EXPECT_EQ(result.matrix[1][2], A.matrix[1][2]);
  EXPECT_EQ(result.matrix[1][3], A.matrix[1][3]);

  EXPECT_EQ(result.matrix[2][0], A.matrix[2][0]);
  EXPECT_EQ(result.matrix[2][1], A.matrix[2][1]);
  EXPECT_EQ(result.matrix[2][2], A.matrix[2][2]);
  EXPECT_EQ(result.matrix[2][3], A.matrix[2][3]);

  EXPECT_EQ(result.matrix[3][0], A.matrix[3][0]);
  EXPECT_EQ(result.matrix[3][1], A.matrix[3][1]);
  EXPECT_EQ(result.matrix[3][2], A.matrix[3][2]);
  EXPECT_EQ(result.matrix[3][3], A.matrix[3][3]);
}

TEST(MatrixOperationsTests, TransposeMatrixTest)
{
  Matrix A;
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 9;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 0;

  A.matrix[1][0] = 9;
  A.matrix[1][1] = 8;
  A.matrix[1][2] = 0;
  A.matrix[1][3] = 8;

  A.matrix[2][0] = 1;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 5;
  A.matrix[2][3] = 3;

  A.matrix[3][0] = 0;
  A.matrix[3][1] = 0;
  A.matrix[3][2] = 5;
  A.matrix[3][3] = 8;

  Matrix result = A.transpose();

  EXPECT_EQ(result.matrix[0][0], 0);
  EXPECT_EQ(result.matrix[0][1], 9);
  EXPECT_EQ(result.matrix[0][2], 1);
  EXPECT_EQ(result.matrix[0][3], 0);

  EXPECT_EQ(result.matrix[1][0], 9);
  EXPECT_EQ(result.matrix[1][1], 8);
  EXPECT_EQ(result.matrix[1][2], 8);
  EXPECT_EQ(result.matrix[1][3], 0);

  EXPECT_EQ(result.matrix[2][0], 3);
  EXPECT_EQ(result.matrix[2][1], 0);
  EXPECT_EQ(result.matrix[2][2], 5);
  EXPECT_EQ(result.matrix[2][3], 5);

  EXPECT_EQ(result.matrix[3][0], 0);
  EXPECT_EQ(result.matrix[3][1], 8);
  EXPECT_EQ(result.matrix[3][2], 3);
  EXPECT_EQ(result.matrix[3][3], 8);
}

TEST(MatrixOperationsTests, TransposeIdentityTest)
{
  Matrix A;

  //lazy way to ge an identity matrix, probably should do a better way later
  Matrix ident = A.identity();

  Matrix result = ident.transpose();

  EXPECT_EQ(result.matrix[0][0], ident.matrix[0][0]);
  EXPECT_EQ(result.matrix[0][1], ident.matrix[0][1]);
  EXPECT_EQ(result.matrix[0][2], ident.matrix[0][2]);
  EXPECT_EQ(result.matrix[0][3], ident.matrix[0][3]);

  EXPECT_EQ(result.matrix[1][0], ident.matrix[1][0]);
  EXPECT_EQ(result.matrix[1][1], ident.matrix[1][1]);
  EXPECT_EQ(result.matrix[1][2], ident.matrix[1][2]);
  EXPECT_EQ(result.matrix[1][3], ident.matrix[1][3]);

  EXPECT_EQ(result.matrix[2][0], ident.matrix[2][0]);
  EXPECT_EQ(result.matrix[2][1], ident.matrix[2][1]);
  EXPECT_EQ(result.matrix[2][2], ident.matrix[2][2]);
  EXPECT_EQ(result.matrix[2][3], ident.matrix[2][3]);

  EXPECT_EQ(result.matrix[3][0], ident.matrix[3][0]);
  EXPECT_EQ(result.matrix[3][1], ident.matrix[3][1]);
  EXPECT_EQ(result.matrix[3][2], ident.matrix[3][2]);
  EXPECT_EQ(result.matrix[3][3], ident.matrix[3][3]);
}

TEST(MatrixOperationsTests, 2x2DetTest)
{
  Matrix A;

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 5;
  A.matrix[1][0] = -3;
  A.matrix[1][1] = 2;

  float result = A.determinant();

  EXPECT_EQ(result, 17);
}

TEST(MatrixOperationsTests, 2x2SubmatrixTest)
{
  Matrix A;

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 0;

  A.matrix[1][0] = -3;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 7;

  A.matrix[2][0] = 0;
  A.matrix[2][1] = 6;
  A.matrix[2][2] = -3;

  Matrix result = A.submatrix(0, 2);

  EXPECT_EQ(result.matrix[0][0], -3);
  EXPECT_EQ(result.matrix[0][1], 2);
  EXPECT_EQ(result.matrix[1][0], 0);
  EXPECT_EQ(result.matrix[1][1], 6);
}

TEST(MatrixOperationsTests, 3x3SubmatrixTest)
{
  Matrix A;
  A.matrix[0][0] = -6;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 1;
  A.matrix[0][3] = 6;

  A.matrix[1][0] = -8;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 8;
  A.matrix[1][3] = 6;

  A.matrix[2][0] = -1;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 8;
  A.matrix[2][3] = 2;

  A.matrix[3][0] = -7;
  A.matrix[3][1] = 1;
  A.matrix[3][2] = -1;
  A.matrix[3][3] = 1;

  Matrix result = A.submatrix(2, 1);

  EXPECT_EQ(result.matrix[0][0], -6);
  EXPECT_EQ(result.matrix[0][1], 1);
  EXPECT_EQ(result.matrix[0][2], 6);

  EXPECT_EQ(result.matrix[1][0], -8);
  EXPECT_EQ(result.matrix[1][1], 8);
  EXPECT_EQ(result.matrix[1][2], 6);

  EXPECT_EQ(result.matrix[2][0], -7);
  EXPECT_EQ(result.matrix[2][1], -1);
  EXPECT_EQ(result.matrix[2][2], 1);
}

TEST(MatrixOperationsTests, 3x3MinorTest)
{
  Matrix A;
  A.matrix[0][0] = 3;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 0;

  A.matrix[1][0] = 2;
  A.matrix[1][1] = -1;
  A.matrix[1][2] = -7;

  A.matrix[2][0] = 6;
  A.matrix[2][1] = -1;
  A.matrix[2][2] = 6;

  float result = A.minor(1, 0);

  EXPECT_EQ(result, 25);
}

TEST(MatrixOperationsTests, 3x3CofactorTest)
{
  Matrix A;
  A.matrix[0][0] = 3;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 0;

  A.matrix[1][0] = 2;
  A.matrix[1][1] = -1;
  A.matrix[1][2] = -7;

  A.matrix[2][0] = 6;
  A.matrix[2][1] = -1;
  A.matrix[2][2] = 6;

  //gonna test two different row / col deletions to ensure it negates correctly
  float minorResult1 = A.minor(0, 0);
  float cofactorResult1 = A.cofactor(0, 0);

  float minorResult2 = A.minor(1, 0);
  float cofactorResult2 = A.cofactor(1, 0);

  EXPECT_EQ(minorResult1, -12);
  EXPECT_EQ(cofactorResult1, -12);

  EXPECT_EQ(minorResult1, 25);
  EXPECT_EQ(cofactorResult1, -25);
}