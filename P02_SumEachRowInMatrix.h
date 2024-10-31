#pragma once

#include <iostream>
using namespace std;

namespace P02_SumEachRowInMatrix {

	int RandomNumbersInRange(int From, int To) {

		int RandomNumber = rand() % (To + 1 - From) + From;
		return RandomNumber;

	}

	void FillMatrixWithRandomNumbers(int arr[3][3], int Rows, int Cols) {

		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {

				arr[i][j] = RandomNumbersInRange(1,100);

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

		int Sum = 0;

		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {

				Sum += arr[i][j];
			}
			cout << " Row " << i + 1 << " Sum = " << Sum << endl;
			Sum = 0;
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

