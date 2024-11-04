#pragma once

#include <iostream>
using namespace std;

namespace P18_IntersectedNumbersInMatrices {

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

	void IntersectedNumbersInMatrices(int arr1[3][3], int arr2[3][3], short Rows, short Cols) {
		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Cols; j++) {
				if (IsNumberExistInMatrix(arr2,Rows,Cols,arr1[i][j])) {
					cout << arr1[i][j] << '\t';
				}
			}
		}

	}

	void Task() {

		int arr1[3][3] = { {77,5,12},{22,20,1} ,{1,0,9} };
		int arr2[3][3] = { {5,80,90},{22,77,1} ,{10,8,33} };


		cout << "Matrix1:" << endl;
		PrintMatrix(arr1, 3, 3);
		cout << "\nMatrix2:" << endl;
		PrintMatrix(arr2, 3, 3);

		cout << "\nIntersected Numbers are:\n\n";
		IntersectedNumbersInMatrices(arr1, arr2, 3, 3);
		cout << '\n';

	}

}