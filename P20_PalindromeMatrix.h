#pragma once

#include <iostream>
using namespace std;

namespace P20_PalindromeMatrix {

	void PrintMatrix(int arr[3][3], short Rows, short Cols) {

		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Cols; j++) {
				cout << " " << arr[i][j] << '\t';
			}
			cout << '\n';
		}


	}

	bool IsAPalindromeMatrix(int arr[3][3], short Rows, short Cols) {

		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Cols/2; j++) {
				if (arr[i][j] != arr[i][Cols -1 -j]) {
					return false;
				}
			}
		}
		return true;

	}

	void Task() {

		int arr[3][3] = { {1,2,1},{5,5,5} ,{7,3,7} };

		cout << "Matrix1:" << endl;
		PrintMatrix(arr, 3, 3);

		if (IsAPalindromeMatrix(arr, 3, 3))
			cout << "\nYes: Matrix is Palindrome" << endl;
		else
			cout << "\nNo: Matrix is NOT Palindrome" << endl;



	}


}


