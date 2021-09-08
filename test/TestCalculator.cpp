#include <gtest/gtest.h>

TEST(TestAdd, NormalInputs) {
	EXPECT_EQ(Add(0, 1), 1);
	EXPECT_EQ(Add(2, 3), 5);
}

TEST(TestMultiply, NormalInputs) {
	EXPECT_EQ(Multiply(0, 1), 0);
	EXPECT_EQ(Multiply(2, 3), 6);
}

