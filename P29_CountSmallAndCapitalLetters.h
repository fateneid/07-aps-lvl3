#pragma once

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

namespace P29_CountSmallAndCapitalLetters {

	enum enWhatToCount { CapitalLetters = 0, SmallLetters = 1, All = 3 };

	short CountLetters(string MyString, enWhatToCount WhatToCount = enWhatToCount::All) {

		if (WhatToCount == enWhatToCount::All) {
			return MyString.length();
		}

		short Counter = 0;
		for (short i = 0; i < MyString.length(); i++) {
			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(MyString[i])) {
				Counter++;
			}
			else if (WhatToCount == enWhatToCount::SmallLetters && islower(MyString[i])) {
				Counter++;
			}
		}
		return Counter;


	}

	string ReadString(string Message) {
		string MyString;
		cout << Message;
		getline(cin, MyString);
		return MyString;
	}

	short CountCapitalLetters(string MyString) {
		short Counter = 0;
		for (short i = 0; i < MyString.length(); i++) {
			if (isupper(MyString[i])) {
				Counter++;
			}
		}
		return Counter;
	}

	short CountSmallLetters(string MyString) {
		short Counter = 0;
		for (short i = 0; i < MyString.length(); i++) {
			if (islower(MyString[i])) {
				Counter++;
			}
		}
		return Counter;

	}


	void Task() {

		string MyString = ReadString("Please Enter Your String?\n");

		cout << "\nString Length = " << MyString.length();
		cout << "\nCapital Letters Count = " << CountCapitalLetters(MyString);
		cout << "\nSmall Letters Count = " << CountSmallLetters(MyString) << endl;

		cout << "\n\nUsing another method\n";
		cout << "\nString Length = " << CountLetters(MyString);
		cout << "\nCapital Letters Count = " << CountLetters(MyString,enWhatToCount::CapitalLetters);
		cout << "\nSmall Letters Count = " << CountLetters(MyString,enWhatToCount::SmallLetters) << endl;


	}


}
