#pragma once

#include <iostream>
using namespace std;

namespace P19_MinAndMaxNumberInMatrix {

	void PrintMatrix(int arr[3][3], short Rows, short Cols) {

		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Cols; j++) {
				cout << " " << arr[i][j] << '\t';
			}
			cout << '\n';
		}

	}

	int MaxNumberInMatrix(int arr[3][3], short Rows, short Cols) {
		int Max = arr[0][0];
		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Cols; j++) {
				if (arr[i][j] > Max) {
					Max = arr[i][j];
				}
			}
		}
		return Max;
	}

	int MinNumberInMatrix(int arr[3][3], short Rows, short Cols) {
		int Min = arr[0][0];
		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Cols; j++) {
				if (arr[i][j] < Min) {
					Min = arr[i][j];
				}
			}
		}
		return Min;
	}

	void Task() {

		int arr[3][3] = { {77,5,12},{22,20,6} ,{14,3,9} };

		cout << "Matrix1:" << endl;
		PrintMatrix(arr, 3, 3);

		cout << "\nMinimum Number is: " << MinNumberInMatrix(arr, 3, 3) << '\n';
		cout << "\nMax Number is: " << MaxNumberInMatrix(arr, 3, 3) << '\n';


	}

}
