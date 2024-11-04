#pragma once

#include <iostream>
using namespace std;

namespace P17_NumberExistsInMatrix {

	void PrintMatrix(int arr[3][3], short Rows, short Cols) {

		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Cols; j++) {
				cout << " " << arr[i][j] << '\t';
			}
			cout << '\n';
		}


	}

	bool IsNumberExistInMatrix(int arr[3][3], short Rows, short Cols, int Search) {
		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Cols; j++) {
				if (arr[i][j] == Search) {
					return true;
				}
			}
		}
		return false;

	}

	void Task() {

		int arr[3][3] = { {9,1,12},{0,9,1} ,{0,9,9} };
		int Search;

		cout << "Matrix1:" << endl;
		PrintMatrix(arr, 3, 3);
		cout << "\nPlease Enter the number to look for in matrix? ";
		cin >> Search;

		if (IsNumberExistInMatrix(arr, 3, 3,Search))
			cout << "\nYes it is there." << endl;
		else
			cout << "\nNo it's NOT there." << endl;


	}

}