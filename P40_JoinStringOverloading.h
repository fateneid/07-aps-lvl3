#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace P40_JoinStringOverloading {

	string JoinString(vector <string> vStrings, string Split) {
		string S = "";
		for (string& s1 : vStrings) {
			S += s1 + Split;
		}
		return S.substr(0, S.length() - Split.length());
	}

	string JoinString(string arrStrings[3], short arrLength, string Split) {
		string S = "";
		for (short i = 0; i < arrLength; i++) {
			S += arrStrings[i] + Split;
		}
		return S.substr(0, S.length() - Split.length());
	}

	void Task() {

		vector <string> vStrings = { "Ahmed","Ali","Lama" };
		string arrStrings[] = { "Ahmed","Ali","Lama" };

		cout << "Vector after join:\n" << JoinString(vStrings, "-") << '\n';
		cout << "Array after join:\n" << JoinString(arrStrings, 3, "-") << '\n';




	}

}