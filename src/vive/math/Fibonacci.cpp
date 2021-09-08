#include "vive/math/Fibonacci.hpp"


int vive::math::Fibonacci(int n)
{
	int n_2 = 1;
	int n_1 = 1;

	if (n == 0)
	{
		return 1;
	}
	else if (n == 1)
	{
		return 1;
	}
	else if (n > 0)
	{
		for (int i = 2; i < n; ++i)
		{
			int n_0 = n_2 + n_1;
			n_2 = n_1;
			n_1 = n_0;
		}
		return n_1;
	}


	return -1;
}
