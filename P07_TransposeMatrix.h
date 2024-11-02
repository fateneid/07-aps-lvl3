#pragma once

#include <iostream>
#include <iomanip>
using namespace std;

namespace P07_TransposeMatrix {

	void FillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short Cols) {
		short Counter = 1;
		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Cols; j++) {
				arr[i][j] = Counter;
				Counter++;
			}
		}

	}

	void PrintMatrix(int arr[3][3], short Rows, short Cols) {
		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Cols; j++) {
				cout << setw(3) << arr[i][j] << '\t';
			}
			cout << '\n';
		}

	}

	void TransposeMatrix(int arr[3][3], int arrTransposed[3][3], short Rows, short Cols) {

		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Cols; j++) { //{{2,3,4},{3,5,8},{9,0,2}} 2 3 9  

				arrTransposed[i][j] = arr[j][i];
			}
		}
	}

	void Task() {

		int arr[3][3], arrTransposed[3][3];

		cout << "The following is a 3x3 ordered matrix:" << endl;
		FillMatrixWithOrderedNumbers(arr, 3, 3);
		PrintMatrix(arr, 3, 3);

		TransposeMatrix(arr, arrTransposed, 3, 3);
		cout << "\n\nThe following is the transposed matrix:" << endl;
		PrintMatrix(arrTransposed, 3, 3);



	}

}

