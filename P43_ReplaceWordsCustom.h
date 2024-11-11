#pragma once

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

namespace P43_ReplaceWordsCustom {

	string ReadString(string Message) {
		string MyString;
		cout << Message;
		getline(cin, MyString);
		return MyString;
	}

	string ReplaceWords(string MyString, string ToReplace, string ReplaceTo) {
		
		short pos = MyString.find(ToReplace);

		while (pos != string::npos)
		{

			MyString.erase(pos, ToReplace.length());
			MyString.insert(pos, ReplaceTo);

			pos = MyString.find(ToReplace);

		}
		
		return MyString;

	}

	string InvertFirstLetter(string Word) {
		Word[0] = isupper(Word[0]) ? tolower(Word[0]) : toupper(Word[0]);
		return Word;
	}

	string ReplaceWordsDontMatchCase(string MyString, string ToReplace, string ReplaceTo, bool MatchCase = 1) {

		string S = ReplaceWords(MyString, ToReplace, ReplaceTo);

		if (MatchCase) {

			return S;
		}
		else {

			S = ReplaceWords(S, InvertFirstLetter(ToReplace), ReplaceTo);
			return S;

		}

	}

	void Task() {

		//string MyString = ReadString("Please Enter Your String?\n");
		string MyString = "Egypt egypt eGYPT egypt Egypt EgyPt.";

		cout << "Original String:\n";
		cout << MyString << endl;
		cout << "\nReplace with match case:\n";
		cout << ReplaceWords(MyString, "Egypt", "China") << endl;
		cout << "\nReplace with dont match case:\n";
		cout << ReplaceWordsDontMatchCase(MyString, "Egypt", "China", false) << endl;
	}


}
