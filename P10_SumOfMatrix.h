#pragma once

#include <iostream>
using namespace std;

namespace P10_SumOfMatrix {

	short RandomNumberInRange(short From, short To) {
		short RandomNumber = rand() % (To + 1 - From);
		return RandomNumber;
	}

	void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols) {
		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Cols; j++) {
				arr[i][j] = RandomNumberInRange(1, 10);
			}
		}
	}

	void PrintMatrix(int arr[3][3], short Rows, short Cols) {
		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Cols; j++) {
				printf("%0*d \t", 2, arr[i][j]);
			}
			cout << '\n';
		}
	}

	int SumOfMatrix(int arr[3][3], short Rows, short Cols) {
		int Sum = 0;
		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Cols; j++) {
				Sum += arr[i][j];
			}
		}
		return Sum;

	}

	void Task() {

		srand((unsigned)time(NULL));

		int arr[3][3];

		FillMatrixWithRandomNumbers(arr, 3, 3);

		cout << "Matrix1:" << endl;
		PrintMatrix(arr, 3, 3);

		cout << "\nSum of Matrix1 is: " << SumOfMatrix(arr,3,3) << endl;

	}

}
