#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace P25_LowerFirstLetterOfEachWord {

	string ReadString(string Message) {
		string Mystring;
		cout << Message;
		getline(cin, Mystring);
		return Mystring;
	}

	string LowerFirstLetterOfEachWord(string MyString) {
		bool IsFirstLetter = true;
		for (short i = 0; i < MyString.length(); i++) {
			if (MyString[i] != ' ' && IsFirstLetter) {
				MyString[i] = tolower(MyString[i]);
			}
			IsFirstLetter = (MyString[i] == ' ' ? true : false);
		}
		return MyString;
	}

	void Task() {

		string MyString = ReadString("Please Enter Your String?\n");
		cout << "\nString after conversion: \n" << LowerFirstLetterOfEachWord(MyString) << '\n';
		
	}




}
