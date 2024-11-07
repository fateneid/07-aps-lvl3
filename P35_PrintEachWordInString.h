#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace P35_PrintEachWordInString {


	string ReadString(string Message) {

		string MyString;
		cout << Message;
		getline(cin, MyString);
		return MyString;

	}

	void PrintEachWordInString(string MyString) {
		for (short i = 0; i < MyString.length(); i++) {

			if (MyString[i] == ' ' && MyString[i - 1] != ' ') {
				cout << '\n';
				continue;
			}
			else if (MyString[i] != ' ') {
				cout << MyString[i] << "";
			}

		}
	}


	void PrintEachWordInStringProfSol(string MyString) {

		string delim = " ", sWord;
		short pos = 0;

		while ((pos = MyString.find(delim)) != string::npos) {

			sWord = MyString.substr(0, pos);
			if (sWord != "") {
				cout << sWord << endl;
			}

			MyString.erase(0, pos + delim.length());

		}

		if (MyString != "") {
			cout << MyString << endl;
		}

	}


	void Task() {

		string MyString = ReadString("Please Enter your string?\n");
		cout << "\nYour string words are:\n\n";
		PrintEachWordInString(MyString);
		cout << '\n';

	}

}
