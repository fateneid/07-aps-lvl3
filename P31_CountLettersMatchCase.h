#pragma once

#include <iostream>
#include <string> 
using namespace std;

namespace P31_CountLettersMatchCase {

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

	char InvertCharcterCase(char MyChar) {
		return isupper(MyChar) ? tolower(MyChar) : toupper(MyChar);
	}

	short CountLettersMatchCase(string MyString, char Letter, bool MatchCase = 1) {
		short Counter = 0;

		for (short i = 0; i < MyString[i]; i++) {
			if (MatchCase) {
				if (MyString[i] == Letter) {
					Counter++;
				}
			}
			else {

				if (MyString[i] == Letter || MyString[i] == InvertCharcterCase(Letter)) {
					Counter++;
				}
			}
		}
		return Counter;
	}

	void Task() {

		string MyString = ReadString("Please Enter Your String?\n");

		char Letter = ReadCharcter("\nPlease Enter a Charcter?\n");

		cout << "\nLetter '" << Letter << "' Count = " << CountLettersMatchCase(MyString, Letter);
		cout << "\nLetter '" << Letter << "' Or '" << InvertCharcterCase(Letter) << "' Count = " << CountLettersMatchCase(MyString, Letter, 0) << endl;



	}

}
