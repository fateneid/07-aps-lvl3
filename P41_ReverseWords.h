#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace P41_ReverseWords {

	string ReadString(string Message) {
		string MyString;
		cout << Message;
		getline(cin, MyString);
		return MyString;
	}

	vector<string> SplitString(string MyString, string split) {

		string sWord;
		short pos = 0;
		vector <string> vSplitString;

		while ((pos = MyString.find(split)) != string::npos) {

			sWord = MyString.substr(0, pos);

			if (sWord != "") {
				vSplitString.push_back(sWord);
			}

			MyString.erase(0, pos + split.length());
		}

		if (MyString != "") {
			vSplitString.push_back(MyString);
		}

		return vSplitString;

	}

	string ReversedWords(string MyString) {

		vector <string> vString = SplitString(MyString, " ");
		string S = "";
		// declare iterator
		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin()) {
			--iter;
			S += *iter + " ";
		}

		return S.substr(0, S.length() - 1);

	}


	void Task() {

		string MyString = ReadString("Please Enter Your String?\n");

		cout << "\nString after reversing words:\n";
		cout << ReversedWords(MyString) << endl;
		


	}


}
