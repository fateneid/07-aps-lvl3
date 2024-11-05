#pragma once

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

namespace P26_UpperAndLowerAllLettersOfAString {

	string ReadString(string Message) {
		string MyString;
		cout << Message;
		getline(cin, MyString);
		return MyString;
	}

	string UpperAllLettersOfAString(string MyString) {
		for (short i = 0; i < MyString.length(); i++) {
			MyString[i] = toupper(MyString[i]);
		}
		return MyString;
	}

	string LowerAllLettersOfAString(string MyString) {
		for (short i = 0; i < MyString.length(); i++) {
			MyString[i] = tolower(MyString[i]);
		}
		return MyString;
	}



	void Task() {

		string MyString = ReadString("Please Enter Your String?\n");
		cout << "\nString after Upper: \n" << UpperAllLettersOfAString(MyString) << '\n';
		cout << "\nString after Lower: \n" << LowerAllLettersOfAString(MyString) << '\n';


	}

}
