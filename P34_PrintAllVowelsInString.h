#pragma once

#include <iostream>
#include <string> 
#include <cctype>
using namespace std;

namespace P34_PrintAllVowelsInString {

	string ReadString(string Message) {

		string MyString;
		cout << Message;
		getline(cin, MyString);
		return MyString;

	}

	bool IsVowel(char MyChar) {

		MyChar = tolower(MyChar);

		return((MyChar == 'a' || MyChar == 'e' || MyChar == 'i' || MyChar == 'o' || MyChar == 'u'));

	}

	void PrintAllVowelsInString(string MyString) {

		for (short i = 0; i < MyString.length(); i++) {

			if (IsVowel(MyString[i]))
				cout << MyString[i] << "   ";

		}

	}


	void Task() {

		string MyString = ReadString("Please Enter your string?\n");

		cout << "\nVowels in string are: ";
		PrintAllVowelsInString(MyString);
		cout << '\n';


	}

}