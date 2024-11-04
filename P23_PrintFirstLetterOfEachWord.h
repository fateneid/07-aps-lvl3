#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace P23_PrintFirstLetterOfEachWord {

	string ReadString(string Message) {
		string MyString;
		cout << Message;
		getline(cin, MyString);
		return MyString;
	}

	void PrintFirstLetterOfEachWord(string MyString) {
		for (short i = 0; i <= MyString.length(); i++) {
			if (i == 0) {
				cout << MyString[i] << endl;
			}
			else if (MyString[i] == ' ') {
				cout << MyString[i + 1] << endl;
			}
		}
	}

	void PrintFirstLetterOfEachWordAnotherSolution(string MyString) {
		bool IsFirstLetter = true;

		for (short i = 0; i <= MyString.length(); i++) {
			if (MyString[i] != ' ' && IsFirstLetter) {
				cout << MyString[i] << endl;
			}
			IsFirstLetter = (MyString[i] == ' ' ? true : false);
	
		}

	}

	void Task() {

		cout << "\nFirst letters of this string: \n";
		PrintFirstLetterOfEachWordAnotherSolution(ReadString("Please Enter Your String?\n"));


	}



}
