#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace P38_TrimLeftTrimRightTrim {

	string ReadString(string Message) {
		string MyString;
		cout << Message;
		getline(cin, MyString);
		return MyString;
	}

	string TrimLeft(string MyString) {

		for (short i = 0; i < MyString.length(); i++) {
			if (MyString[i] != ' ') {
				MyString.erase(0, i);
				return MyString;
			}
		}

		return "";

	}

	string TrimRight(string MyString) {

		for (short i = MyString.length() - 1; i >= 0; i--) {
			if (MyString[i] != ' ') {
				MyString.erase(i + 1, MyString.length());
				return MyString;
			}
		}

		return "";

	}

	string Trim(string MyString) {

		return TrimRight(TrimLeft(MyString));

	}


	void Task() {

		string MyString = ReadString("Please Enter Your String?\n\n");
		cout << "Trim Left  = " << '|' << TrimLeft(MyString) << '|' << endl;
		cout << "Trim Right = " << '|' << TrimRight(MyString) << '|' << endl;
		cout << "Trim       = " << '|' << Trim(MyString) << '|' << endl;

	}

	// we can solve it using substr as the teacher


}
