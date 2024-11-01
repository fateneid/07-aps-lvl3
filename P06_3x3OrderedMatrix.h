#pragma once

#include <iostream>
using namespace std;

namespace P06_3x3OrderedMatrix {

	void FillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short Cols) {
		short Counter = 1;
		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Cols; j++) {
				arr[i][j] = Counter;
				Counter++;
			}
		}

	}

	void PrintMatrixWithOrderedNumbers(int arr[3][3], short Rows, short Cols) {
		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Cols; j++) {
				cout << setw(3) << arr[i][j] << '\t';
			}
			cout << '\n';
		}

	}
	void Task() {

		int arr[3][3];

		cout << "The following is a 3x3 ordered maatrix:" << endl;
		FillMatrixWithOrderedNumbers(arr, 3, 3);
		PrintMatrixWithOrderedNumbers(arr, 3, 3);

	}

}

