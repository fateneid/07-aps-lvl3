#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace P44_RemovePunctuations {

	string ReadString(string Message) {
		string MyString;
		cout << Message;
		getline(cin, MyString);
		return MyString;
	}

	string RemovePunctuations(string MyString) {

		string S = "";

		for (short i = 0; i < MyString.length(); i++) {

			if (!ispunct(MyString[i])) {
				S += MyString[i];
			}
		}

		return S;

	}


	void Task(){

		string MyString = ReadString("Please Enter Your String?\n");

		cout << "\nOriginal String:\n";
		cout << MyString << endl;
		cout << "\nPunctuations Removed:\n";
		cout << RemovePunctuations(MyString) << endl;
		
	
	
	}

}

