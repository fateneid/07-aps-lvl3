#pragma once

#include <iostream>
using namespace std;

namespace P14_CheckScalarMatrixh {

	void PrintMatrix(int arr[3][3], short Rows, short Cols) {
		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Cols; j++) {
				printf(" %0*d \t", 1, arr[i][j]);
			}
			cout << '\n';
		}
	}

	bool CheckScalarMatrixh(int arr[3][3], short Rows, short Cols) {
		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Cols; j++) {
				if (i == j && arr[i][j] != arr[0][0]) {
					return false;
				}
				else if(i != j && arr[i][j] != 0)
					return false;
			}
		}
		return true;
	}

	void Task() {

		int arr[3][3] = { {9,0,0},{0,9,0} ,{0,0,9} };

		cout << "\nMatrix1:" << endl;
		PrintMatrix(arr, 3, 3);

		if (CheckScalarMatrixh(arr, 3, 3))
			cout << "\nYes: Matrix is Scalar." << endl;
		else
			cout << "\nNo: Matrix is NOT Scalar." << endl;

	}

}
