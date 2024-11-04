#pragma once

#include <iostream>
using namespace std;

namespace P22_FibonacciSeriesWithRecursion {

	void PrintFibonacciSeriesUsingRecursion(short To, short Prev2, short Prev1)
	{

		if (To > 0) {
			cout << Prev1 << '\t';
			PrintFibonacciSeriesUsingRecursion(To - 1, Prev1, Prev1 + Prev2);
		}

	}

	void Task() {

		PrintFibonacciSeriesUsingRecursion(10, 0, 1);


	}

}

