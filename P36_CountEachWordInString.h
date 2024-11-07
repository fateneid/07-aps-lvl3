#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace P36_CountEachWordInString {


	string ReadString(string Message) {

		string MyString;
		cout << Message;
		getline(cin, MyString);
		return MyString;

	}

	short CountEachWordInString(string MyString) {
		short Counter = 1;

		for (short i = 0; i < MyString.length(); i++) {

			if (MyString[i] == ' ' && MyString[i - 1] != ' ') {
				Counter++;
			}

		}
		return Counter;
	}

	short CountEachWordInStringAnotherSol(string MyString) {
	
		string delim = " ", sWord;
		short pos = 0, Counter = 0;

		while ((pos = MyString.find(delim)) != string::npos) {

			sWord = MyString.substr(0, pos);
			if (sWord != "") {
				Counter++;
			}
			MyString.erase(0, pos + delim.length());
		}

		if (MyString != "") {
			Counter++;
		}

		return Counter;
	}


	void Task() {

		string MyString = ReadString("Please Enter your string?\n");
		cout << "\nThe number of words in your string is: " << CountEachWordInString(MyString) << endl;
		cout << "\nUsing another method: " << endl;
		cout << "\nThe number of words in your string is: " << CountEachWordInStringAnotherSol(MyString) << endl;

	}

}