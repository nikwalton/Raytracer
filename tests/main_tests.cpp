#include <gtest/gtest.h>

#include<math.h>

//My Lib includes
#include "tuple.h"
#include "vector.h"
#include "point.h"
#include "color.h"


 //START OF TUPLE, POINT, VECTOR TEST SUITE
TEST (TuplePointVectorTests, TupleCreationTest_IsVector) {
    Tuple tuple(4.3, -4.2, 3.1, 0);

    EXPECT_FLOAT_EQ(tuple.GetX(), 4.3);
    EXPECT_FLOAT_EQ(tuple.GetY(), -4.2);
    EXPECT_FLOAT_EQ(tuple.GetZ(), 3.1);
    EXPECT_FLOAT_EQ(tuple.IsPoint(), false);

}

TEST (TuplePointVectorTests, TupleCreationTest_IsPoint) {
    Tuple tuple(4.3, -4.2, 3.1, 1);

    EXPECT_FLOAT_EQ(tuple.GetX(), 4.3);
    EXPECT_FLOAT_EQ(tuple.GetY(), -4.2);
    EXPECT_FLOAT_EQ(tuple.GetZ(), 3.1);
    EXPECT_FLOAT_EQ(tuple.IsPoint(), true);

}

TEST (TuplePointVectorTests, PointTest) {
    Point point(4, -4, 3);
    

    EXPECT_EQ(point.GetX(), 4);
    EXPECT_EQ(point.GetY(), -4);
    EXPECT_EQ(point.GetZ(), 3);
    EXPECT_EQ(point.IsPoint(), true);
}

TEST (TuplePointVectorTests, VectorFactoryTest) {
    Vector vector(4, -4, 3);

    EXPECT_EQ(vector.GetX(), 4);
    EXPECT_EQ(vector.GetY(), -4);
    EXPECT_EQ(vector.GetZ(), 3);
    EXPECT_EQ(vector.IsPoint(), 0);
}

TEST (TuplePointVectorTests, EqualOperatorTest) {
    Tuple tuple(4.3, -4.2, 3.1, 0);
    Tuple tuple2(4.3, -4.2, 3.1, 0);
    Tuple tuple3(3.2, 3.2, 3.2, 1);

    EXPECT_EQ(tuple == tuple2, true);
    EXPECT_EQ(tuple == tuple3, false);
}

TEST (TuplePointVectorTests, AddOperatorTest) {
    Tuple tuple(3, -2, 5, 1);
    Tuple tuple2(-2, 3, 1, 0);
    // solution (1, 1, 6, 1);
    Tuple attempt = tuple + tuple2;

    EXPECT_EQ(attempt.GetX(), 1);
    EXPECT_EQ(attempt.GetY(), 1);
    EXPECT_EQ(attempt.GetZ(), 6);
    EXPECT_EQ(attempt.IsPoint(), true);
}

TEST (TuplePointVectorTests, SubtractOperatorTest_PointFromPoint) {
    //subtracting two points result in a vector
    Point p1(3, 2, 1);
    Point p2(5,6,7);
    //solution Vector (-2, -4, -6);
    Tuple attempt = p1 - p2;


    EXPECT_EQ(attempt.GetX(), -2);
    EXPECT_EQ(attempt.GetY(), -4);
    EXPECT_EQ(attempt.GetZ(), -6);
    EXPECT_EQ(attempt.IsPoint(), false);
}

TEST(TuplePointVectorTests, SubtractOperatorTest_VecFromPoint) {
    //subtracting a vector from a point results in a point
    Point p(3,2,1); 
    Vector v(5,6,7);
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

    EXPECT_FLOAT_EQ(attempt.GetX(), 1/sqrt(14));
    EXPECT_FLOAT_EQ(attempt.GetY(), 2/sqrt(14));
    EXPECT_FLOAT_EQ(attempt.GetZ(), 3/sqrt(14));
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
