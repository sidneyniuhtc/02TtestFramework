#include <gtest/gtest.h>

#include "vive/math/Fractor.hpp"

using namespace vive::math;

TEST(TestFractor, NormalInputs) {
	using std::vector;
	using std::cout;
	
	vector<int> p;
	vector<int> k;

	Fractor(33, p, k);

	vector<int> true_p;
	vector<int> true_k;

	for (int i = 0; i < true_p.size(); ++i)
	{
		EXPECT_EQ(p[i], true_p[i]);
		EXPECT_EQ(k[i], true_k[i]);
	}
}