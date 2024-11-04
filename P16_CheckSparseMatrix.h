#pragma once

#include <iostream>
using namespace std;

namespace P16_CheckSparseMatrix {

	void PrintMatrix(int arr[3][3], short Rows, short Cols) {

		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Cols; j++) {
				cout << " " << arr[i][j] << '\t';
			}
			cout << '\n';
		}
	}

	short CountNumberInMatrix(int arr[3][3], short Rows, short Cols, int ToCount) {

		short Counter = 0;

		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Cols; j++) {
				if (arr[i][j] == ToCount) {
					Counter++;
				}
			}
		}
		return Counter;

	}

	bool CheckSparseMatrix(int arr[3][3], short Rows, short Cols) {
		short MatrixSize = Rows * Cols;

		return(CountNumberInMatrix(arr, 3, 3, 0) >= (MatrixSize / 2));
	
	}

	void Task() {
		//{ { 0, 0, 12 }, { 0,6,1 }, { 7,9,9 } };
		int arr[3][3] = { { 0, 0, 12 }, { 0,0,1 }, { 0,0,9 } };
		int ToCount;

		cout << "Matrix1:" << endl;
		PrintMatrix(arr, 3, 3);

		if (CheckSparseMatrix(arr, 3, 3))
			cout << "\nYes: It is Sparse." << endl;
		else
			cout << "\nNo: It's NOT Sparse." << endl;


	}

}
