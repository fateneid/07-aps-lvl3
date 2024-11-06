#pragma once

#include <iostream>
#include <string> 
#include <cctype>
using namespace std;

namespace P33_CountVowel {

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

	short CountVowelInString(string MyString) {

		short Counter = 0;

		for (short i = 0; i < MyString.length(); i++) {

			if (IsVowel(MyString[i]))
				Counter++;

		}

		return Counter;
	}


	void Task() {

		string MyString = ReadString("Please Enter your string?\n");

		cout << "\nNumber of vowels is: " << CountVowelInString(MyString) << endl;


	}

}
