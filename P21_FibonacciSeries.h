#pragma once

#include <iostream>
#include <vector>
using namespace std;

namespace P21_FibonacciSeries {


	void FibonacciSeries(vector<int>& vFibonacciNumbers,int To) {
		for (short i = 0; i < To - 2; i++) {
			int NextFib = vFibonacciNumbers[i] + vFibonacciNumbers[i + 1];
			vFibonacciNumbers.push_back(NextFib);
		}
	}

	void PrintFibonacciSeries(vector<int> vFibonacciNumbers) {
		for (int& FibonacciNumber : vFibonacciNumbers) {
			cout << FibonacciNumber << '\t';
		}
	}

	// another solution using only for loop (no vector)
	void FibonacciSeriesUsingOnlyLoop(short To) {
		int Prev1 = 1, Prev2 = 0, NextFib;
		cout << "1\t";
		for (short i = 2; i <= To; i++) {
			NextFib = Prev1 + Prev2;
			cout << NextFib << '\t';
			Prev2 = Prev1;
			Prev1 = NextFib;
		}
	}
	

	void Task() {

		vector<int> vFibonacciNumbers = { 1,1 };

		FibonacciSeries(vFibonacciNumbers, 10);
		cout << "Fibonacci Series:\n";
		PrintFibonacciSeries(vFibonacciNumbers);

		//FibonacciSeriesUsingOnlyLoop(10);


	}


}