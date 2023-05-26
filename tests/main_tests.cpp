#include <gtest/gtest.h>

//Lib includes
#include<tuple.h>

TEST (TuplePointVectorTests, TupleCreationTest_IsVector) {
    Tuple tuple(4.3, -4.2, 3.1, 0.0);

    EXPECT_EQ(tuple.GetX(), 4.3);
    EXPECT_EQ(tuple.GetY(), -4.2);
    EXPECT_EQ(tuple.GetZ(), 3.1);
    EXPECT_EQ(tuple.IsPoint(), 0.0);

}

TEST (TuplePointVectorTests, TupleCreationTest_IsPoint) {
    Tuple tuple(4.3, -4.2, 3.1, 1.0);

    EXPECT_EQ(tuple.GetX(), 4.3);
    EXPECT_EQ(tuple.GetY(), -4.2);
    EXPECT_EQ(tuple.GetZ(), 3.1);
    EXPECT_EQ(tuple.IsPoint(), 1.0);

}

TEST (TuplePointVectorTests, PointFactoryTest) {
    Tuple factory;
    Tuple point = factory.Point(4, -4, 3);

    EXPECT_EQ(point.GetX(), 4);
    EXPECT_EQ(point.GetY(), -4);
    EXPECT_EQ(point.GetZ(), 3);
    EXPECT_EQ(point.IsPoint(), 1);
}

TEST (TuplePointVectorTests, VectorFactoryTest) {

    EXPECT_EQ(point.GetX(), 4);
    EXPECT_EQ(point.GetY(), -4);
    EXPECT_EQ(point.GetZ(), 3);
    EXPECT_EQ(point.IsPoint(), 0);
}