#include <gtest/gtest.h>

TEST(TestFibonacci, NormalInputs) {
	EXPECT_EQ(Fibonacci(0), 1);
	EXPECT_EQ(Fibonacci(1), 1);
	EXPECT_EQ(Fibonacci(2), 2);
	EXPECT_EQ(Fibonacci(3), 3);
	EXPECT_EQ(Fibonacci(4), 5);
}

TEST(TestMultiply, SpecialInputs) {
	EXPECT_EQ(Fibonacci(-1), -1);

}