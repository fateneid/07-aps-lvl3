#pragma once

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

namespace P24_UpperFirstLetterOfEachWord {

	string ReadString(string Message) {
		string MyString;
		cout << Message;
		getline(cin, MyString);
		return MyString;
	}

	string UpperFirstLetterOfEachWord(string MyString) {
		bool IsFirstLetter = true;

		for (short i = 0; i < MyString.length(); i++) {
			if (MyString[i] != ' ' && IsFirstLetter) {
				MyString[i] = toupper(MyString[i]);
			}

			IsFirstLetter = (MyString[i] == ' ' ? true : false);
		}

		return MyString;
	}

	void Task() {

		string MyString = ReadString("Please Enter Your String?\n");
		cout << "\nString after conversion: \n" << UpperFirstLetterOfEachWord(MyString) << '\n';

	}



}
