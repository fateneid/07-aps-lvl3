#pragma once

#include <iostream>
#include <Cmath>
using namespace std;

namespace P09_PrintMiddleRowAndColOfMatrix {

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
				printf("%0*d \t", 2, arr[i][j]);
			}
			cout << '\n';
		}
	}

	void PrintMiddleRowOfMatrix(int arr[3][3], short Rows, short Cols) {
		short MiddleRow = Rows / 2;
		for (short i = 0; i < Cols; i++) {
			printf("%0*d \t", 2, arr[MiddleRow][i]);
		}
		cout << '\n';
	}

	void PrintMiddleColOfMatrix(int arr[3][3], short Rows, short Cols) {
		short MiddleCol = Rows / 2;
		for (short i = 0; i < Rows; i++) {
			printf("%0*d \t", 2, arr[i][MiddleCol]);
		}
		cout << '\n';
	}

	void Task() {

		srand((unsigned)time(NULL));

		int arr[3][3];

		FillMatrixWithRandomNumbers(arr, 3, 3);
		cout << "Matrix1:" << endl;
		PrintMatrix(arr, 3, 3);

		cout << "\nMiddle Row of Matrix1 is:\n";
		PrintMiddleRowOfMatrix(arr, 3, 3);
		cout << "\nMiddle Col of Matrix1 is:\n";
		PrintMiddleColOfMatrix(arr, 3, 3);


	}

}



