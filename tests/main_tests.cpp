#include <gtest/gtest.h>

//Lib includes
#include<tuple.h>

 
TEST (TuplePointVectorTests, TupleCreationTest_IsVector) {
    Tuple tuple(4.3, -4.2, 3.1, 0);

    EXPECT_EQ(tuple.GetX(), (float)4.3);
    EXPECT_EQ(tuple.GetY(), (float)-4.2);
    EXPECT_EQ(tuple.GetZ(), (float)3.1);
    EXPECT_EQ(tuple.IsPoint(), false);

}

TEST (TuplePointVectorTests, TupleCreationTest_IsPoint) {
    Tuple tuple(4.3, -4.2, 3.1, 1);

    EXPECT_EQ(tuple.GetX(), (float)4.3);
    EXPECT_EQ(tuple.GetY(), (float)-4.2);
    EXPECT_EQ(tuple.GetZ(), (float)3.1);
    EXPECT_EQ(tuple.IsPoint(), true);

}

TEST (TuplePointVectorTests, PointFactoryTest) {
    Tuple factory;
    Tuple point = factory.Point(4, -4, 3);

    EXPECT_EQ(point.GetX(), 4);
    EXPECT_EQ(point.GetY(), -4);
    EXPECT_EQ(point.GetZ(), 3);
    EXPECT_EQ(point.IsPoint(), true);
}

TEST (TuplePointVectorTests, VectorFactoryTest) {
    Tuple factory;
    Tuple vector = factory.Vector(4, -4, 3);

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
    Tuple factory;
    Tuple p1 = factory.Point(3, 2, 1);
    Tuple p2 = factory.Point(5, 6, 7);
    //solution Vector (-2, -4, -6);
    Tuple attempt = p1 - p2;


    EXPECT_EQ(attempt.GetX(), -2);
    EXPECT_EQ(attempt.GetY(), -4);
    EXPECT_EQ(attempt.GetZ(), -6);
    EXPECT_EQ(attempt.IsPoint(), false);
}

TEST(TuplePointVectorTests, SubtractOperatorTest_VecFromPoint) {
    //subtracting a vector from a point results in a point
    Tuple factory;
    Tuple p = factory.Point(3, 2, 1);
    Tuple v = factory.Vector(5 , 6, 7);
    // solution Point (-2, -4, -6);
    Tuple attempt = p - v;

    EXPECT_EQ(attempt.GetX(), -2);
    EXPECT_EQ(attempt.GetY(), -4);
    EXPECT_EQ(attempt.GetZ(), -6);
    EXPECT_EQ(attempt.IsPoint(), true);
}

TEST(TuplePointVectorTests, SubtractOperatorTest_VecFromVec) {
    Tuple factory;
    Tuple v1 = factory.Vector(3 , 2, 1);
    Tuple v2 = factory.Vector(5, 6, 7);
    //solution Vector (-2, -4, -6)
    Tuple attempt = v1 - v2;


    EXPECT_EQ(attempt.GetX(), -2);
    EXPECT_EQ(attempt.GetY(), -4);
    EXPECT_EQ(attempt.GetZ(), -6);
    EXPECT_EQ(attempt.IsPoint(), false);
}

TEST(TuplePointVectorTests, SubtractOperatorTest_ZeroFromVec) {
    Tuple factory;
    Tuple zero = factory.Vector(0,0,0);
    Tuple v = factory.Vector(1, -2, 3);
    //solution Vector (-1, 2, -3);
    Tuple attempt = zero - v;


    EXPECT_EQ(attempt.GetX(), -1);
    EXPECT_EQ(attempt.GetY(), 2);
    EXPECT_EQ(attempt.GetZ(), -3);
    EXPECT_EQ(attempt.IsPoint(), false);
}

TEST(TuplePointVectorTets, NegationOperatorTest) {
    Tuple tuple(1, -2, 3, -4);
    Tuple attempt = -tuple;


    EXPECT_EQ(attempt.GetX(), -1);
    EXPECT_EQ(attempt.GetY(), 2);
    EXPECT_EQ(attempt.GetZ(), -3);
    EXPECT_EQ(attempt.GetW(), 4);
}