#pragma once

#include <iostream>
using namespace std;

namespace P27_InvertCharcterCase {

	char ReadCharcter(string Message) {
		char MyChar;
		cout << Message;
		cin >> MyChar;
		return MyChar;
	}

	/*char InvertCharcterCase(char MyChar) {

		short ASCII = static_cast<int>(MyChar);
		if (ASCII >= 65 && ASCII <= 90) {
			return tolower(MyChar);
		}
		else if (ASCII >= 97 && ASCII <= 122) {
			return toupper(MyChar);

		}

	}*/

	char InvertCharcterCase(char MyChar) {
		return isupper(MyChar) ? tolower(MyChar) : toupper(MyChar);
	}

	void Task() {

		char MyChar = ReadCharcter("Please Enter Your String?\n");
		cout << "\nChar after invertig case: \n" << InvertCharcterCase(MyChar) << '\n';


	}

}
