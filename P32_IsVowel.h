#pragma once

#include <iostream>
#include <string> 
#include <cctype>
using namespace std;

namespace P32_IsVowel {

	char ReadCharcter(string Message) {
		char MyChar;
		cout << Message;
		cin >> MyChar;
		return MyChar;
	}

	bool IsVowel(char MyChar) {
		char arrVowelChar[5] = { 'a','e','i','o','u' };
		for (short i = 0; i < 5; i++) {
			if (arrVowelChar[i] == tolower(MyChar)) {
				return true;
			}
		}
		return false;
	}

	bool IsVowelAnotherSol(char MyChar) {
		MyChar = tolower(MyChar);
		return((MyChar == 'a' || MyChar == 'e' || MyChar == 'i' || MyChar == 'o' || MyChar == 'u'));
	}

	void Task() {

		char MyChar = ReadCharcter("Please Enter a Charcter?\n");

		if (IsVowelAnotherSol(MyChar)) {
			cout << "\nYES Letter '" << MyChar << "' is a vowel" << endl;
		}
		else {
			cout << "\nNO Letter '" << MyChar << "' is NOT a vowel" << endl;
		}


	}

}





