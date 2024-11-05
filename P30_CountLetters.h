#pragma once

#include <iostream>
#include <string> 
using namespace std;

namespace P30_CountLetters {

	string ReadString(string Message) {
		string MyString;
		cout << Message;
		getline(cin, MyString);
		return MyString;
	}

	char ReadCharcter(string Message) {
		char MyChar;
		cout << Message;
		cin >> MyChar;
		return MyChar;
	}

	short CountLetters(string MyString,char Letter) {
		short Counter = 0;
		for (short i = 0; i < MyString[i]; i++) {
			if (MyString[i] == Letter) {
				Counter++;
			}
		}
		return Counter;
	}

	void Task() {

		string MyString = ReadString("Please Enter Your String?\n");

		char Letter = ReadCharcter("\nPlease Enter a Charcter?\n");

		cout << "\nLetter '" << Letter << "' Count = " << CountLetters(MyString, Letter) << endl;


	}

}
