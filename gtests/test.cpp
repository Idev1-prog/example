#include "pch.h"
#include "Triangle.h"

TEST(BaseTriangleTests, CreateTest) {
	Triangle test;
	EXPECT_FLOAT_EQ(0.5, test.calculate_area());
}
TEST(BaseTriangleTests, CopyTest) {
	Triangle test1(2, 33);
	Triangle test2(test1);
	Triangle test3;
	test3 = test2;
	EXPECT_FLOAT_EQ(33, test2.calculate_area());
	EXPECT_FLOAT_EQ(33, test3.calculate_area());
}
TEST(BaseTriangleTests, ManualCreateTest) {
	Triangle test(2, 3);
	EXPECT_FLOAT_EQ(3, test.calculate_area());
}
TEST(BaseTriangleTests, GetDataTest) {
	Triangle test(2.33, 6.11);
	EXPECT_FLOAT_EQ(test.get_hight(), 6.11);
	EXPECT_FLOAT_EQ(test.get_side(), 2.33);
}
TEST(BaseTriangleTests, SwichDataTest) {
	Triangle test(5, 10);
	EXPECT_FLOAT_EQ(25, test.calculate_area());
	test.set_hight(5);
	test.set_side(4);
	EXPECT_FLOAT_EQ(10, test.calculate_area());
}
TEST(ExceptionsTests, InvalidManualCreateTest) {
	EXPECT_ANY_THROW(Triangle test(-1, 10));
	EXPECT_ANY_THROW(Triangle test(1, 0));
	EXPECT_NO_THROW(Triangle test(10, 10.19341));
}
TEST(ExceptionsTests, InvalidSwichDataTest) {
	Triangle test(3, 11);
	EXPECT_NO_THROW(test.set_hight(3.1491));
	EXPECT_ANY_THROW(test.set_side(-5142));
	EXPECT_ANY_THROW(test.set_hight(0));
}
TEST(ConstructorEdgeCasesTests, ExtremeSmallPositiveValues) {
	EXPECT_NO_THROW(Triangle test(1e-10f, 1e-10f));
	EXPECT_NO_THROW(Triangle test(1e-30f, 5.0f));
	EXPECT_NO_THROW(Triangle test(1e-38f, 1e-38f));
}
TEST(ConstructorEdgeCasesTests, ExtremeLargePositiveValues) {
	EXPECT_NO_THROW(Triangle test(1e10f, 1e10f));
	EXPECT_NO_THROW(Triangle test(1e30f, 1e37f));
}
TEST(ConstructorEdgeCasesTests, ZeroValuesInvalid) {
	EXPECT_ANY_THROW(Triangle test(0.0f, 10.0f));
	EXPECT_ANY_THROW(Triangle test(10.0f, 0.0f));
	EXPECT_ANY_THROW(Triangle test(0.0f, 0.0f));
}
TEST(ConstructorEdgeCasesTests, NegativeValuesInvalid) {
	EXPECT_ANY_THROW(Triangle test(-1e-10f, 10.0f));
	EXPECT_ANY_THROW(Triangle test(10.0f, -1e-10f));

	EXPECT_ANY_THROW(Triangle test(-1e30f, 10.0f));
	EXPECT_ANY_THROW(Triangle test(10.0f, -1e30f));

	EXPECT_ANY_THROW(Triangle test(-1e37f, 1e37f));
}