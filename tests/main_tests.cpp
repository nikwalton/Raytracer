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