#pragma once

#include <iostream>
using namespace std;

namespace P13_CheckIdentityMatrix {

	void PrintMatrix(int arr[3][3], short Rows, short Cols) {
		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Cols; j++) {
				printf(" %0*d \t", 1, arr[i][j]);
			}
			cout << '\n';
		}
	}

	bool CheckIdentityMatrix(int arr[3][3], short Rows, short Cols) {
		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Cols; j++) {
				if (i == j && arr[i][j] != 1)
					return false;
				else if (i != j && arr[i][j] != 0)
					return false;
			}
		}
		return true;
	}
	// 00 11 22    1 
	// 01 02 10 12 20 21    0 

	void Task() {

		int arr[3][3] = { {1,0,0},{0,1,0},{0,0,1} }; 

		cout << "Matrix1:" << endl;
		PrintMatrix(arr, 3, 3);
		               
		if (CheckIdentityMatrix(arr, 3, 3))
			cout << "\nYes: Matrix is identity." << endl;
		else
			cout << "\nNo: Matrix is NOT identity." << endl;

	}

}