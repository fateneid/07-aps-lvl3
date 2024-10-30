#pragma once

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

namespace P01_3x3RandomMatrix {

	int RandomNumbersInRange(int From, int To) {
		int RandomNumber = rand() % (To + 1 - From) + From;
		return RandomNumber;
	}

	void FillMatrixWithRandomNumbers(int arr[3][3]) {

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				arr[i][j] = RandomNumbersInRange(1, 100);
			}
		}

	}

	void PrintMatrix(int arr[3][3]) {

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << setw(3) << arr[i][j] << '\t';
			}
			cout << '\n';
		}

	}

	void Task() {

		srand((unsigned)time(NULL));

		int arr[3][3];

		cout << "The following is a 3x3 random matrix:" << endl;
		FillMatrixWithRandomNumbers(arr);
		PrintMatrix(arr);

		//system("pause>0");


	}


}

/*

 - RandomNumbersInRange
 - Fill2DArray   ->  FillMatrixWithRandomNumbers
 - Print2DArray  ->  PrintMatrix

*/
