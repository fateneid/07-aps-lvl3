#pragma once

#include <iostream>
using namespace std;

namespace P12_CheckTypicalMatrices {

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

	bool CheckTypicalMatrices(int arr1[3][3], int arr2[3][3], short Rows, short Cols) {

		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Cols; j++) {
				if (arr1[i][j] != arr2[i][j]) {
					return false;
				}
			}
		}
		return true;

	}

	void Task() {

		srand((unsigned)time(NULL));

		int arr1[3][3], arr2[3][3];

		FillMatrixWithRandomNumbers(arr1, 3, 3);
		cout << "Matrix1:" << endl;
		PrintMatrix(arr1, 3, 3);

		FillMatrixWithRandomNumbers(arr2, 3, 3);
		cout << "\nMatrix2:" << endl;
		PrintMatrix(arr2, 3, 3);

		if (CheckTypicalMatrices(arr1, arr2, 3, 3))
			cout << "\nYes: both matrices are equal." << endl;
		else 
			cout << "\nNo: matrices are NOT equal." << endl;

	}

}