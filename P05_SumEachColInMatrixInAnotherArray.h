#pragma once

#include <iostream>
#include <iomanip>
using namespace std;

namespace P05_SumEachColInMatrixInAnotherArray {

	int RandomNumberInRange(int From, int To) {
		int RandomNumber = rand() % (To + 1 - From);
		return RandomNumber;
	}

	void FillMatrixWithRandomNumbers(int arr[3][3],int Rows, int Cols) {
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

	void SumOfColsInMatrix(int arr[3][3],int arrSum[3], int Rows, int Cols) {

		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {

				arrSum[i] += arr[j][i];    

			}

		}
	}

	void PrintSumOfColsInMatrix(int arrSum[3], int Cols) {

		cout << "\nThe following are the Sum of each Col in the matrix:" << endl;

		for (int i = 0; i < Cols; i++) {
			cout << " Col " << i + 1 << " Sum = " << arrSum[i] << endl;
		}
		
	}


	void Task() {


		srand((unsigned)time(NULL));

		int arr[3][3], arrSum[3] = { 0,0,0 };

		FillMatrixWithRandomNumbers(arr, 3, 3);

		cout << "The following is a 3x3 random matrix:" << endl;
		PrintMatrix(arr, 3, 3);

		SumOfColsInMatrix(arr, arrSum, 3, 3);
		PrintSumOfColsInMatrix(arrSum, 3);


	}


}
