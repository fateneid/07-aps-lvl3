#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace P39_JoinString {

	string JoinString(vector <string> vStrings, string Split) {
		string S = "";
		for (string& s1 : vStrings) {
			S += s1 + Split;
		}
		return S.substr(0, S.length() - Split.length());
	}

	void Task() {

		vector <string> vStrings = { "Ahmed","Ali","Lama" };
		cout << "vector after join:\n" << JoinString(vStrings, "-") << '\n';



	}

}
