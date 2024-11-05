#pragma once

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

namespace P28_InvertAllLettersCase {

	string ReadString(string Message) {
		string MyString;
		cout << Message;
		getline(cin, MyString);
		return MyString;
	}

	char InvertCharcterCase(char MyChar) {
		return isupper(MyChar) ? tolower(MyChar) : toupper(MyChar);
	}

	string InvertAllLettersCase(string MyString) {

		for (short i = 0; i < MyString.length(); i++) {
			MyString[i] = InvertCharcterCase(MyString[i]);
		}

		return MyString;

	}


	void Task() {

		string MyString = ReadString("Please Enter Your String?\n");
		cout << "\String after Invert All Letters Case: \n" << InvertAllLettersCase(MyString) << '\n';


	}


}