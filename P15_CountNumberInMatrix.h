#pragma once

#include <iostream>
using namespace std;

namespace P15_CountNumberInMatrix {


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



	void Task() {

		int arr[3][3] = { {9,1,12},{0,9,1} ,{0,9,9} };
		int ToCount;

		cout << "Matrix1:" << endl;
		PrintMatrix(arr, 3, 3);
		cout << "Enter the number to count in matrix? ";
		cin >> ToCount;
		cout << "\nNumber " << ToCount << " count in matrix is " << CountNumberInMatrix(arr, 3, 3, ToCount) << '\n';

	}

}
