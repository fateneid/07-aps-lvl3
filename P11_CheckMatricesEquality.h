#pragma once

#include <iostream>
using namespace std;

namespace P11_CheckMatricesEquality {

	short RandomNumberInRange(short From, short To) {
		short RandomNumber = rand() % (To + 1 - From) + From;
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
				printf(" %0*d \t", 2, arr[i][j]);
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

	void CheckMatricesEquality(int arr1[3][3],short Rows1, short Cols1, 
		int arr2[3][3], short Rows2, short Cols2) {

		if (SumOfMatrix(arr1, Rows1, Cols1) == SumOfMatrix(arr2, Rows2, Cols2)) {
			cout << "Yes: both matrices are equal." << endl;
		}
		else {
			cout << "No: matrices are NOT equal." << endl;
		}
	}

	void Task() {

		srand((unsigned)time(NULL));

		int arr1[3][3], arr2[3][3];

		FillMatrixWithRandomNumbers(arr1, 3, 3);
		FillMatrixWithRandomNumbers(arr2, 3, 3);

		cout << "Matrix1:" << endl;
		PrintMatrix(arr1, 3, 3);
		cout << "\nMatrix2:" << endl;
		PrintMatrix(arr2, 3, 3);

		cout << '\n';

		CheckMatricesEquality(arr1, 3, 3, arr2, 3, 3);


	}

}
