#pragma once

#include <iostream>
#include <iomanip>
using namespace std;

namespace P03_SumEachRowInMatrixInArray {

	int RandomNumberInRange(int From, int To) {
		int RandomNumber = rand() % (To + 1 - From);
		return RandomNumber;
	}

	void FillMatrixWithRandomNumbers(int arr[3][3], int Rows, int Cols) {

		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {

				arr[i][j] = RandomNumberInRange(1, 100);

			}
		}

	}

	void PrintMatrix(int arr[3][3], int Rows, int Cols) {

		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {

				cout << setw(3) << arr[i][j] << '\t';

			}
			cout << '\n';
		}

	}

	void SumOfRowsInMatrix(int arr[3][3], int Rows, int Cols) {

		int arrSumRows[3] = { 0,0,0 };

		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {

				arrSumRows[i] += arr[i][j];
			}
			cout << " Row " << i + 1 << " Sum = " << arrSumRows[i] << endl;
			
		}

	}


	void Task() {

		srand((unsigned)time(NULL));

		int arr[3][3];

		cout << "The following is a 3x3 random matrix:" << endl;

		FillMatrixWithRandomNumbers(arr, 3, 3);
		PrintMatrix(arr, 3, 3);
		cout << "\nThe following are the Sum of each row in the matrix:" << endl;
		SumOfRowsInMatrix(arr, 3, 3);

	}



}
